#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp" // Added
#include "nav_msgs/msg/odometry.hpp"
#include "nav_msgs/msg/path.hpp" // Added
#include "tf2/LinearMath/Quaternion.h"
#include "tf2/LinearMath/Matrix3x3.h"
#include <chrono>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
#include <string>

using namespace std::chrono_literals;

struct LogData {
    double timestamp;
    double pos_err_sq;
    double orient_err_sq;
};

class SquareMover : public rclcpp::Node {
public:
    SquareMover() : Node("square_mover"), state_(IDLE), current_lap_(0), current_side_(0) {
        // Parameters
        this->declare_parameter("square_len", 1.0);
        this->declare_parameter("laps", 1);
        this->declare_parameter("direction", "ccw"); // cw or ccw
        this->declare_parameter("linear_brake_dist", 0.2); // Increased default
        this->declare_parameter("angular_brake_dist", 0.5); // Increased default
        // Inertia factor (simple heuristic multiplier for stopping distance or time)
        // User asked for a parameter to predict inertia. 
        // We will use it to scale the braking distance.
        this->declare_parameter("inertia_factor", 1.0); 

        square_len_ = this->get_parameter("square_len").as_double();
        total_laps_ = this->get_parameter("laps").as_int();
        direction_str_ = this->get_parameter("direction").as_string();
        linear_brake_dist_ = this->get_parameter("linear_brake_dist").as_double();
        angular_brake_dist_ = this->get_parameter("angular_brake_dist").as_double();
        inertia_factor_ = this->get_parameter("inertia_factor").as_double();

        if (direction_str_ == "cw") {
            turn_direction_ = -1.0;
        } else {
            turn_direction_ = 1.0;
        }

        // Apply inertia factor to brake distances
        linear_brake_dist_ *= inertia_factor_;
        angular_brake_dist_ *= inertia_factor_;

        RCLCPP_INFO(this->get_logger(), "Params: len=%.2f, laps=%d, dir=%s, inertia=%.2f", 
            square_len_, total_laps_, direction_str_.c_str(), inertia_factor_);


        // Publishers and Subscribers
        pub_cmd_ = this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);
        pub_path_ = this->create_publisher<nav_msgs::msg::Path>("/path", 10); // Added
        
        sub_odom_ = this->create_subscription<nav_msgs::msg::Odometry>(
            "/mobile_base_controller/odom", 10,
            std::bind(&SquareMover::odom_cb, this, std::placeholders::_1));

        sub_gt_ = this->create_subscription<nav_msgs::msg::Odometry>(
            "/ground_truth_odom", 10,
            std::bind(&SquareMover::gt_cb, this, std::placeholders::_1));

        timer_ = this->create_wall_timer(
            50ms, std::bind(&SquareMover::control_loop, this));

        // Initial state
        first_odom_ = true;
        target_yaw_ = 0.0;
        last_log_time_ = 0.0; // Initialize last log time
        logging_counter_ = 0.0;
    }

