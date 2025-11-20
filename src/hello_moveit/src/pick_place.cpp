#include <memory>
#include <thread>
#include <chrono>
#include <optional>
#include <map>
#include <sstream>
#include <iomanip>
#include <Eigen/Geometry>
#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <tf2_ros/buffer.h>
#include <tf2_ros/transform_listener.h>
#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit_visual_tools/moveit_visual_tools.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit_msgs/msg/collision_object.hpp>
#include <shape_msgs/msg/solid_primitive.hpp>
#include <gazebo_msgs/srv/get_entity_state.hpp>

using namespace std::chrono_literals;

class PickPlace : public rclcpp::Node {
public:
  explicit PickPlace(const rclcpp::NodeOptions & options = rclcpp::NodeOptions()) : rclcpp::Node("pick_place", options),
    tf_buffer_(this->get_clock()),
    tf_listener_(tf_buffer_) {
    // parameters
    group_ = declare_parameter<std::string>("group", "arm");
    object_ = declare_parameter<std::string>("object", "green_cube_3");
    ref_gz_ = declare_parameter<std::string>("reference_frame", "tiago::base_footprint");
    rviz_frame_ = declare_parameter<std::string>("rviz_frame", "base_footprint");
    table_entity_ = declare_parameter<std::string>("table_entity", "table::link");
    table_size_x_ = declare_parameter<double>("table_size_x", 1.0);
    table_size_y_ = declare_parameter<double>("table_size_y", 1.0);
    table_size_z_ = declare_parameter<double>("table_size_z", 0.05);
    cube_size_ = declare_parameter<double>("cube_size", 0.05);
    above_table_clearance_ = declare_parameter<double>("above_table_clearance", 0.10);
    of_px_ = declare_parameter<double>("of_px", 0.005071250542391959);
    of_py_ = declare_parameter<double>("of_py", -0.001078510009209965);
    of_pz_ = declare_parameter<double>("of_pz", 0.232017062226551);
    of_qx_ = declare_parameter<double>("of_qx", 0.997776211667235);
    of_qy_ = declare_parameter<double>("of_qy", -0.06661632963077202);
    of_qz_ = declare_parameter<double>("of_qz", -0.0019340518557168878);
    of_qw_ = declare_parameter<double>("of_qw", 0.0010749422891682054);
    approach_distance_ = declare_parameter<double>("approach_distance", 0.10);
    f_link_ = declare_parameter<std::string>("f_link", "wrist_ft_link");
    gripper_group_ = declare_parameter<std::string>("gripper_group", "gripper");
    finger_left_joint_ = declare_parameter<std::string>("finger_left_joint", "gripper_left_finger_joint");
    finger_right_joint_ = declare_parameter<std::string>("finger_right_joint", "gripper_right_finger_joint");
    open_width_ = declare_parameter<double>("gripper_open", 0.044);
    close_width_ = declare_parameter<double>("gripper_close", 0.035);
    torso_joint_ = declare_parameter<std::string>("torso_joint", "torso_lift_joint");
    arm1_joint_ = declare_parameter<std::string>("arm1_joint", "arm_1_joint");
    torso_up_ = declare_parameter<double>("torso_up", 0.35);
    arm1_angle_ = declare_parameter<double>("arm1_angle", 1.5708);
    lift_height_ = declare_parameter<double>("lift_height", 0.05);
    max_reach_ = declare_parameter<double>("max_reach", 1.2);
    place_x_ = declare_parameter<std::vector<double>>("place_x", {0.6, 0.5, 0.5, 2.0});
    place_y_ = declare_parameter<std::vector<double>>("place_y", {0.0, 0.2, -0.2, 0.0});
    
    client_ = this->create_client<gazebo_msgs::srv::GetEntityState>("/get_entity_state");
  }

