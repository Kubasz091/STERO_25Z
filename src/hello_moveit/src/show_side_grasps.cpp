#include <memory>
#include <thread>
#include <chrono>
#include <optional>
#include <cmath>
#include <mutex>
#include <atomic>
#include <Eigen/Geometry>
#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <tf2_ros/buffer.h>
#include <tf2_ros/transform_listener.h>
#include <tf2_eigen/tf2_eigen.hpp>
#include <moveit_msgs/msg/grasp.hpp>
#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit_visual_tools/moveit_visual_tools.h>
#include <gazebo_msgs/srv/get_entity_state.hpp>

using namespace std::chrono_literals;

struct GraspVizData {
    bool initialized = false;
    bool needs_update = false;

    int id = 0;
    Eigen::Isometry3d T_BE;
    Eigen::Isometry3d T_BE_pre;
    Eigen::Isometry3d T_BO;
    moveit_msgs::msg::Grasp grasp_msg;
};

class ShowSideGraspsNode : public rclcpp::Node {
public:
  explicit ShowSideGraspsNode(const rclcpp::NodeOptions & options = rclcpp::NodeOptions())
    : rclcpp::Node("show_side_grasps", options),
      tf_buffer_(this->get_clock()),
      tf_listener_(tf_buffer_) {

    group_ = declare_parameter<std::string>("group", "arm");
    object_ = declare_parameter<std::string>("object", "green_cube_3");
    ref_gz_ = declare_parameter<std::string>("reference_frame", "tiago::base_footprint");
    rviz_frame_ = declare_parameter<std::string>("rviz_frame", "base_footprint");

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

    viz_rate_ = declare_parameter<double>("viz_rate", 20.0);

    client_ = this->create_client<gazebo_msgs::srv::GetEntityState>("/get_entity_state");
  }

