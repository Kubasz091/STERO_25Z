#include <memory>
#include <thread>
#include <chrono>
#include <rclcpp/rclcpp.hpp>
#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit_visual_tools/moveit_visual_tools.h>
#include <gazebo_msgs/srv/get_entity_state.hpp>
#include <Eigen/Geometry>
#include <tf2_ros/buffer.h>
#include <tf2_ros/transform_listener.h>

int main(int argc, char* argv[])
{
  using namespace std::chrono_literals;

  rclcpp::init(argc, argv);
  auto node = std::make_shared<rclcpp::Node>("one_grasp");
  auto logger = rclcpp::get_logger("one_grasp");

  // Spin executor (needed for service client and visual tools)
  rclcpp::executors::SingleThreadedExecutor executor;
  executor.add_node(node);
  auto spinner = std::thread([&executor]() { executor.spin(); });

  // Params
  const std::string group = node->declare_parameter<std::string>("group", "arm");
  const std::string object = node->declare_parameter<std::string>("object", "green_cube_3");
  const std::string ref_gz = node->declare_parameter<std::string>("reference_frame", "tiago::base_footprint");
  const std::string rviz_frame = node->declare_parameter<std::string>("rviz_frame", "base_footprint");

  const double of_px = node->declare_parameter<double>("of_px", 0.005071250542391959);
  const double of_py = node->declare_parameter<double>("of_py", -0.001078510009209965);
  const double of_pz = node->declare_parameter<double>("of_pz", 0.232017062226551);
  const double of_qx = node->declare_parameter<double>("of_qx", 0.997776211667235);
  const double of_qy = node->declare_parameter<double>("of_qy", -0.06661632963077202);
  const double of_qz = node->declare_parameter<double>("of_qz", -0.0019340518557168878);
  const double of_qw = node->declare_parameter<double>("of_qw", 0.0010749422891682054);

  // Pregrasp approach distance
  const double approach_distance = node->declare_parameter<double>("approach_distance", 0.10);

  const std::string f_link = node->declare_parameter<std::string>("f_link", "wrist_ft_link");

  moveit::planning_interface::MoveGroupInterface move_group_interface(node, group);
  const std::string e_link = move_group_interface.getEndEffectorLink();

  moveit_visual_tools::MoveItVisualTools mvt(node, rviz_frame,
                                             rviz_visual_tools::RVIZ_MARKER_TOPIC,
                                             move_group_interface.getRobotModel());
  mvt.deleteAllMarkers();
  mvt.loadRemoteControl();
//   mvt.trigger();

  // client
  using GetEntityState = gazebo_msgs::srv::GetEntityState;
  auto client = node->create_client<GetEntityState>("/get_entity_state");

  while (!client->wait_for_service(1s)) {
    if (!rclcpp::ok()) {
      RCLCPP_ERROR(logger, "Interrupted. Exiting.");
      rclcpp::shutdown();
      return 1;
    }
    RCLCPP_INFO(logger, "Service not available, waiting...");
  }

  auto call_get_state = [&](const std::string& name)->std::shared_ptr<GetEntityState::Response> {
    auto req = std::make_shared<GetEntityState::Request>();
    req->name = name;
    req->reference_frame = ref_gz;  // B
    auto fut = client->async_send_request(req);
    if (fut.wait_for(3s) == std::future_status::ready)
      return fut.get();
    return {};
  };

  // O in B (T_BO)
  auto resp = call_get_state(object);
  if (!resp || !resp->success) {
    RCLCPP_WARN(logger, "Call with '%s' failed, trying '%s::link'", object.c_str(), object.c_str());
    resp = call_get_state(object + "::link");
  }
  if (!resp || !resp->success) {
    RCLCPP_ERROR(logger, "Failed to get entity state for '%s'", object.c_str());
    rclcpp::shutdown();
    spinner.join();
    return 2;
  }

  const auto& p = resp->state.pose;
  RCLCPP_INFO(logger,
    "Object '%s' in '%s': pos [%.3f %.3f %.3f], quat [%.3f %.3f %.3f %.3f]",
    (resp->state.name.empty() ? (object + "::link") : resp->state.name).c_str(),
    ref_gz.c_str(),
    p.position.x, p.position.y, p.position.z,
    p.orientation.x, p.orientation.y, p.orientation.z, p.orientation.w);

  auto quat_to_rot = [](double x, double y, double z, double w){
    Eigen::Quaterniond q(w, x, y, z);
    return q.normalized().toRotationMatrix();
  };

  // T_BO
  Eigen::Isometry3d T_BO = Eigen::Isometry3d::Identity();
  T_BO.translation() = Eigen::Vector3d(p.position.x, p.position.y, p.position.z);
  T_BO.linear() = quat_to_rot(p.orientation.x, p.orientation.y, p.orientation.z, p.orientation.w);

  // T_OF (grasp offset measured)
  Eigen::Isometry3d T_OF = Eigen::Isometry3d::Identity();
  T_OF.translation() = Eigen::Vector3d(of_px, of_py, of_pz);
  T_OF.linear() = quat_to_rot(of_qx, of_qy, of_qz, of_qw);

  // T_FE from TF
  tf2_ros::Buffer tf_buffer(node->get_clock());
  tf2_ros::TransformListener tf_listener(tf_buffer);

  rclcpp::sleep_for(300ms);

  Eigen::Isometry3d T_FE = Eigen::Isometry3d::Identity();
  try {
    // Get E -> F
    auto tf = tf_buffer.lookupTransform(f_link, e_link, tf2::TimePointZero, 2s);
    const auto& tr = tf.transform.translation;
    const auto& rq = tf.transform.rotation;
    T_FE.translation() = Eigen::Vector3d(tr.x, tr.y, tr.z);
    T_FE.linear() = quat_to_rot(rq.x, rq.y, rq.z, rq.w);
  } catch (const std::exception& e) {
    RCLCPP_WARN(logger, "TF lookup (%s <- %s) failed, using defaults. Error: %s",
                f_link.c_str(), e_link.c_str(), e.what());

    T_FE.translation() = Eigen::Vector3d(0.008, 0.0, 0.0);
    T_FE.linear() = quat_to_rot(0.5, 0.5, 0.5, 0.5);
  }

  // T_BE = T_BO · T_OF · T_FE
  Eigen::Isometry3d T_BE = T_BO * T_OF * T_FE;

  // Pregrasp
  Eigen::Isometry3d T_E_pre = Eigen::Isometry3d::Identity();
  T_E_pre.translation() = Eigen::Vector3d(-approach_distance, 0.0, 0.0);
  Eigen::Isometry3d T_BE_pre = T_BE * T_E_pre;

  auto pose_to_string = [](const Eigen::Isometry3d& T){
    Eigen::Quaterniond q(T.rotation());
    std::ostringstream ss;
    ss.setf(std::ios::fixed); ss<<std::setprecision(3);
    ss<<"pos ["<<T.translation().x()<<" "<<T.translation().y()<<" "<<T.translation().z()<<"] "
      <<"quat ["<<q.x()<<" "<<q.y()<<" "<<q.z()<<" "<<q.w()<<"]";
    return ss.str();
  };

  RCLCPP_INFO(logger, "E_grasp in '%s': %s", rviz_frame.c_str(), pose_to_string(T_BE).c_str());
  RCLCPP_INFO(logger, "E_pregrasp (d=%.3fm) in '%s': %s", approach_distance, rviz_frame.c_str(),
              pose_to_string(T_BE_pre).c_str());

  // Visualize: object, E_grasp, E_pregrasp
  mvt.publishAxis(T_BO, 0.12);  // Object frame
  mvt.publishText(T_BO, "O(object)", rviz_visual_tools::GREEN, rviz_visual_tools::LARGE, false);

  mvt.publishAxis(T_BE, 0.12);  // Grasp target
  mvt.publishText(T_BE, "E_grasp", rviz_visual_tools::BLUE, rviz_visual_tools::LARGE, false);

  mvt.publishAxis(T_BE_pre, 0.12);  // Pregrasp
  mvt.publishText(T_BE_pre, "E_pregrasp", rviz_visual_tools::CYAN, rviz_visual_tools::LARGE, false);

  mvt.trigger();

  rclcpp::shutdown();
  spinner.join();
  return 0;
}