  void run() {
    moveit::planning_interface::MoveGroupInterface arm(shared_from_this(), group_);
    const std::string e_link = arm.getEndEffectorLink();
    arm.setEndEffectorLink(e_link);
    arm.setMaxVelocityScalingFactor(0.4);
    arm.setMaxAccelerationScalingFactor(0.4);

    moveit::planning_interface::MoveGroupInterface gripper(shared_from_this(), gripper_group_);
    gripper.setMaxVelocityScalingFactor(1.0);
    gripper.setMaxAccelerationScalingFactor(1.0);

    moveit_visual_tools::MoveItVisualTools mvt(shared_from_this(), rviz_frame_,
                                               rviz_visual_tools::RVIZ_MARKER_TOPIC,
                                               arm.getRobotModel());
    mvt.deleteAllMarkers();
    mvt.loadRemoteControl();

    // obstacles
    moveit::planning_interface::PlanningSceneInterface psi;
    auto eigToPose = [&](const Eigen::Isometry3d & T) {
      geometry_msgs::msg::Pose p;
      p.position.x = T.translation().x();
      p.position.y = T.translation().y();
      p.position.z = T.translation().z();
      Eigen::Quaterniond q(T.rotation()); q.normalize();
      p.orientation.x = q.x(); p.orientation.y = q.y(); p.orientation.z = q.z(); p.orientation.w = q.w();
      return p;
    };
    auto make_box = [&](const std::string & id, double sx, double sy, double sz, const Eigen::Isometry3d & T){
      moveit_msgs::msg::CollisionObject co;
      co.id = id; co.header.frame_id = rviz_frame_;
      shape_msgs::msg::SolidPrimitive box; box.type = shape_msgs::msg::SolidPrimitive::BOX; box.dimensions = {sx, sy, sz};
      co.primitives.push_back(box); co.primitive_poses.push_back(eigToPose(T));
      co.operation = moveit_msgs::msg::CollisionObject::ADD; return co;
    };
    Eigen::Isometry3d T_BT = Eigen::Isometry3d::Identity();
    if (auto p = get_entity_pose(table_entity_)) {
      T_BT.translation() = Eigen::Vector3d(p->position.x, p->position.y, p->position.z+0.5); // podniesienie os 25 cm
      Eigen::Quaterniond q(p->orientation.w, p->orientation.x, p->orientation.y, p->orientation.z);
      T_BT.linear() = q.normalized().toRotationMatrix();
    }
    
    // Initial object pose for collision object
    Eigen::Isometry3d T_BO_init = Eigen::Isometry3d::Identity();
    if (auto p_obj = get_entity_pose(object_)) {
        T_BO_init.translation() = Eigen::Vector3d(p_obj->position.x, p_obj->position.y, p_obj->position.z);
        T_BO_init.linear() = quat_to_rot(p_obj->orientation.x, p_obj->orientation.y, p_obj->orientation.z, p_obj->orientation.w);
    }

    std::vector<moveit_msgs::msg::CollisionObject> cos;
    cos.push_back(make_box("table_top", table_size_x_, table_size_y_, table_size_z_, T_BT));
    cos.push_back(make_box(object_, cube_size_, cube_size_, cube_size_, T_BO_init));
    psi.applyCollisionObjects(cos);
    rclcpp::sleep_for(300ms);

    // zad 12
    {
      std::map<std::string,double> j; j[torso_joint_] = torso_up_;
      (void)plan_exec_joints(arm, j, "Raise torso");
    }
    {
      std::map<std::string,double> j; j[arm1_joint_] = arm1_angle_;
      (void)plan_exec_joints(arm, j, "Rotate arm_1");
    }
    (void)set_gripper_width(gripper, open_width_, "Open gripper");

    // Loop through place coordinates
    size_t n_places = std::min(place_x_.size(), place_y_.size());
    for (size_t i = 0; i < n_places; ++i) {
      RCLCPP_INFO(get_logger(), "Starting pick and place sequence %zu/%zu", i + 1, n_places);
      bool ok = pick_and_place(arm, gripper, mvt, place_x_[i], place_y_[i]);
      if (!ok) {
        RCLCPP_ERROR(get_logger(), "Pick and place sequence %zu failed", i + 1);
        break;
      }
      rclcpp::sleep_for(1s); // Wait a bit between sequences
    }
    
    RCLCPP_INFO(get_logger(), "All sequences completed.");
  }


private:
  // helpers
  bool pick_and_place(moveit::planning_interface::MoveGroupInterface & arm,
                      moveit::planning_interface::MoveGroupInterface & gripper,
                      moveit_visual_tools::MoveItVisualTools & mvt,
                      double place_x,
                      double place_y) {
    std::string e_link = arm.getEndEffectorLink();
    bool ok = true;

    // Calculate poses
    auto p_obj = get_entity_pose(object_);
    if (!p_obj) {
        RCLCPP_ERROR(get_logger(), "Could not get pose for object %s", object_.c_str());
        return false;
    }
    RCLCPP_INFO(get_logger(), "Object '%s' in '%s': pos [%.3f %.3f %.3f]",
                object_.c_str(), ref_gz_.c_str(),
                p_obj->position.x, p_obj->position.y, p_obj->position.z);

    Eigen::Isometry3d T_BO = Eigen::Isometry3d::Identity();
    T_BO.translation() = Eigen::Vector3d(p_obj->position.x, p_obj->position.y, p_obj->position.z);
    T_BO.linear() = quat_to_rot(p_obj->orientation.x, p_obj->orientation.y, p_obj->orientation.z, p_obj->orientation.w);

    Eigen::Isometry3d T_OF = Eigen::Isometry3d::Identity();
    T_OF.translation() = Eigen::Vector3d(of_px_, of_py_, of_pz_);
    T_OF.linear() = quat_to_rot(of_qx_, of_qy_, of_qz_, of_qw_);

    Eigen::Isometry3d T_FE = Eigen::Isometry3d::Identity();
    try {
      auto tf = tf_buffer_.lookupTransform(f_link_, e_link, tf2::TimePointZero, 2s);
      T_FE.translation() = Eigen::Vector3d(tf.transform.translation.x, tf.transform.translation.y, tf.transform.translation.z);
      T_FE.linear() = quat_to_rot(tf.transform.rotation.x, tf.transform.rotation.y, tf.transform.rotation.z, tf.transform.rotation.w);
    } catch (...) {
      T_FE.translation() = Eigen::Vector3d(0.008, 0.0, 0.0);
      T_FE.linear() = quat_to_rot(0.5, 0.5, 0.5, 0.5);
    }

    Eigen::Isometry3d T_BE = T_BO * T_OF * T_FE;
    Eigen::Isometry3d T_E_pre = Eigen::Isometry3d::Identity();
    T_E_pre.translation() = Eigen::Vector3d(-approach_distance_, 0.0, 0.0);
    Eigen::Isometry3d T_BE_pre = T_BE * T_E_pre;

    // Visualize
    mvt.publishAxis(T_BO, 0.12);
    mvt.publishText(T_BO, "O(object)", rviz_visual_tools::GREEN, rviz_visual_tools::LARGE, false);
    mvt.publishAxis(T_BE, 0.12);
    mvt.publishText(T_BE, "E_grasp", rviz_visual_tools::BLUE, rviz_visual_tools::LARGE, false);
    mvt.publishAxis(T_BE_pre, 0.12);
    mvt.publishText(T_BE_pre, "E_pregrasp", rviz_visual_tools::CYAN, rviz_visual_tools::LARGE, false);
    mvt.trigger();

    // Check reach
    if (!check_reach(T_BO.translation().x(), T_BO.translation().y(), "Object")) return false;

    // Pick
    ok = ok && plan_exec_pose(arm, e_link, rviz_frame_, T_BE_pre, "Pregrasp");
    ok = ok && plan_exec_pose(arm, e_link, rviz_frame_, T_BE, "Grasp pose");
    ok = ok && set_gripper_width(gripper, close_width_, "Close gripper");
    if (ok) {
      arm.attachObject(object_, e_link, gripper.getLinkNames());
      RCLCPP_INFO(get_logger(), "Object attached");
    }
    rclcpp::sleep_for(300ms);
    Eigen::Isometry3d T_BE_lift = T_BE; T_BE_lift.translation().z() += lift_height_;
    ok = ok && plan_exec_pose(arm, e_link, rviz_frame_, T_BE_lift, "Lift");

    // Place
    if (!check_reach(place_x, place_y, "Place point")) return false;

    if (ok) {
      Eigen::Isometry3d T_B_place = Eigen::Isometry3d::Identity();
      T_B_place.translation() = Eigen::Vector3d(place_x, place_y, T_BE_lift.translation().z());
      T_B_place.linear() = T_BE.rotation();

      RCLCPP_INFO(get_logger(), "Placing at: [%.3f, %.3f, %.3f]", place_x, place_y, T_BE.translation().z());

      ok = plan_exec_pose(arm, e_link, rviz_frame_, T_B_place, "Move to place position");
      rclcpp::sleep_for(300ms);
      Eigen::Isometry3d T_B_place_lower = T_B_place;
      T_B_place_lower.translation().z() = T_BE.translation().z() + 0.01;

      RCLCPP_INFO(get_logger(), "Lowering to Z: %.3f (Grasp Z: %.3f)", T_B_place_lower.translation().z(), T_BE.translation().z());

      if (ok) {
        ok = plan_exec_pose(arm, e_link, rviz_frame_, T_B_place_lower, "Lower to place");
      }

      if (ok) {
        ok = set_gripper_width(gripper, open_width_, "Release object");
        rclcpp::sleep_for(300ms);
      }

      if (ok) {
        arm.detachObject(object_);
        RCLCPP_INFO(get_logger(), "Object detached");
      }

      if (ok) {
        Eigen::Isometry3d T_B_retreat = T_B_place; T_B_retreat.translation().z() = T_BE_pre.translation().z();
        ok = plan_exec_pose(arm, e_link, rviz_frame_, T_B_retreat, "Retreat from place");
      }
    }
    return ok;
  }