  void run() {
    rclcpp::sleep_for(1s);

    moveit::planning_interface::MoveGroupInterface arm(shared_from_this(), group_);

    mvt_ = std::make_shared<moveit_visual_tools::MoveItVisualTools>(
        shared_from_this(), rviz_frame_, rviz_visual_tools::RVIZ_MARKER_TOPIC, arm.getRobotModel());

    mvt_->deleteAllMarkers();
    mvt_->loadRemoteControl();

    const moveit::core::JointModelGroup* gripper_jmg = arm.getRobotModel()->getJointModelGroup(gripper_group_);

    viz_running_ = true;
    std::thread viz_thread([this, gripper_jmg](){ this->visualization_loop(gripper_jmg); });

    while (!client_->wait_for_service(1s)) {
      if (!rclcpp::ok()) return;
    }

    auto get_pose = [&](const std::string & name) -> std::optional<geometry_msgs::msg::Pose> {
        auto req = std::make_shared<gazebo_msgs::srv::GetEntityState::Request>();
        req->name = name;
        req->reference_frame = ref_gz_;
        auto fut = client_->async_send_request(req);
        if (fut.wait_for(2s) == std::future_status::ready) {
            auto res = fut.get();
            if (res->success) return res->state.pose;
        }
        if (name.rfind("::link") == std::string::npos) {
            req->name = name + "::link";
            auto fut2 = client_->async_send_request(req);
            if (fut2.wait_for(2s) == std::future_status::ready) {
                auto res2 = fut2.get();
                if (res2->success) return res2->state.pose;
            }
        }
        return std::nullopt;
    };

    auto p_obj = get_pose(object_);
    if (!p_obj) return;

    Eigen::Isometry3d T_BO = Eigen::Isometry3d::Identity();
    T_BO.translation() = Eigen::Vector3d(p_obj->position.x, p_obj->position.y, p_obj->position.z);
    T_BO.linear() = quat_to_rot(p_obj->orientation.x, p_obj->orientation.y, p_obj->orientation.z, p_obj->orientation.w);

    Eigen::Isometry3d T_OF_base = Eigen::Isometry3d::Identity();
    T_OF_base.translation() = Eigen::Vector3d(of_px_, of_py_, of_pz_);
    T_OF_base.linear() = quat_to_rot(of_qx_, of_qy_, of_qz_, of_qw_);

    Eigen::Isometry3d T_FE = Eigen::Isometry3d::Identity();
    const std::string e_link = arm.getEndEffectorLink();
    try {
      auto tf = tf_buffer_.lookupTransform(f_link_, e_link, tf2::TimePointZero, 2s);
      T_FE.translation() = Eigen::Vector3d(tf.transform.translation.x, tf.transform.translation.y, tf.transform.translation.z);
      T_FE.linear() = quat_to_rot(tf.transform.rotation.x, tf.transform.rotation.y, tf.transform.rotation.z, tf.transform.rotation.w);
    } catch (...) {
      T_FE.translation() = Eigen::Vector3d(0.008, 0.0, 0.0);
      T_FE.linear() = quat_to_rot(0.5, 0.5, 0.5, 0.5);
    }

    int grasp_idx = 0;
    for (int i_z = 0; i_z < 4; ++i_z) {
        double roll = i_z * (M_PI / 2.0);

        for (int i_y = 0; i_y < 3; ++i_y) {
            double pitch = i_y * (M_PI / 6.0);

            Eigen::Isometry3d T_O_Ogr = Eigen::Isometry3d::Identity();
            T_O_Ogr.linear() = (Eigen::AngleAxisd(roll, Eigen::Vector3d::UnitZ()) * Eigen::AngleAxisd(pitch, Eigen::Vector3d::UnitY())).toRotationMatrix();

            Eigen::Isometry3d T_BE = T_BO * T_O_Ogr * T_OF_base * T_FE;

            Eigen::Isometry3d T_E_pre = Eigen::Isometry3d::Identity();
            T_E_pre.translation() = Eigen::Vector3d(-approach_distance_, 0.0, 0.0);
            Eigen::Isometry3d T_BE_pre = T_BE * T_E_pre;

            {
                std::lock_guard<std::mutex> lock(data_mutex_);
                shared_data_.initialized = true;
                shared_data_.needs_update = true;

                shared_data_.id = grasp_idx + 1;
                shared_data_.T_BE = T_BE;
                shared_data_.T_BE_pre = T_BE_pre;
                shared_data_.T_BO = T_BO;

                shared_data_.grasp_msg.grasp_pose.header.frame_id = rviz_frame_;
                shared_data_.grasp_msg.grasp_pose.pose = tf2::toMsg(T_BE);
            }

            RCLCPP_INFO(get_logger(), "Grasp %d: Roll=%.0f, Pitch=%.0f", grasp_idx + 1, roll * 180.0/M_PI, pitch * 180.0/M_PI);

            if (!mvt_->prompt("Press 'Next'")) {
                viz_running_ = false;
                return;
            }
            grasp_idx++;
        }
    }
    viz_running_ = false;

    if (viz_thread.joinable()) {
        viz_thread.join();
    }

    mvt_.reset();

    RCLCPP_INFO(get_logger(), "Visualization thread joined. Exiting safely.");
  }

private:
  void visualization_loop(const moveit::core::JointModelGroup* jmg) {
      GraspVizData local_data;
      rclcpp::Rate rate(viz_rate_);

      while (rclcpp::ok() && viz_running_) {
          {
              std::lock_guard<std::mutex> lock(data_mutex_);
              if (shared_data_.needs_update) {
                  local_data = shared_data_;
                  shared_data_.needs_update = false;
              }
          }

          if (local_data.initialized) {
              mvt_->deleteAllMarkers();

              mvt_->publishGrasps({local_data.grasp_msg}, jmg);
              mvt_->publishAxisLabeled(local_data.T_BE, "Grasp" + std::to_string(local_data.id), rviz_visual_tools::MEDIUM);
              mvt_->publishAxisLabeled(local_data.T_BE_pre, "Pre", rviz_visual_tools::SMALL);
              mvt_->publishAxisLabeled(local_data.T_BO, "Object", rviz_visual_tools::MEDIUM);

              mvt_->trigger();
          }
          rate.sleep();
      }
  }

  static Eigen::Matrix3d quat_to_rot(double x, double y, double z, double w) {
    Eigen::Quaterniond q(w, x, y, z);
    return q.normalized().toRotationMatrix();
  }

  std::string group_, object_, ref_gz_, rviz_frame_, f_link_, gripper_group_;
  double of_px_, of_py_, of_pz_, of_qx_, of_qy_, of_qz_, of_qw_;
  double approach_distance_;
  double viz_rate_;

  tf2_ros::Buffer tf_buffer_;
  tf2_ros::TransformListener tf_listener_;
  rclcpp::Client<gazebo_msgs::srv::GetEntityState>::SharedPtr client_;

  std::shared_ptr<moveit_visual_tools::MoveItVisualTools> mvt_;

  std::mutex data_mutex_;
  GraspVizData shared_data_;
  std::atomic<bool> viz_running_{false};
};

int main(int argc, char * argv[]) {
  rclcpp::init(argc, argv);

  rclcpp::NodeOptions options;
  options.parameter_overrides({{"use_sim_time", true}});

  auto node = std::make_shared<ShowSideGraspsNode>(options);

  rclcpp::executors::MultiThreadedExecutor exec;
  exec.add_node(node);
  std::thread spinner([&](){ exec.spin(); });

  node->run();

  rclcpp::shutdown();
  spinner.join();
  return 0;
}