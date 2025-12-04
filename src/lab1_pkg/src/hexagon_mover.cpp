#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include <chrono>

using namespace std::chrono_literals;

class HexagonMover : public rclcpp::Node {
public:
    HexagonMover() : Node("hexagon_mover"), state_(0), side_count_(0) {
        pub_ = this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);

        sub_ = this->create_subscription<nav_msgs::msg::Odometry>(
            "/mobile_base_controller/odom", 10,
            std::bind(&HexagonMover::odom_cb, this, std::placeholders::_1));

        timer_ = this->create_wall_timer(
            100ms, std::bind(&HexagonMover::control_loop, this));

        lin_vel_ = 0.4;
        ang_vel_ = 0.4;

        // move
        move_time_ = 1.0 / lin_vel_;

        // turn
        turn_time_ = ((M_PI / 3.0) / ang_vel_) * 1.6925; // fix

        first_ = true;
        RCLCPP_INFO(this->get_logger(), "Start");
    }

private:
    void odom_cb(const nav_msgs::msg::Odometry::SharedPtr msg) {
        auto pos = msg->pose.pose.position;
        RCLCPP_INFO_THROTTLE(this->get_logger(), *this->get_clock(), 1000,
            "Pos: x=%.2f, y=%.2f", pos.x, pos.y);
    }

    void control_loop() {
        auto now = this->now();

        if (first_) {
            start_ = now;
            first_ = false;
        }

        double dt = (now - start_).seconds();
        geometry_msgs::msg::Twist cmd;

        if (side_count_ >= 7) {
            cmd.linear.x = 0.0;
            cmd.angular.z = 0.0;
            pub_->publish(cmd);
            return;
        }

        if (state_ == 0) { // move
            if (dt < move_time_) {
                cmd.linear.x = lin_vel_;
                cmd.angular.z = 0.0;
            } else {
                state_ = 1;
                start_ = now;
                cmd.linear.x = 0.0;
                cmd.angular.z = 0.0;
            }
        } else if (state_ == 1) { // turn
            if (dt < turn_time_) {
                cmd.linear.x = 0.0;
                cmd.angular.z = ang_vel_;
            } else {
                state_ = 0;
                start_ = now;
                side_count_++;
                cmd.linear.x = 0.0;
                cmd.angular.z = 0.0;
            }
        }

        pub_->publish(cmd);
    }

    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr pub_;
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr sub_;
    rclcpp::TimerBase::SharedPtr timer_;

    int state_;
    int side_count_;
    rclcpp::Time start_;
    bool first_;

    double lin_vel_;
    double ang_vel_;
    double move_time_;
    double turn_time_;
};

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<HexagonMover>());
    rclcpp::shutdown();
    return 0;
}
