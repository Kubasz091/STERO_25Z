#include <memory>
#include <string>
#include <map>
#include <iostream>

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "nav2_msgs/action/navigate_to_pose.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"

// struct to hold pose data
struct SimplePose {
    double x;
    double y;
    double z_sin;
    double w_cos;
};

class PlaceNavigator : public rclcpp::Node
{
public:
    using NavigateToPose = nav2_msgs::action::NavigateToPose;
    using GoalHandleNav = rclcpp_action::ClientGoalHandle<NavigateToPose>;

    PlaceNavigator() : Node("place_navigator")
    {
        places_["fotel"]     = {0.00, 3.52, 0.178, 0.984};
        places_["kuchenka"]  = {1.51, 3.81, 0.948, -0.318};
        places_["wc"]        = {2.76, 1.81, -0.886, 0.464};
        places_["sypialnia"] = {4.59, 3.52, 0.949, 0.315};
        

        places_["test_start"] = {5.76, 2.66, 0.040, 0.999};
        places_["test_end"]   = {9.09, 3.67, 0.040, 0.999};

        this->client_ptr_ = rclcpp_action::create_client<NavigateToPose>(
            this,
            "navigate_to_pose"
        );

        input_thread_ = std::thread(std::bind(&PlaceNavigator::inputLoop, this));
    }

    ~PlaceNavigator()
    {
        if (input_thread_.joinable()) {
            input_thread_.join();
        }
    }

private:
    void inputLoop()
    {
        if (!this->client_ptr_->wait_for_action_server(std::chrono::seconds(10))) {
            RCLCPP_ERROR(this->get_logger(), "Action server 'navigate_to_pose' not available after waiting. Is Nav2 running?");
            return;
        }

        std::string input;
        while (rclcpp::ok()) {
            std::cout << "\n--- Dostepne miejsca: ---\n";
            for (const auto& pair : places_) {
                std::cout << "- " << pair.first << "\n";
            }
            std::cout << "Wpisz nazwe miejsca (lub 'q' zeby wyjsc): ";
            std::getline(std::cin, input);

            if (input == "q") {
                std::cout << "Powrot do punktu zerowego (0,0) przed wyjsciem...\n";
                sendGoal({0.0, 0.0, 0.0, 1.0});
                
                std::cout << "Oczekiwanie na dojazd...\n";
                while (!goal_done_ && rclcpp::ok()) {
                    std::this_thread::sleep_for(std::chrono::milliseconds(100));
                }
                break;
            }

            auto it = places_.find(input);
            if (it != places_.end()) {
                sendGoal(it->second);
            } else {
                std::cout << "Nieznane miejsce: " << input << std::endl;
            }
        }
        rclcpp::shutdown();
    }

    void sendGoal(const SimplePose& pose_data)
    {
        goal_done_ = false;
        auto goal_msg = NavigateToPose::Goal();
        goal_msg.pose.header.frame_id = "map";
        goal_msg.pose.header.stamp = rclcpp::Time(0);

        goal_msg.pose.pose.position.x = pose_data.x;
        goal_msg.pose.pose.position.y = pose_data.y;
        goal_msg.pose.pose.position.z = 0.0;

        double mag = std::sqrt(pose_data.z_sin * pose_data.z_sin + pose_data.w_cos * pose_data.w_cos);
        if (mag < 1e-6) {
            mag = 1.0;

        goal_msg.pose.pose.orientation.x = 0.0;
        goal_msg.pose.pose.orientation.y = 0.0;
        goal_msg.pose.pose.orientation.z = pose_data.z_sin / mag;
        goal_msg.pose.pose.orientation.w = pose_data.w_cos / mag;

        RCLCPP_INFO(this->get_logger(), "--- Sending Goal ---");
        RCLCPP_INFO(this->get_logger(), "Frame: %s", goal_msg.pose.header.frame_id.c_str());
        RCLCPP_INFO(this->get_logger(), "Pos: [x=%.3f, y=%.3f, z=%.3f]", 
            goal_msg.pose.pose.position.x, goal_msg.pose.pose.position.y, goal_msg.pose.pose.position.z);
        RCLCPP_INFO(this->get_logger(), "Ori: [x=%.3f, y=%.3f, z=%.3f, w=%.3f]", 
            goal_msg.pose.pose.orientation.x, goal_msg.pose.pose.orientation.y, 
            goal_msg.pose.pose.orientation.z, goal_msg.pose.pose.orientation.w);

        auto send_goal_options = rclcpp_action::Client<NavigateToPose>::SendGoalOptions();
        send_goal_options.goal_response_callback =
            std::bind(&PlaceNavigator::goal_response_callback, this, std::placeholders::_1);
        send_goal_options.result_callback =
            std::bind(&PlaceNavigator::result_callback, this, std::placeholders::_1);

        this->client_ptr_->async_send_goal(goal_msg, send_goal_options);
    }

    void goal_response_callback(const GoalHandleNav::SharedPtr & goal_handle)
    {
        if (!goal_handle) {
            RCLCPP_ERROR(this->get_logger(), "Goal was REJECTED by server.");
            RCLCPP_WARN(this->get_logger(), "Please check the terminal where you launched the simulation (Nav2) for the exact error reason (e.g., 'Goal is in lethal costmap').");
            goal_done_ = true;
        } else {
            RCLCPP_INFO(this->get_logger(), "Goal ACCEPTED by server, executing...");
        }
    }

    void result_callback(const GoalHandleNav::WrappedResult & result)
    {
        switch (result.code) {
            case rclcpp_action::ResultCode::SUCCEEDED:
                RCLCPP_INFO(this->get_logger(), "Robot dotarl do celu!");
                break;
            case rclcpp_action::ResultCode::ABORTED:
                RCLCPP_ERROR(this->get_logger(), "Cel porzucony (ABORTED)");
                break;
            case rclcpp_action::ResultCode::CANCELED:
                RCLCPP_ERROR(this->get_logger(), "Cel anulowany (CANCELED)");
                break;
            default:
                RCLCPP_ERROR(this->get_logger(), "Nieznany wynik akcji");
                break;
        }
        goal_done_ = true;
    }

    rclcpp_action::Client<NavigateToPose>::SharedPtr client_ptr_;
    std::map<std::string, SimplePose> places_;
    std::thread input_thread_;
    std::atomic<bool> goal_done_{true};
};

int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<PlaceNavigator>();
    rclcpp::spin(node);
    return 0;
}
