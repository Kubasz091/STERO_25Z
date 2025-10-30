#include <rclcpp/rclcpp.hpp>
#include <moveit/move_group_interface/move_group_interface.h>

int main(int argc, char** argv) {
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("print_frames");
  std::string group = node->declare_parameter<std::string>("group", "arm");
  moveit::planning_interface::MoveGroupInterface mgi(node, group);
  RCLCPP_INFO(node->get_logger(), "B (planning frame): %s", mgi.getPlanningFrame().c_str());
  RCLCPP_INFO(node->get_logger(), "E (end effector):  %s", mgi.getEndEffectorLink().c_str());
  rclcpp::shutdown();
  return 0;
}