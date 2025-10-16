# Antoni Matczuk Jakub Szubzda lab 1 stero

# zad 1
wywołanie tego polecenia
``` bash
vcs import --input https://raw.githubusercontent.com/RCPRG-
ros-pkg/STERO2/refs/heads/iron/tiago_public_stero.repos
src
```

miało efekt pobrania potrzebnych pluginów do src

---
# zad 2
te polecenia
```bash
source /opt/ros/iron/setup.bash
colcon build --symlink-install
```
załadowały środowisko ROS 2 Iron, 
spowodowały zbudowanie wszystkich potrzebnych paczek w katalogu tiago

Co zmienia --symlink-install:
- zamiast kopiować pliki do install/ tworzy dowiązania symboliczne do zbudowanych/źródłowych plików (zwł. dla pakietów Python i zasobów),
- przyspiesza przebudowy i zmniejsza zużycie miejsca; zmiany w plikach Pythona widoczne od razu bez reinstalacji,
- nie zmienia kompilacji; binaria/biblioteki pochodzą z build/.

---

# zad 3

``` bash
student@pantera:~/stero$ cd src/
student@pantera:~/stero/src$ source install/local_setup.bash
student@pantera:~/stero/src$ ros2 run my_package my_node
Package 'my_package' not found
student@pantera:~/stero/src$ ros2 run hello_stero hello_stero_node
hello world hello_stero package
```

# zad 4

``` bash
student@pantera:~/stero$ ros2 action info /execute_trajectory
Action: /execute_trajectory
Action clients: 1
    //p/l/a/y/_/m/o/t/i/o/n/2_move_group_node
Action servers: 1
    /move_group
```

# zad 5

``` bash
student@pantera:~/stero$ ros2 action info /execute_trajectory
Action: /execute_trajectory
Action clients: 2
    //p/l/a/y/_/m/o/t/i/o/n/2_move_group_node
    /rviz
Action servers: 1
    /move_group
```

# zad 6
``` bash
student@pantera:~/stero$ ros2 node list | grep move_group
WARNING: Be aware that there are nodes in the graph that share an exact name, which can have unintended side effects.
/move_group
/move_group_private_96272869041408
student@pantera:~/stero$ ros2 node info /move_group
/move_group
  Subscribers:
    /clock: rosgraph_msgs/msg/Clock
    /parameter_events: rcl_interfaces/msg/ParameterEvent
    /throttle_filtering_points/filtered_points: sensor_msgs/msg/PointCloud2
    /trajectory_execution_event: std_msgs/msg/String
  Publishers:
    /display_contacts: visualization_msgs/msg/MarkerArray
    /display_planned_path: moveit_msgs/msg/DisplayTrajectory
    /filtered_cloud: sensor_msgs/msg/PointCloud2
    /motion_plan_request: moveit_msgs/msg/MotionPlanRequest
    /parameter_events: rcl_interfaces/msg/ParameterEvent
    /robot_description_semantic: std_msgs/msg/String
    /rosout: rcl_interfaces/msg/Log
  Service Servers:
    /apply_planning_scene: moveit_msgs/srv/ApplyPlanningScene
    /check_state_validity: moveit_msgs/srv/GetStateValidity
    /clear_octomap: std_srvs/srv/Empty
    /compute_cartesian_path: moveit_msgs/srv/GetCartesianPath
    /compute_fk: moveit_msgs/srv/GetPositionFK
    /compute_ik: moveit_msgs/srv/GetPositionIK
    /get_planner_params: moveit_msgs/srv/GetPlannerParams
    /load_map: moveit_msgs/srv/LoadMap
    /move_group/describe_parameters: rcl_interfaces/srv/DescribeParameters
    /move_group/get_parameter_types: rcl_interfaces/srv/GetParameterTypes
    /move_group/get_parameters: rcl_interfaces/srv/GetParameters
    /move_group/get_type_description: type_description_interfaces/srv/GetTypeDescription
    /move_group/list_parameters: rcl_interfaces/srv/ListParameters
    /move_group/set_parameters: rcl_interfaces/srv/SetParameters
    /move_group/set_parameters_atomically: rcl_interfaces/srv/SetParametersAtomically
    /plan_kinematic_path: moveit_msgs/srv/GetMotionPlan
    /query_planner_interface: moveit_msgs/srv/QueryPlannerInterfaces
    /save_map: moveit_msgs/srv/SaveMap
    /set_planner_params: moveit_msgs/srv/SetPlannerParams
  Service Clients:

  Action Servers:
    /execute_trajectory: moveit_msgs/action/ExecuteTrajectory
    /move_action: moveit_msgs/action/MoveGroup
  Action Clients:
```