private:
    enum State {
        IDLE,
        INIT_MOVE,
        MOVING,
        INIT_TURN,
        TURNING,
        FINISHED
    };

    void odom_cb(const nav_msgs::msg::Odometry::SharedPtr msg) {
        current_pose_ = *msg;
        
        // Update Path
        geometry_msgs::msg::PoseStamped pose_stamped;
        pose_stamped.header = msg->header;
        pose_stamped.pose = msg->pose.pose;
        path_.header = msg->header; // Update frame info
        path_.poses.push_back(pose_stamped);
        pub_path_->publish(path_);

        if (first_odom_) {
             // Store initial pose as reference for relative movement if needed
             // But simpler to just track current position relative to start of side
             start_pose_ = current_pose_;
             first_odom_ = false;
             state_ = INIT_MOVE; // Start moving once we have odometry
        }
    }

    void gt_cb(const nav_msgs::msg::Odometry::SharedPtr msg) {
        gt_pose_ = *msg;
        
        // Log data if running, every 10 seconds
        if (state_ != FINISHED && state_ != IDLE) {
            double now_sec = this->now().seconds();
            if (now_sec - last_log_time_ >= 10.0) {
                LogData data;
                data.timestamp = logging_counter_;
                logging_counter_ += 10.0;
                
                double tx = current_pose_.pose.pose.position.x;
                double ty = current_pose_.pose.pose.position.y;
                double ttheta = get_yaw(current_pose_.pose.pose.orientation);

                double gx = gt_pose_.pose.pose.position.x;
                double gy = gt_pose_.pose.pose.position.y;
                double gtheta = get_yaw(gt_pose_.pose.pose.orientation);

                data.pos_err_sq = std::pow(tx - gx, 2) + std::pow(ty - gy, 2);
                
                double orient_err = normalize_angle(ttheta - gtheta);
                data.orient_err_sq = std::pow(orient_err, 2);

                data_log_.push_back(data);
                last_log_time_ = now_sec;
            }
        }
    }

    double get_yaw(const geometry_msgs::msg::Quaternion &q) {
        tf2::Quaternion tf_q(q.x, q.y, q.z, q.w);
        tf2::Matrix3x3 m(tf_q);
        double roll, pitch, yaw;
        m.getRPY(roll, pitch, yaw);
        return yaw;
    }

    double normalize_angle(double angle) {
        while (angle > M_PI) angle -= 2.0 * M_PI;
        while (angle < -M_PI) angle += 2.0 * M_PI;
        return angle;
    }

    void control_loop() {
        if (first_odom_ || state_ == IDLE || state_ == FINISHED) {
            geometry_msgs::msg::Twist stop_cmd;
            pub_cmd_->publish(stop_cmd);
             if (state_ == FINISHED && !report_generated_) {
                generate_report();
                report_generated_ = true;
                rclcpp::shutdown();
            }
            return;
        }

        geometry_msgs::msg::Twist cmd;
        double current_x = current_pose_.pose.pose.position.x;
        double current_y = current_pose_.pose.pose.position.y;
        double current_yaw = get_yaw(current_pose_.pose.pose.orientation);

        // Determine Start X/Y of the current segment for distance calculation
        static double segment_start_x = 0;
        static double segment_start_y = 0;
        static double segment_start_yaw = 0;

        switch (state_) {
            case INIT_MOVE: {
                RCLCPP_INFO(this->get_logger(), "State: MOVING (Side %d, Lap %d)", current_side_, current_lap_);
                segment_start_x = current_x;
                segment_start_y = current_y;
                state_ = MOVING;
                break;
            }
            case MOVING: {
                double dx = current_x - segment_start_x;
                double dy = current_y - segment_start_y;
                double dist_moved = std::sqrt(dx*dx + dy*dy);
                double dist_remaining = square_len_ - dist_moved;

                RCLCPP_INFO_THROTTLE(this->get_logger(), *this->get_clock(), 1000, 
                    "MOVING: rem=%.3f, brake_at=%.3f", dist_remaining, linear_brake_dist_);

                if (dist_remaining <= linear_brake_dist_) {
                     // Decelerate or stop
                     // Simple predictive stop: if we are very close or overshot, stop
                     // Logic: if dist_remaining <= 0, we are done. 
                     // Or if dist_remaining is small, slow down.
                     if (dist_remaining <= 0.02) {
                         cmd.linear.x = 0.0;
                         state_ = INIT_TURN;
                     } else {
                         // Proportional braking (min vel 0.1 to avoid deadband)
                         double speed = std::max(0.1, 0.2 * (dist_remaining / linear_brake_dist_));
                         cmd.linear.x = speed;
                     }
                } else {
                    cmd.linear.x = 0.2; // Cruise speed as per tips
                }
                cmd.angular.z = 0.0;
                
                // Correction for straight line drift could be added here
                break;
            }
            case INIT_TURN: {
                RCLCPP_INFO(this->get_logger(), "State: TURNING");
                segment_start_yaw = current_yaw;
                target_yaw_ = normalize_angle(segment_start_yaw + (turn_direction_ * M_PI / 2.0));
                state_ = TURNING;
                break;
            }
            case TURNING: {
                double diff = normalize_angle(target_yaw_ - current_yaw);
                
                RCLCPP_INFO_THROTTLE(this->get_logger(), *this->get_clock(), 1000, 
                    "TURNING: diff=%.3f, target=%.3f, curr=%.3f", diff, target_yaw_, current_yaw);

                if (std::abs(diff) <= angular_brake_dist_) {
                    if (std::abs(diff) <= 0.02) {
                        cmd.angular.z = 0.0;
                        current_side_++;
                        if (current_side_ >= 4) {
                            current_side_ = 0;
                            current_lap_++;
                            // Calculate Lap Error Here if needed, or just post-process
                            if (current_lap_ >= total_laps_) {
                                state_ = FINISHED;
                            } else {
                                state_ = INIT_MOVE;
                            }
                        } else {
                            state_ = INIT_MOVE;
                        }
                    } else {
                         // Proportional braking (min vel 0.2 for Tiago rotation)
                         double speed = std::max(0.2, 0.3 * (std::abs(diff) / angular_brake_dist_));
                         cmd.angular.z = speed * (diff > 0 ? 1.0 : -1.0);
                    }
                } else {
                    cmd.angular.z = 0.3 * (diff > 0 ? 1.0 : -1.0); // Cruise turn speed
                }
                cmd.linear.x = 0.0;
                break;
            }
            default:
                break;
        }

        pub_cmd_->publish(cmd);
    }

    void generate_report() {
        if (data_log_.empty()) {
            RCLCPP_WARN(this->get_logger(), "No data collected.");
            return;
        }

        // Calculate Errors
        double total_pos_sq_err = 0;
        double total_orient_sq_err = 0;
        int count = 0;
        
        // Save CSV
        std::ofstream csv_file;
        std::string filename = "square_mover_data.csv";
        csv_file.open(filename);
        csv_file << "time,pos_err_sq,orient_err_sq\n";
        // Set precision for floating point output
        csv_file << std::fixed << std::setprecision(9);

        std::cout << "\n=== ERROR REPORT ===\n";
        std::cout << "Instantaneous MSE provided in CSV (Logged every 10s). Averages below:\n";

        for (const auto& d : data_log_) {
            total_pos_sq_err += d.pos_err_sq;
            total_orient_sq_err += d.orient_err_sq;
            count++;

            csv_file << d.timestamp << "," 
                     << d.pos_err_sq << "," << d.orient_err_sq << "\n";
        }
        csv_file.close();

        double mse_pos = total_pos_sq_err / count;
        double mse_orient = total_orient_sq_err / count;

        std::cout << "Avg MSE Position: " << mse_pos << " m^2\n";
        std::cout << "Avg MSE Orientation: " << mse_orient << " rad^2\n";
        std::cout << "Data saved to " << filename << "\n";
        std::cout << "====================\n";
    }

    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr pub_cmd_;
    rclcpp::Publisher<nav_msgs::msg::Path>::SharedPtr pub_path_; // Added
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr sub_odom_;
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr sub_gt_;
    rclcpp::TimerBase::SharedPtr timer_;

    State state_;
    nav_msgs::msg::Odometry current_pose_;
    nav_msgs::msg::Odometry start_pose_;
    nav_msgs::msg::Odometry gt_pose_;
    nav_msgs::msg::Path path_; // Added
    bool first_odom_;
    double target_yaw_;

    // Params
    double square_len_;
    int total_laps_;
    std::string direction_str_;
    double turn_direction_;
    double linear_brake_dist_;
    double angular_brake_dist_;
    double inertia_factor_;

    int current_lap_;
    int current_side_;
    
    std::vector<LogData> data_log_;
    double last_log_time_;
    double logging_counter_;
    bool report_generated_ = false;
};

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SquareMover>());
    rclcpp::shutdown();
    return 0;
}
