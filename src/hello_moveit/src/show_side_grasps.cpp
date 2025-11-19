#include <memory>
#include <thread>
#include <chrono>
#include <optional>
#include <map>
#include <sstream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <Eigen/Geometry>
#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <tf2_ros/buffer.h>
#include <tf2_ros/transform_listener.h>
#include <moveit_msgs/msg/grasp.hpp>
#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit_visual_tools/moveit_visual_tools.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit_msgs/msg/collision_object.hpp>
#include <shape_msgs/msg/solid_primitive.hpp>
#include <gazebo_msgs/srv/get_entity_state.hpp>

using namespace std::chrono_literals;

class ShowSideGraspsNode : public rclcpp::Node {
public:
  explicit ShowSideGraspsNode(const rclcpp::NodeOptions & options = rclcpp::NodeOptions()) : rclcpp::Node("show_side_grasps", options),
    tf_buffer_(this->get_clock()),
    tf_listener_(tf_buffer_) {
    // parameters
    group_ = declare_parameter<std::string>("group", "arm");
    object_ = declare_parameter<std::string>("object", "green_cube_3");
    ref_gz_ = declare_parameter<std::string>("reference_frame", "tiago::base_footprint");
    rviz_frame_ = declare_parameter<std::string>("rviz_frame", "base_footprint");
    
    // Grasp parameters (T_OF)
    of_px_ = declare_parameter<double>("of_px", 0.005071250542391959);
    of_py_ = declare_parameter<double>("of_py", -0.001078510009209965);
    of_pz_ = declare_parameter<double>("of_pz", 0.232017062226551);
    of_qx_ = declare_parameter<double>("of_qx", 0.997776211667235);
    of_qy_ = declare_parameter<double>("of_qy", -0.06661632963077202);
    of_qz_ = declare_parameter<double>("of_qz", -0.0019340518557168878);
    of_qw_ = declare_parameter<double>("of_qw", 0.0010749422891682054);
    
    approach_distance_ = declare_parameter<double>("approach_distance", 0.10);
    gripper_group_ = declare_parameter<std::string>("gripper_group", "gripper");

    f_link_ = declare_parameter<std::string>("f_link", "wrist_ft_link");
  }

