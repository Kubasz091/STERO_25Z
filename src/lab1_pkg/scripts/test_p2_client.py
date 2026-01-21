#!/usr/bin/env python3

import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node
from lab1_pkg.action import NavigateToWaypoints
from geometry_msgs.msg import Point

class TestP2Client(Node):

    def __init__(self):
        super().__init__('test_p2_client')
        self._action_client = ActionClient(self, NavigateToWaypoints, 'navigate_to_waypoints')

    def send_goal(self):
        goal_msg = NavigateToWaypoints.Goal()
        
        # Define some points relative to map (verify your map coordinates, these are examples)
        # Define waypoints that create a path and do NOT end at start (0,0)
        # to avoid premature "Goal Reached" by the controller.
        p1 = Point(x=0.00, y=3.52, z=0.0)
        p2 = Point(x=1.51, y=3.81, z=0.0)
        p3 = Point(x=4.59, y=3.52, z=0.0)
        
        goal_msg.waypoints = [p1, p2, p3]

        self._action_client.wait_for_server()
        
        self.get_logger().info('Sending goal...')
        
        self._send_goal_future = self._action_client.send_goal_async(
            goal_msg, 
            feedback_callback=self.feedback_callback)
            
        self._send_goal_future.add_done_callback(self.goal_response_callback)

    def goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().info('Goal rejected :(')
            return

        self.get_logger().info('Goal accepted :)')

        self._get_result_future = goal_handle.get_result_async()
        self._get_result_future.add_done_callback(self.get_result_callback)

    def get_result_callback(self, future):
        result = future.result().result
        self.get_logger().info(f'Result: {result.success}')
        rclpy.shutdown()

    def feedback_callback(self, feedback_msg):
        feedback = feedback_msg.feedback
        self.get_logger().info(f'Received feedback: {feedback.percentage_complete}%')

def main(args=None):
    rclpy.init(args=args)
    action_client = TestP2Client()
    action_client.send_goal()
    rclpy.spin(action_client)

if __name__ == '__main__':
    main()
