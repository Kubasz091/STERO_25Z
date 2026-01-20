#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer
from rclpy.callback_groups import ReentrantCallbackGroup
from rclpy.executors import MultiThreadedExecutor
from geometry_msgs.msg import Point, PoseStamped
from trajectory_msgs.msg import JointTrajectory, JointTrajectoryPoint
from nav2_simple_commander.robot_navigator import BasicNavigator, TaskResult
from lab1_pkg.action import NavigateToWaypoints
import math
import time
from tf2_ros import Buffer, TransformListener, LookupException, ConnectivityException, ExtrapolationException

class Lab2P2Node(Node):

    def __init__(self):
        super().__init__('lab2_p2_node')
        
        self.navigator = BasicNavigator()
        
        # TF Buffer for getting robot pose
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)
        
        self._action_server = ActionServer(
            self,
            NavigateToWaypoints,
            'navigate_to_waypoints',
            self.execute_callback,
            callback_group=ReentrantCallbackGroup())
            
        self.head_pub = self.create_publisher(
            JointTrajectory, 
            'head_controller/joint_trajectory', 
            10)
            
        self.get_logger().info('Lab2 Project 2 Node has been started.')

    def get_robot_pose(self):
        try:
            # Look up transform from map to base_link
            t = self.tf_buffer.lookup_transform(
                'map',
                'base_link',
                rclpy.time.Time())
                
            pose = PoseStamped()
            pose.header = t.header
            pose.pose.position.x = t.transform.translation.x
            pose.pose.position.y = t.transform.translation.y
            pose.pose.position.z = t.transform.translation.z
            pose.pose.orientation = t.transform.rotation
            return pose
        except (LookupException, ConnectivityException, ExtrapolationException):
            return None

    def execute_callback(self, goal_handle):
        self.get_logger().info('Executing goal...')
        waypoints = goal_handle.request.waypoints
        
        if not waypoints:
            self.get_logger().warn('No waypoints received!')
            goal_handle.succeed()
            result = NavigateToWaypoints.Result()
            result.success = True
            return result

        # Create PoseStamped list
        poses = []
        for pt in waypoints:
            pose = PoseStamped()
            pose.header.frame_id = 'map'
            pose.header.stamp = self.navigator.get_clock().now().to_msg()
            pose.pose.position.x = pt.x
            pose.pose.position.y = pt.y
            pose.pose.position.z = 0.0
            pose.pose.orientation.w = 1.0 
            poses.append(pose)

        # Estimate total path length
        path_segments_len = 0.0
        current_pose_check = self.get_robot_pose()
        
        if current_pose_check:
             dx = waypoints[0].x - current_pose_check.pose.position.x
             dy = waypoints[0].y - current_pose_check.pose.position.y
             path_segments_len += math.sqrt(dx*dx + dy*dy)
        else:
            # If we cant get pose, assume we are at 0,0 or just verify segments
            self.get_logger().warn('Could not get robot pose for initial distance calc.')
        
        for i in range(len(waypoints) - 1):
            dx = waypoints[i+1].x - waypoints[i].x
            dy = waypoints[i+1].y - waypoints[i].y
            path_segments_len += math.sqrt(dx*dx + dy*dy)
            
        original_total_dist = path_segments_len
        if original_total_dist == 0: original_total_dist = 1.0

        # Start Navigation
        self.navigator.goThroughPoses(poses)

        feedback_msg = NavigateToWaypoints.Feedback()
        
        last_yaw = 0.0
        # Initialize last_yaw from current pose if available
        if current_pose_check:
            q = current_pose_check.pose.orientation
            siny_cosp = 2 * (q.w * q.z + q.x * q.y)
            cosy_cosp = 1 - 2 * (q.y * q.y + q.z * q.z)
            last_yaw = math.atan2(siny_cosp, cosy_cosp)
        
        while not self.navigator.isTaskComplete():
            if goal_handle.is_cancel_requested:
                goal_handle.canceled()
                self.navigator.cancelTask()
                self.get_logger().info('Goal canceled')
                return NavigateToWaypoints.Result(success=False)

            # --- Feedback ---
            nav_feedback = self.navigator.getFeedback()
            if nav_feedback:
                dist_rem = nav_feedback.distance_remaining
                ratio = 1.0
                if original_total_dist > 0:
                    ratio = 1.0 - (dist_rem / original_total_dist)
                
                if ratio < 0: ratio = 0.0
                if ratio > 1: ratio = 1.0
                
                feedback_msg.percentage_complete = ratio * 100.0
                goal_handle.publish_feedback(feedback_msg)

            # --- Head Control ---
            current_pose = self.get_robot_pose()
            if current_pose:
                # Calculate yaw
                q = current_pose.pose.orientation
                siny_cosp = 2 * (q.w * q.z + q.x * q.y)
                cosy_cosp = 1 - 2 * (q.y * q.y + q.z * q.z)
                current_yaw = math.atan2(siny_cosp, cosy_cosp)
                
                yaw_diff = current_yaw - last_yaw
                while yaw_diff > math.pi: yaw_diff -= 2*math.pi
                while yaw_diff < -math.pi: yaw_diff += 2*math.pi
                
                last_yaw = current_yaw
                
                turn_threshold = 0.01 
                
                head_yaw = 0.0
                if yaw_diff > turn_threshold: # Turning Left
                    head_yaw = 0.5 
                elif yaw_diff < -turn_threshold: # Turning Right
                    head_yaw = -0.5 
                else:
                    head_yaw = 0.0 
                    
                traj = JointTrajectory()
                traj.joint_names = ['head_1_joint', 'head_2_joint']
                point = JointTrajectoryPoint()
                point.positions = [float(head_yaw), 0.0] 
                point.time_from_start.sec = 1
                point.time_from_start.nanosec = 0
                traj.points.append(point)
                self.head_pub.publish(traj)
            
            time.sleep(0.1)

        result = self.navigator.getResult()
        if result == TaskResult.SUCCEEDED:
            self.get_logger().info('Goal succeeded!')
            goal_handle.succeed()
            res = NavigateToWaypoints.Result()
            res.success = True
            return res
        elif result == TaskResult.CANCELED:
            self.get_logger().info('Goal was canceled!')
            goal_handle.canceled()
            res = NavigateToWaypoints.Result()
            res.success = False
            return res
        elif result == TaskResult.FAILED:
            self.get_logger().info('Goal failed!')
            goal_handle.abort()
            res = NavigateToWaypoints.Result()
            res.success = False
            return res
        else:
            self.get_logger().info('Goal has an invalid return status!')
            goal_handle.abort()
            res = NavigateToWaypoints.Result()
            res.success = False
            return res

def main(args=None):
    rclpy.init(args=args)
    node = Lab2P2Node()
    
    executor = MultiThreadedExecutor()
    executor.add_node(node)
    
    try:
        executor.spin()
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