  bool check_reach(double x, double y, const char * label) {
    double d = std::hypot(x, y);
    if (d > max_reach_) {
      RCLCPP_ERROR(get_logger(), "%s too far (%.2f > %.2f)", label, d, max_reach_);
      return false;
    }
    return true;
  }

  static Eigen::Matrix3d quat_to_rot(double x, double y, double z, double w) {
    Eigen::Quaterniond q(w, x, y, z);
    return q.normalized().toRotationMatrix();
  }

  bool plan_exec_pose(moveit::planning_interface::MoveGroupInterface & mgi,
                      const std::string & ee_link,
                      const std::string & frame,
                      const Eigen::Isometry3d & T,
                      const char * label) {
    geometry_msgs::msg::PoseStamped ps; ps.header.frame_id = frame;
    Eigen::Quaterniond q(T.rotation()); q.normalize();
    ps.pose.position.x = T.translation().x();
    ps.pose.position.y = T.translation().y();
    ps.pose.position.z = T.translation().z();
    ps.pose.orientation.x = q.x(); ps.pose.orientation.y = q.y(); ps.pose.orientation.z = q.z(); ps.pose.orientation.w = q.w();
    mgi.setPoseTarget(ps, ee_link);
    mgi.setStartStateToCurrentState();
    moveit::planning_interface::MoveGroupInterface::Plan plan;
    bool ok = (mgi.plan(plan) == moveit::core::MoveItErrorCode::SUCCESS);
    if (ok) ok = (mgi.execute(plan) == moveit::core::MoveItErrorCode::SUCCESS);
    RCLCPP_INFO(get_logger(), "%s: %s", label, ok ? "OK" : "FAIL");
    mgi.clearPoseTargets();
    return ok;
  }