  void run() {
    moveit::planning_interface::MoveGroupInterface arm(shared_from_this(), group_);
    const std::string e_link = arm.getEndEffectorLink();
    
    moveit_visual_tools::MoveItVisualTools mvt(shared_from_this(), rviz_frame_,
                                               rviz_visual_tools::RVIZ_MARKER_TOPIC,
                                               arm.getRobotModel());
    mvt.deleteAllMarkers();
    mvt.loadRemoteControl();

    // Get object pose
    using GetEntityState = gazebo_msgs::srv::GetEntityState;
    auto client = this->create_client<GetEntityState>("/get_entity_state");
    while (!client->wait_for_service(1s)) {
      if (!rclcpp::ok()) return;
    }
    
    auto call_get_pose = [&](const std::string & name)->std::optional<geometry_msgs::msg::Pose> {
      auto req = std::make_shared<GetEntityState::Request>();
      req->name = name;
      req->reference_frame = ref_gz_;
      auto fut = client->async_send_request(req);
      if (fut.wait_for(3s) == std::future_status::ready) {
        auto r = fut.get();
        if (r->success) return r->state.pose;
      }
      if (name.rfind("::link") == std::string::npos) {
        req->name = name + "::link";
        auto fut2 = client->async_send_request(req);
        if (fut2.wait_for(2s) == std::future_status::ready) {
          auto r2 = fut2.get();
          if (r2->success) return r2->state.pose;
        }
      }
      return std::nullopt;
    };

    auto p_obj = call_get_pose(object_);
    if (!p_obj) {
        RCLCPP_ERROR(get_logger(), "Could not get object pose for %s", object_.c_str());
        return;
    }
    RCLCPP_INFO(get_logger(), "Object '%s' pose found.", object_.c_str());

    Eigen::Isometry3d T_BO = Eigen::Isometry3d::Identity();
    T_BO.translation() = Eigen::Vector3d(p_obj->position.x, p_obj->position.y, p_obj->position.z);
    T_BO.linear() = quat_to_rot(p_obj->orientation.x, p_obj->orientation.y, p_obj->orientation.z, p_obj->orientation.w);

    // Base grasp T_OF
    Eigen::Isometry3d T_OF = Eigen::Isometry3d::Identity();
    T_OF.translation() = Eigen::Vector3d(of_px_, of_py_, of_pz_);
    T_OF.linear() = quat_to_rot(of_qx_, of_qy_, of_qz_, of_qw_);

    // T_FE
    rclcpp::sleep_for(300ms);
    Eigen::Isometry3d T_FE = Eigen::Isometry3d::Identity();
    try {
      auto tf = tf_buffer_.lookupTransform(f_link_, e_link, tf2::TimePointZero, 2s);
      T_FE.translation() = Eigen::Vector3d(tf.transform.translation.x, tf.transform.translation.y, tf.transform.translation.z);
      T_FE.linear() = quat_to_rot(tf.transform.rotation.x, tf.transform.rotation.y, tf.transform.rotation.z, tf.transform.rotation.w);
    } catch (...) {
      T_FE.translation() = Eigen::Vector3d(0.008, 0.0, 0.0);
      T_FE.linear() = quat_to_rot(0.5, 0.5, 0.5, 0.5);
    }

    mvt.publishAxis(T_BO, 0.12);
    mvt.publishText(T_BO, "O", rviz_visual_tools::GREEN, rviz_visual_tools::LARGE, false);

    const moveit::core::JointModelGroup* gripper_jmg = arm.getRobotModel()->getJointModelGroup(gripper_group_);

    auto eigToPose = [&](const Eigen::Isometry3d & T) {
      geometry_msgs::msg::Pose p;
      p.position.x = T.translation().x();
      p.position.y = T.translation().y();
      p.position.z = T.translation().z();
      Eigen::Quaterniond q(T.rotation()); q.normalize();
      p.orientation.x = q.x(); p.orientation.y = q.y(); p.orientation.z = q.z(); p.orientation.w = q.w();
      return p;
    };

    // Generate 12 grasps
    // 4 rotations around Z (0, 90, 180, 270)
    // For each Z rotation, 3 rotations around Y (-30, 0, +30)
    RCLCPP_INFO(get_logger(), "Generating 12 grasps (4 around Z * 3 around Y)...");
    
    int grasp_idx = 0;
    for (int i_z = 0; i_z < 4; ++i_z) {
        double angle_z_deg = i_z * 90.0;
        double angle_z_rad = angle_z_deg * M_PI / 180.0;
        
        for (int i_y = -1; i_y <= 1; ++i_y) {
            double angle_y_deg = i_y * 30.0;
            double angle_y_rad = angle_y_deg * M_PI / 180.0;

            mvt.deleteAllMarkers();

            // Rotation around Z
            Eigen::Isometry3d R_z = Eigen::Isometry3d::Identity();
            R_z.linear() = Eigen::AngleAxisd(angle_z_rad, Eigen::Vector3d::UnitZ()).toRotationMatrix();

            // Rotation around Y
            Eigen::Isometry3d R_y = Eigen::Isometry3d::Identity();
            R_y.linear() = Eigen::AngleAxisd(angle_y_rad, Eigen::Vector3d::UnitY()).toRotationMatrix();

            // Combined rotation: First rotate around Y (tilt), then around Z (orientation)
            // Or depending on the frame definition. Usually we want to tilt relative to the current approach, then rotate around the object axis?
            // The requirement says: "for each rotation around RZ by 90 degrees, additional two grasps tilted by +- 30 degrees in RY".
            // Assuming we apply these rotations to the base grasp T_OF.
            // Let's assume we rotate T_OF by R_z then R_y or R_y then R_z.
            // If we rotate around Z first, we orient the gripper. Then we tilt it around Y (local or global?).
            // Usually "tilt" means changing the approach angle relative to the face normal.
            // Let's try: T_OF_new = T_OF * R_z * R_y
            
            Eigen::Isometry3d T_OF_new = T_OF * R_z * R_y;

            // Calculate T_BE (Grasp Pose)
            Eigen::Isometry3d T_BE = T_BO * T_OF_new * T_FE;

            // Calculate T_BE_pre (Pre-grasp Pose)
            Eigen::Isometry3d T_E_pre = Eigen::Isometry3d::Identity();
            T_E_pre.translation() = Eigen::Vector3d(-approach_distance_, 0.0, 0.0);
            Eigen::Isometry3d T_BE_pre = T_BE * T_E_pre;

            // 1) Model chwytaka (Gripper model)
            moveit_msgs::msg::Grasp grasp;
            grasp.grasp_pose.header.frame_id = rviz_frame_;
            grasp.grasp_pose.pose = eigToPose(T_BE);
            mvt.publishGrasps({grasp}, gripper_jmg);

            // 2) Układ związany z chwytakiem – dla pozycji chwytu
            mvt.publishAxis(T_BE, 0.1);
            mvt.publishText(T_BE, "Grasp " + std::to_string(grasp_idx), rviz_visual_tools::WHITE, rviz_visual_tools::XLARGE);

            // 3) Układ związany z chwytakiem – dla pozycji przed chwytem
            mvt.publishAxis(T_BE_pre, 0.1);
            mvt.publishText(T_BE_pre, "Pre-grasp", rviz_visual_tools::GREY, rviz_visual_tools::LARGE);

            // 4) Układ związany z obiektem
            mvt.publishAxis(T_BO, 0.12);
            mvt.publishText(T_BO, "Object", rviz_visual_tools::GREEN, rviz_visual_tools::LARGE);
            
            // Log rotation
            RCLCPP_INFO(get_logger(), "Grasp %d: Rot Z=%.0f deg, Rot Y=%.0f deg", 
                grasp_idx, angle_z_deg, angle_y_deg);

            mvt.trigger();

            if (!mvt.prompt("Press 'Next' for next grasp, or 'Break' to stop")) {
                goto end_loop;
            }
            grasp_idx++;
        }
    }
    end_loop:
    
    RCLCPP_INFO(get_logger(), "Finished showing grasps.");
  }

private:
  static Eigen::Matrix3d quat_to_rot(double x, double y, double z, double w) {
    Eigen::Quaterniond q(w, x, y, z);
    return q.normalized().toRotationMatrix();
  }
  
  std::string group_, object_, ref_gz_, rviz_frame_, f_link_, gripper_group_;
  double of_px_, of_py_, of_pz_, of_qx_, of_qy_, of_qz_, of_qw_;
  double approach_distance_;
  
  tf2_ros::Buffer tf_buffer_;
  tf2_ros::TransformListener tf_listener_;
};

int main(int argc, char * argv[]) {
  rclcpp::init(argc, argv);
  
  // Force use_sim_time to true since this node depends on Gazebo
  rclcpp::NodeOptions options;
  options.parameter_overrides({
    {"use_sim_time", true}
  });
  
  auto node = std::make_shared<ShowSideGraspsNode>(options);
  rclcpp::executors::SingleThreadedExecutor exec;
  exec.add_node(node);
  std::thread spinner([&](){ exec.spin(); });
  node->run();
  rclcpp::shutdown();
  spinner.join();
  return 0;
}