``` bash
student@pantera:~/stero$ ros2 node info /move_group_private_96272869041408
/move_group_private_96272869041408
  Subscribers:
    /attached_collision_object: moveit_msgs/msg/AttachedCollisionObject
    /clock: rosgraph_msgs/msg/Clock
    /collision_object: moveit_msgs/msg/CollisionObject
    /joint_states: sensor_msgs/msg/JointState
    /parameter_events: rcl_interfaces/msg/ParameterEvent
    /planning_scene: moveit_msgs/msg/PlanningScene
    /planning_scene_world: moveit_msgs/msg/PlanningSceneWorld
  Publishers:
    /monitored_planning_scene: moveit_msgs/msg/PlanningScene
    /parameter_events: rcl_interfaces/msg/ParameterEvent
    /rosout: rcl_interfaces/msg/Log
  Service Servers:
    /get_planning_scene: moveit_msgs/srv/GetPlanningScene
    /move_group_private_96272869041408/describe_parameters: rcl_interfaces/srv/DescribeParameters
    /move_group_private_96272869041408/get_parameter_types: rcl_interfaces/srv/GetParameterTypes
    /move_group_private_96272869041408/get_parameters: rcl_interfaces/srv/GetParameters
    /move_group_private_96272869041408/get_type_description: type_description_interfaces/srv/GetTypeDescription
    /move_group_private_96272869041408/list_parameters: rcl_interfaces/srv/ListParameters
    /move_group_private_96272869041408/set_parameters: rcl_interfaces/srv/SetParameters
    /move_group_private_96272869041408/set_parameters_atomically: rcl_interfaces/srv/SetParametersAtomically
  Service Clients:

  Action Servers:

  Action Clients:
```

# zad 7


# zad 8
``` bash
student@pantera:~/stero$ ros2 control list_hardware_interfaces
[WARN] [1760603031.328857765] [_ros2cli_71201]: Failed getting a result from calling /controller_manager/list_hardware_interfaces in 0.0. (Attempt 1 of 3.)
command interfaces
	arm_1_joint/effort [available] [unclaimed]
	arm_1_joint/position [available] [claimed]
	arm_1_joint/velocity [available] [unclaimed]
	arm_2_joint/effort [available] [unclaimed]
	arm_2_joint/position [available] [claimed]
	arm_2_joint/velocity [available] [unclaimed]
	arm_3_joint/effort [available] [unclaimed]
	arm_3_joint/position [available] [claimed]
	arm_3_joint/velocity [available] [unclaimed]
	arm_4_joint/effort [available] [unclaimed]
	arm_4_joint/position [available] [claimed]
	arm_4_joint/velocity [available] [unclaimed]
	arm_5_joint/effort [available] [unclaimed]
	arm_5_joint/position [available] [claimed]
	arm_5_joint/velocity [available] [unclaimed]
	arm_6_joint/effort [available] [unclaimed]
	arm_6_joint/position [available] [claimed]
	arm_6_joint/velocity [available] [unclaimed]
	arm_7_joint/effort [available] [unclaimed]
	arm_7_joint/position [available] [claimed]
	arm_7_joint/velocity [available] [unclaimed]
	gripper_left_finger_joint/position [available] [claimed]
	gripper_right_finger_joint/position [available] [claimed]
	head_1_joint/position [available] [claimed]
	head_2_joint/position [available] [claimed]
	torso_lift_joint/position [available] [claimed]
	wheel_left_joint/velocity [available] [claimed]
	wheel_right_joint/velocity [available] [claimed]
state interfaces
	arm_1_joint/effort
	arm_1_joint/position
	arm_1_joint/velocity
	arm_2_joint/effort
	arm_2_joint/position
	arm_2_joint/velocity
	arm_3_joint/effort
	arm_3_joint/position
	arm_3_joint/velocity
	arm_4_joint/effort
	arm_4_joint/position
	arm_4_joint/velocity
	arm_5_joint/effort
	arm_5_joint/position
	arm_5_joint/velocity
	arm_6_joint/effort
	arm_6_joint/position
	arm_6_joint/velocity
	arm_7_joint/effort
	arm_7_joint/position
	arm_7_joint/velocity
	base_imu_sensor/angular_velocity.x
	base_imu_sensor/angular_velocity.y
	base_imu_sensor/angular_velocity.z
	base_imu_sensor/linear_acceleration.x
	base_imu_sensor/linear_acceleration.y
	base_imu_sensor/linear_acceleration.z
	base_imu_sensor/orientation.w
	base_imu_sensor/orientation.x
	base_imu_sensor/orientation.y
	base_imu_sensor/orientation.z
	gripper_left_finger_joint/effort
	gripper_left_finger_joint/position
	gripper_left_finger_joint/velocity
	gripper_right_finger_joint/effort
	gripper_right_finger_joint/position
	gripper_right_finger_joint/velocity
	head_1_joint/effort
	head_1_joint/position
	head_1_joint/velocity
	head_2_joint/effort
	head_2_joint/position
	head_2_joint/velocity
	torso_lift_joint/effort
	torso_lift_joint/position
	torso_lift_joint/velocity
	wheel_left_joint/position
	wheel_right_joint/position
	wrist_ft_sensor/force.x
	wrist_ft_sensor/force.y
	wrist_ft_sensor/force.z
	wrist_ft_sensor/torque.x
	wrist_ft_sensor/torque.y
	wrist_ft_sensor/torque.z
```

``` bash
student@pantera:~/stero$ ros2 control list_hardware_interfaces | grep arm_1_joint
[WARN] [1760603139.514779005] [_ros2cli_71246]: Failed getting a result from calling /controller_manager/list_hardware_interfaces in 0.0. (Attempt 1 of 3.)
	arm_1_joint/effort [available] [unclaimed]
	arm_1_joint/position [available] [claimed]
	arm_1_joint/velocity [available] [unclaimed]
	arm_1_joint/effort
	arm_1_joint/position
	arm_1_joint/velocity
```