  bool plan_exec_joints(moveit::planning_interface::MoveGroupInterface & mgi,
                        const std::map<std::string,double> & joints,
                        const char * label) {
    mgi.setJointValueTarget(joints);
    mgi.setStartStateToCurrentState();
    moveit::planning_interface::MoveGroupInterface::Plan plan;
    bool ok = (mgi.plan(plan) == moveit::core::MoveItErrorCode::SUCCESS);
    if (ok) ok = (mgi.execute(plan) == moveit::core::MoveItErrorCode::SUCCESS);
    RCLCPP_INFO(get_logger(), "%s: %s", label, ok ? "OK" : "FAIL");
    return ok;
  }

  bool set_gripper_width(moveit::planning_interface::MoveGroupInterface & gr,
                         double w,
                         const char * label) {
    std::map<std::string,double> j;
    j[finger_left_joint_] = w;
    j[finger_right_joint_] = w;
    return plan_exec_joints(gr, j, label);
  }

  // parameters
  std::string group_, object_, ref_gz_, rviz_frame_, table_entity_, f_link_, gripper_group_;
  double table_size_x_{}, table_size_y_{}, table_size_z_{}, cube_size_{}, above_table_clearance_{};
  double of_px_{}, of_py_{}, of_pz_{}, of_qx_{}, of_qy_{}, of_qz_{}, of_qw_{};
  double approach_distance_{}, max_reach_{}, open_width_{}, close_width_{}, torso_up_{}, arm1_angle_{}, lift_height_{};
  std::vector<double> place_x_, place_y_;
  std::string finger_left_joint_, finger_right_joint_, torso_joint_, arm1_joint_;

  // tf
  tf2_ros::Buffer tf_buffer_;
  tf2_ros::TransformListener tf_listener_;
  rclcpp::Client<gazebo_msgs::srv::GetEntityState>::SharedPtr client_;

  std::optional<geometry_msgs::msg::Pose> get_entity_pose(const std::string & name) {
    auto req = std::make_shared<gazebo_msgs::srv::GetEntityState::Request>();
    req->name = name;
    req->reference_frame = ref_gz_;
    while (!client_->wait_for_service(1s)) {
      if (!rclcpp::ok()) return std::nullopt;
      RCLCPP_INFO(get_logger(), "Waiting for service %s...", client_->get_service_name());
    }
    auto fut = client_->async_send_request(req);
    if (fut.wait_for(3s) == std::future_status::ready) {
      auto r = fut.get();
      if (r->success) return r->state.pose;
    }
    if (name.rfind("::link") == std::string::npos) {
      req->name = name + "::link";
      auto fut2 = client_->async_send_request(req);
      if (fut2.wait_for(2s) == std::future_status::ready) {
        auto r2 = fut2.get();
        if (r2->success) return r2->state.pose;
      }
    }
    return std::nullopt;
  }
};

int main(int argc, char * argv[]) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<PickPlace>();
  rclcpp::executors::SingleThreadedExecutor exec;
  exec.add_node(node);
  std::thread spinner([&](){ exec.spin(); });
  node->run();
  rclcpp::shutdown();
  spinner.join();
  return 0;
}