#include <memory>
#include <thread>
#include <chrono>
#include <rclcpp/rclcpp.hpp>
#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit_visual_tools/moveit_visual_tools.h>
#include <gazebo_msgs/srv/get_entity_state.hpp>
#include <Eigen/Geometry>

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

  // MoveIt interfaces
  moveit::planning_interface::MoveGroupInterface move_group_interface(node, group);
  moveit_visual_tools::MoveItVisualTools mvt(node, rviz_frame,
                                             rviz_visual_tools::RVIZ_MARKER_TOPIC,
                                             move_group_interface.getRobotModel());
  mvt.deleteAllMarkers();
  mvt.loadRemoteControl();
//   mvt.trigger();

  // Create client
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

  // Helper: attempt call with name; if fails, try name::link
  auto call_get_state = [&](const std::string& name)->std::shared_ptr<GetEntityState::Response> {
    auto req = std::make_shared<GetEntityState::Request>();
    req->name = name;
    req->reference_frame = ref_gz;  // consistent with rviz_frame coordinates
    auto fut = client->async_send_request(req);
    if (fut.wait_for(3s) == std::future_status::ready)
      return fut.get();
    return {};
  };

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
    resp->state.name.c_str(), ref_gz.c_str(),
    p.position.x, p.position.y, p.position.z,
    p.orientation.x, p.orientation.y, p.orientation.z, p.orientation.w);

  // Convert pose to Eigen and visualize axis + label
  Eigen::Isometry3d T = Eigen::Isometry3d::Identity();
  T.translation() = Eigen::Vector3d(p.position.x, p.position.y, p.position.z);
  Eigen::Quaterniond q(p.orientation.w, p.orientation.x, p.orientation.y, p.orientation.z);
  T.linear() = q.normalized().toRotationMatrix();

  mvt.publishAxis(T, 0.12);  // axis length ~12 cm
  mvt.publishText(T, "green_cube_3", rviz_visual_tools::GREEN, rviz_visual_tools::SMALL);
  mvt.trigger();

  rclcpp::shutdown();
  spinner.join();
  return 0;
}