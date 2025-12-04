# Laboratorium 1 - Raport

## 1. Konfiguracja środowiska pracy

### Analiza struktury systemu robota TIAGo

#### Identyfikacja tematów sterowania i sensorów robota

Poniżej przedstawiono zidentyfikowane tematy wraz z ich opisem oraz statusem weryfikacji (czy są aktywne).

1.  **Sterowanie prędkością bazy**
    *   **Temat:** `/cmd_vel` (lub `/mobile_base_controller/cmd_vel_unstamped`)
    *   **Typ:** `geometry_msgs/msg/Twist`
    *   **Opis:** Służy do wysyłania poleceń prędkości liniowej i kątowej do bazy robota. To tutaj publikujemy, aby robot się poruszał.
    *   **Status:** Oczekuje na dane (brak aktywnych publikatorów w spoczynku).

2.  **Odometria**
    *   **Temat:** `/mobile_base_controller/odom`
    *   **Typ:** `nav_msgs/msg/Odometry`
    *   **Opis:** Zawiera estymowaną pozycję i prędkość robota obliczoną na podstawie enkoderów kół. Kluczowe dla lokalizacji i nawigacji.
    *   **Status:** Aktywny (publikuje dane o pozycji).

3.  **Czujnik LiDAR**
    *   **Temat:** `/scan_raw` (uwaga: `/scan` jest widoczny, ale nieaktywny)
    *   **Typ:** `sensor_msgs/msg/LaserScan`
    *   **Opis:** Dane z lasera 2D skanującego otoczenie w płaszczyźnie. Używany do wykrywania przeszkód i tworzenia mapy.
    *   **Status:** `/scan_raw` jest aktywny (posiada publikatora).

4.  **Kamera RGB-D**
    *   **Obraz RGB:** `/head_front_camera/rgb/image_raw`
        *   **Typ:** `sensor_msgs/msg/Image`
        *   **Opis:** Surowy obraz kolorowy z kamery umieszczonej na głowie robota.
        *   **Status:** Aktywny (~28 Hz).
    *   **Chmura punktów:** `/head_front_camera/depth_registered/points`
        *   **Typ:** `sensor_msgs/msg/PointCloud2`
        *   **Opis:** Trójwymiarowa chmura punktów reprezentująca widok przed robotem (współrzędne X, Y, Z + kolor). Używana do percepcji 3D.
        *   **Status:** Aktywny (~26 Hz).

#### Drzewo transformacji (TF Tree)
Wygenerowano plik z drzewem transformacji: `tf_tree.pdf`.

## Topics
/amcl/transition_event
/amcl_pose
/arm_controller/controller_state
/arm_controller/joint_trajectory
/arm_controller/transition_event
/attached_collision_object
/base_imu
/behavior_server/transition_event
/behavior_tree_log
/bond
/bt_navigator/transition_event
/clicked_point
/clock
/cmd_vel
/cmd_vel_nav
/collision_object
/controller_manager/robot_description
/controller_server/transition_event
/cost_cloud
/diagnostics
/display_contacts
/display_planned_path
/downsampled_costmap
/downsampled_costmap_updates
/dynamic_joint_states
/evaluation
/filtered_cloud
/ft_sensor_controller/transition_event
/ft_sensor_controller/wrench
/global_costmap/costmap
/global_costmap/costmap_raw
/global_costmap/costmap_updates
/global_costmap/footprint
/global_costmap/global_costmap/transition_event
/global_costmap/obstacle_layer
/global_costmap/obstacle_layer_raw
/global_costmap/obstacle_layer_updates
/global_costmap/published_footprint
/global_costmap/static_layer
/global_costmap/static_layer_raw
/global_costmap/static_layer_updates
/global_costmap/voxel_marked_cloud
/goal_pose
/gripper_controller/controller_state
/gripper_controller/joint_trajectory
/gripper_controller/transition_event
/ground_truth_odom
/head_controller/controller_state
/head_controller/joint_trajectory
/head_controller/transition_event
/head_front_camera/depth_registered/camera_info
/head_front_camera/depth_registered/image_raw
/head_front_camera/depth_registered/points
/head_front_camera/rgb/camera_info
/head_front_camera/rgb/image_raw
/imu_sensor_broadcaster/imu
/imu_sensor_broadcaster/transition_event
/initialpose
/input_joy/cmd_vel
/joint_state_broadcaster/transition_event
/joint_states
/joy_priority
/joy_vel
/key_vel
/local_costmap/clearing_endpoints
/local_costmap/costmap
/local_costmap/costmap_raw
/local_costmap/costmap_updates
/local_costmap/footprint
/local_costmap/local_costmap/transition_event
/local_costmap/published_footprint
/local_costmap/voxel_grid
/local_costmap/voxel_layer
/local_costmap/voxel_layer_raw
/local_costmap/voxel_layer_updates
/local_costmap/voxel_marked_cloud
/local_plan
/map
/map_server/transition_event
/map_updates
/marker
/marker_vel
/mobile_base/sensors/bumper_pointcloud
/mobile_base_controller/cmd_vel_out
/mobile_base_controller/cmd_vel_unstamped
/mobile_base_controller/odom
/mobile_base_controller/transition_event
/monitored_planning_scene
/motion_plan_request
/parameter_events
/particle_cloud
/pause_navigation
/performance_metrics
/phone_vel
/plan
/plan_smoothed
/planner_server/transition_event
/planning_scene
/planning_scene_world
/play_motion2/transition_event
/received_global_plan
/robot_description
/robot_description_semantic
/rosout
/rviz_joy_vel
/scan
/scan_raw
/servoing_cmd_vel
/smoother_server/transition_event
/sonar_base
/speed_limit
/stop_closing_loop
/tab_vel
/text_marker
/tf
/tf_static
/throttle_filtering_points/filtered_points
/torso_controller/controller_state
/torso_controller/joint_trajectory
/torso_controller/transition_event
/trajectory_execution_event
/transformed_global_plan
/velocity_smoother/transition_event
/waypoint_follower/transition_event
/waypoints
## Nodes
/amcl
/lifecycle_manager_navigation
/map_server
/move_group
/move_group_private_99865224190016
/moveit_simple_controller_manager
/robot_state_publisher
/transform_listener_impl_5ad3af369c80
/transform_listener_impl_5ad3afc309a0
/transform_listener_impl_5bdaab4440f0
/twist_marker
/twist_mux
/velocity_smoother
## Doctor Report

   NETWORK CONFIGURATION
inet         : 127.0.0.1
inet4        : ['127.0.0.1']
inet6        : ['::1']
netmask      : 255.0.0.0
device       : lo
flags        : 73<LOOPBACK,UP,RUNNING>
mtu          : 65536
inet         : 10.2.13.134
inet4        : ['10.2.13.134']
ether        : a8:a1:59:27:61:a5
inet6        : ['fe80::515:dd36:6e85:8bfe%enp7s0']
netmask      : 255.255.0.0
device       : enp7s0
flags        : 4163<BROADCAST,UP,MULTICAST,RUNNING>
mtu          : 1500
broadcast    : 10.2.255.255
inet         : 10.42.0.1
inet4        : ['10.42.0.1']
ether        : 5c:80:b6:45:16:bd
inet6        : ['fe80::ac45:bada:17bb:c882%wlp5s0']
netmask      : 255.255.255.0
device       : wlp5s0
flags        : 4163<BROADCAST,UP,MULTICAST,RUNNING>
mtu          : 1500
broadcast    : 10.42.0.255
inet         : 100.112.0.47
inet4        : ['100.112.0.47']
inet6        : ['fd7a:115c:a1e0::2001:3b', 'fe80::a328:93d5:dbde:1f94%tailscale0']
netmask      : 255.255.255.255
device       : tailscale0
flags        : 4305<PTP,NOARP,MULTICAST,UP,RUNNING>
mtu          : 1280
inet         : 172.17.0.1
inet4        : ['172.17.0.1']
ether        : 22:d1:50:b8:02:35
netmask      : 255.255.0.0
device       : docker0
flags        : 4099<BROADCAST,UP,MULTICAST>
mtu          : 1500
broadcast    : 172.17.255.255

   PACKAGE VERSIONS
urdf_test                                 : latest=, local=2.0.3
tiago_simulation                          : latest=, local=4.1.9
tiago_robot                               : latest=, local=4.3.0
tiago_navigation                          : latest=, local=4.1.7
tiago_gazebo                              : latest=, local=4.1.9
tiago_moveit_config                       : latest=, local=3.0.18
tiago_2dnav                               : latest=, local=4.1.7
tiago_laser_sensors                       : latest=, local=4.1.7
tiago_bringup                             : latest=, local=4.3.0
tiago_description                         : latest=, local=4.3.0
tiago_controller_configuration            : latest=, local=4.3.0
pmb2_robot                                : latest=, local=5.1.2
pmb2_navigation                           : latest=, local=4.1.1
pmb2_2dnav                                : latest=, local=4.1.1
pmb2_laser_sensors                        : latest=, local=4.1.1
pmb2_bringup                              : latest=, local=5.1.2
pmb2_description                          : latest=, local=5.1.2
pmb2_controller_configuration             : latest=, local=5.1.2
play_motion2                              : latest=, local=1.2.0
play_motion2_msgs                         : latest=, local=1.2.0
pal_hey5                                  : latest=, local=4.1.0
pal_hey5_description                      : latest=, local=4.1.0
pal_gripper_simulation                    : latest=, local=3.2.0
pal_gripper                               : latest=, local=3.2.0
pal_gripper_description                   : latest=, local=3.2.0
pal_urdf_utils                            : latest=, local=2.0.1
pal_robotiq_gripper                       : latest=, local=2.1.0
pal_robotiq_description                   : latest=, local=2.1.0
pal_robotiq_controller_configuration      : latest=, local=2.1.0
pal_navigation_cfg                        : latest=, local=3.0.6
pal_navigation_cfg_bringup                : latest=, local=3.0.6
pal_navigation_cfg_params                 : latest=, local=3.0.6
pal_maps                                  : latest=, local=0.0.5
pal_hey5_controller_configuration         : latest=, local=4.1.0
pal_gripper_controller_configuration      : latest=, local=3.2.0
pal_gazebo_worlds                         : latest=, local=4.0.4
pal_gazebo_plugins                        : latest=, local=4.0.5
launch_pal                                : latest=, local=0.3.0
gazebo_grasp_plugin                       : latest=, local=4.1.9
gazebo_version_helpers                    : latest=, local=0.0.0
zstd_vendor                               : latest=0.22.8, local=0.22.8
rqt_gui_py                                : latest=1.3.4, local=1.3.4
gazebo_dev                                : latest=3.7.0, local=3.7.0
rosidl_generator_c                        : latest=4.0.1, local=4.0.1
action_tutorials_interfaces               : latest=0.27.2, local=0.27.2
rosidl_parser                             : latest=4.0.1, local=4.0.1
ament_cmake_pep257                        : latest=0.14.4, local=0.14.4
rmw                                       : latest=7.1.0, local=7.1.0
rosidl_runtime_c                          : latest=4.0.1, local=4.0.1
type_description_interfaces               : latest=1.6.0, local=1.6.0
rcl_lifecycle                             : latest=6.0.7, local=6.0.7
rqt_gui_cpp                               : latest=1.3.4, local=1.3.4
rosidl_runtime_py                         : latest=0.12.0, local=0.12.0
examples_rclpy_executors                  : latest=0.18.2, local=0.18.2
twist_mux                                 : latest=4.3.0, local=4.3.0
octomap                                   : latest=1.9.8, local=1.9.8
launch_testing_ament_cmake                : latest=2.0.4, local=2.0.4
ros2multicast                             : latest=0.25.8, local=0.25.8
tf2_kdl                                   : latest=0.31.8, local=0.31.8
rosidl_typesupport_c                      : latest=3.0.1, local=3.0.1
tf2_ros                                   : latest=0.31.8, local=0.31.8
rttest                                    : latest=0.15.0, local=0.15.0
rosbag2_interfaces                        : latest=0.22.8, local=0.22.8
tf2_ros_py                                : latest=0.31.8, local=0.31.8
rviz_assimp_vendor                        : latest=12.4.10, local=12.4.10
fastrtps_cmake_module                     : latest=3.0.2, local=3.0.2
python_cmake_module                       : latest=0.10.2, local=0.10.2
costmap_queue                             : latest=1.2.10, local=1.2.10
moveit_ros_robot_interaction              : latest=2.8.0, local=2.8.0
moveit_ros_warehouse                      : latest=2.8.0, local=2.8.0
rosidl_generator_type_description         : latest=4.0.1, local=4.0.1
rmw_dds_common                            : latest=2.0.1, local=2.0.1
statistics_msgs                           : latest=1.6.0, local=1.6.0
rosidl_generator_py                       : latest=0.18.0, local=0.18.0
examples_rclpy_minimal_action_client      : latest=0.18.2, local=0.18.2
geometry2                                 : latest=0.31.8, local=0.31.8
rclpy                                     : latest=4.1.7, local=4.1.7
examples_rclcpp_minimal_subscriber        : latest=0.18.2, local=0.18.2
warehouse_ros                             : latest=2.0.5, local=2.0.5
rqt_action                                : latest=2.1.2, local=2.1.2
hardware_interface                        : latest=3.30.0, local=3.30.0
examples_rclpy_minimal_service            : latest=0.18.2, local=0.18.2
rqt_plot                                  : latest=1.2.3, local=1.2.3
filters                                   : latest=2.1.0, local=2.1.0
nav2_bringup                              : latest=1.2.10, local=1.2.10
imu_sensor_broadcaster                    : latest=3.28.0, local=3.28.0
moveit_planners_ompl                      : latest=2.8.0, local=2.8.0
ros2cli_common_extensions                 : latest=0.2.2, local=0.2.2
libcurl_vendor                            : latest=3.2.3, local=3.2.3
geographic_msgs                           : latest=1.0.6, local=1.0.6
actionlib_msgs                            : latest=5.0.1, local=5.0.1
unique_identifier_msgs                    : latest=2.3.2, local=2.3.2
realtime_tools                            : latest=2.8.1, local=2.8.1
service_msgs                              : latest=1.6.0, local=1.6.0
rqt_service_caller                        : latest=1.1.1, local=1.1.1
pcl_conversions                           : latest=2.5.4, local=2.5.4
rviz_default_plugins                      : latest=12.4.10, local=12.4.10
nav2_regulated_pure_pursuit_controller    : latest=1.2.10, local=1.2.10
quality_of_service_demo_py                : latest=0.27.2, local=0.27.2
rqt_common_plugins                        : latest=1.2.0, local=1.2.0
ros2_control_test_assets                  : latest=3.30.0, local=3.30.0
osrf_pycommon                             : latest=2.1.2, local=2.1.2
moveit_visual_tools                       : latest=4.1.0, local=4.1.0
rqt_publisher                             : latest=1.6.3, local=1.6.3
sensor_msgs_py                            : latest=5.0.1, local=5.0.1
ament_xmllint                             : latest=0.14.4, local=0.14.4
ros2topic                                 : latest=0.25.8, local=0.25.8
dummy_robot_bringup                       : latest=0.27.2, local=0.27.2
nav2_costmap_2d                           : latest=1.2.10, local=1.2.10
tf2                                       : latest=0.31.8, local=0.31.8
urdfdom_py                                : latest=1.2.1, local=1.2.1
ament_cmake_lint_cmake                    : latest=0.14.4, local=0.14.4
ros2component                             : latest=0.25.8, local=0.25.8
builtin_interfaces                        : latest=1.6.0, local=1.6.0
ament_cmake_export_interfaces             : latest=2.0.7, local=2.0.7
bondcpp                                   : latest=4.0.0, local=4.0.0
ament_cmake_python                        : latest=2.0.7, local=2.0.7
ros2service                               : latest=0.25.8, local=0.25.8
rosidl_typesupport_interface              : latest=4.0.1, local=4.0.1
gazebo_ros                                : latest=3.7.0, local=3.7.0
gazebo_ros2_control                       : latest=0.6.8, local=0.6.8
rmw_implementation                        : latest=2.12.1, local=2.12.1
ament_lint_cmake                          : latest=0.14.4, local=0.14.4
kdl_parser                                : latest=2.9.0, local=2.9.0
uncrustify_vendor                         : latest=2.1.2, local=2.1.2
geometric_shapes                          : latest=2.1.3, local=2.1.3
examples_rclcpp_minimal_client            : latest=0.18.2, local=0.18.2
launch                                    : latest=2.0.4, local=2.0.4
rosidl_default_generators                 : latest=1.5.0, local=1.5.0
ament_cmake_export_targets                : latest=2.0.7, local=2.0.7
rmw_fastrtps_cpp                          : latest=7.1.4, local=7.1.4
diff_drive_controller                     : latest=3.28.0, local=3.28.0
rviz_visual_tools                         : latest=4.1.4, local=4.1.4
teleop_twist_joy                          : latest=2.5.2, local=2.5.2
position_controllers                      : latest=3.28.0, local=3.28.0
tlsf_cpp                                  : latest=0.15.0, local=0.15.0
ros2lifecycle                             : latest=0.25.8, local=0.25.8
moveit_ros_perception                     : latest=2.8.0, local=2.8.0
qt_gui_py_common                          : latest=2.4.3, local=2.4.3
nav2_dwb_controller                       : latest=1.2.10, local=1.2.10
pcl_msgs                                  : latest=1.0.0, local=1.0.0
laser_geometry                            : latest=2.5.0, local=2.5.0
pendulum_msgs                             : latest=0.27.2, local=0.27.2
nav2_navfn_planner                        : latest=1.2.10, local=1.2.10
std_msgs                                  : latest=5.0.1, local=5.0.1
examples_rclcpp_minimal_timer             : latest=0.18.2, local=0.18.2
rosbag2_storage                           : latest=0.22.8, local=0.22.8
nav2_controller                           : latest=1.2.10, local=1.2.10
rosidl_typesupport_fastrtps_c             : latest=3.0.2, local=3.0.2
graph_msgs                                : latest=0.2.0, local=0.2.0
dwb_critics                               : latest=1.2.10, local=1.2.10
sensor_msgs                               : latest=5.0.1, local=5.0.1
rosbag2_cpp                               : latest=0.22.8, local=0.22.8
domain_coordinator                        : latest=0.11.2, local=0.11.2
launch_yaml                               : latest=2.0.4, local=2.0.4
ros2param                                 : latest=0.25.8, local=0.25.8
rcl_logging_interface                     : latest=2.5.1, local=2.5.1
rqt_msg                                   : latest=1.3.1, local=1.3.1
tl_expected                               : latest=1.0.2, local=1.0.2
ros2controlcli                            : latest=3.30.0, local=3.30.0
tango_icons_vendor                        : latest=0.2.2, local=0.2.2
rosbag2_transport                         : latest=0.22.8, local=0.22.8
nav2_rotation_shim_controller             : latest=1.2.10, local=1.2.10
moveit_ros_planning                       : latest=2.8.0, local=2.8.0
moveit_ros_control_interface              : latest=2.8.0, local=2.8.0
teleop_twist_keyboard                     : latest=2.4.0, local=2.4.0
examples_rclcpp_minimal_publisher         : latest=0.18.2, local=0.18.2
qt_dotgraph                               : latest=2.4.3, local=2.4.3
moveit_ros_visualization                  : latest=2.8.0, local=2.8.0
depthimage_to_laserscan                   : latest=2.5.1, local=2.5.1
gazebo_ros_pkgs                           : latest=3.7.0, local=3.7.0
rqt_py_console                            : latest=1.1.1, local=1.1.1
geometry_msgs                             : latest=5.0.1, local=5.0.1
ament_cmake                               : latest=2.0.7, local=2.0.7
rosbag2                                   : latest=0.22.8, local=0.22.8
control_toolbox                           : latest=3.3.0, local=3.3.0
ament_cmake_pytest                        : latest=2.0.7, local=2.0.7
moveit_core                               : latest=2.8.0, local=2.8.0
desktop                                   : latest=0.10.0, local=0.10.0
ament_lint_auto                           : latest=0.14.4, local=0.14.4
twist_mux_msgs                            : latest=3.0.1, local=3.0.1
smclib                                    : latest=4.0.0, local=4.0.0
rqt_reconfigure                           : latest=1.3.4, local=1.3.4
ros2cli                                   : latest=0.25.8, local=0.25.8
libstatistics_collector                   : latest=1.5.3, local=1.5.3
gazebo_msgs                               : latest=3.7.0, local=3.7.0
launch_testing                            : latest=2.0.4, local=2.0.4
sros2                                     : latest=0.11.3, local=0.11.3
moveit_kinematics                         : latest=2.8.0, local=2.8.0
examples_rclpy_minimal_subscriber         : latest=0.18.2, local=0.18.2
launch_testing_ros                        : latest=0.24.2, local=0.24.2
moveit_ros_occupancy_map_monitor          : latest=2.8.0, local=2.8.0
ament_pep257                              : latest=0.14.4, local=0.14.4
rviz_rendering                            : latest=12.4.10, local=12.4.10
examples_rclcpp_minimal_composition       : latest=0.18.2, local=0.18.2
eigen3_cmake_module                       : latest=0.2.2, local=0.2.2
ament_copyright                           : latest=0.14.4, local=0.14.4
rqt_topic                                 : latest=1.6.1, local=1.6.1
nav2_map_server                           : latest=1.2.10, local=1.2.10
rosidl_generator_cpp                      : latest=4.0.1, local=4.0.1
intra_process_demo                        : latest=0.27.2, local=0.27.2
tf2_eigen                                 : latest=0.31.8, local=0.31.8
tf2_sensor_msgs                           : latest=0.31.8, local=0.31.8
slam_toolbox                              : latest=2.7.4, local=2.7.4
tf2_py                                    : latest=0.31.8, local=0.31.8
nav2_voxel_grid                           : latest=1.2.10, local=1.2.10
ament_cmake_xmllint                       : latest=0.14.4, local=0.14.4
tcb_span                                  : latest=1.0.2, local=1.0.2
rosidl_runtime_cpp                        : latest=4.0.1, local=4.0.1
rqt_bag                                   : latest=1.3.5, local=1.3.5
nav2_planner                              : latest=1.2.10, local=1.2.10
qt_gui_cpp                                : latest=2.4.3, local=2.4.3
nav_2d_msgs                               : latest=1.2.10, local=1.2.10
nav2_smoother                             : latest=1.2.10, local=1.2.10
rosbag2_compression                       : latest=0.22.8, local=0.22.8
teleop_tools_msgs                         : latest=1.7.0, local=1.7.0
ament_cmake_libraries                     : latest=2.0.7, local=2.0.7
control_msgs                              : latest=5.2.0, local=5.2.0
ament_cmake_copyright                     : latest=0.14.4, local=0.14.4
ament_cmake_include_directories           : latest=2.0.7, local=2.0.7
rclcpp_components                         : latest=21.0.8, local=21.0.8
behaviortree_cpp_v3                       : latest=3.8.7, local=3.8.7
turtlebot3_gazebo                         : latest=2.2.5, local=2.2.5
camera_info_manager                       : latest=4.2.4, local=4.2.4
ros2doctor                                : latest=0.25.8, local=0.25.8
diagnostic_msgs                           : latest=5.0.1, local=5.0.1
rosbag2_storage_mcap                      : latest=0.22.8, local=0.22.8
sros2_cmake                               : latest=0.11.3, local=0.11.3
dwb_msgs                                  : latest=1.2.10, local=1.2.10
tracetools                                : latest=6.3.3, local=6.3.3
action_tutorials_cpp                      : latest=0.27.2, local=0.27.2
nav2_smac_planner                         : latest=1.2.10, local=1.2.10
rviz2                                     : latest=12.4.10, local=12.4.10
nav2_collision_monitor                    : latest=1.2.10, local=1.2.10
diagnostic_updater                        : latest=4.1.0, local=4.1.0
pluginlib                                 : latest=5.2.2, local=5.2.2
rosidl_typesupport_introspection_cpp      : latest=4.0.1, local=4.0.1
rcutils                                   : latest=6.2.4, local=6.2.4
bond                                      : latest=4.0.0, local=4.0.0
rcl_action                                : latest=6.0.7, local=6.0.7
rcl_yaml_param_parser                     : latest=6.0.7, local=6.0.7
random_numbers                            : latest=2.0.1, local=2.0.1
rqt_gui                                   : latest=1.3.4, local=1.3.4
controller_manager_msgs                   : latest=3.30.0, local=3.30.0
joint_state_publisher                     : latest=2.4.0, local=2.4.0
map_msgs                                  : latest=2.2.0, local=2.2.0
tinyxml2_vendor                           : latest=0.8.3, local=0.8.3
joy_linux                                 : latest=3.3.0, local=3.3.0
ament_cmake_gmock                         : latest=2.0.7, local=2.0.7
ament_index_python                        : latest=1.5.2, local=1.5.2
examples_rclpy_minimal_client             : latest=0.18.2, local=0.18.2
ament_cmake_gtest                         : latest=2.0.7, local=2.0.7
object_recognition_msgs                   : latest=2.0.0, local=2.0.0
moveit_simple_controller_manager          : latest=2.8.0, local=2.8.0
ament_cmake_target_dependencies           : latest=2.0.7, local=2.0.7
mcap_vendor                               : latest=0.22.8, local=0.22.8
cv_bridge                                 : latest=3.5.0, local=3.5.0
orocos_kdl_vendor                         : latest=0.3.4, local=0.3.4
dwb_core                                  : latest=1.2.10, local=1.2.10
rcl                                       : latest=6.0.7, local=6.0.7
turtlesim                                 : latest=1.6.1, local=1.6.1
rosbag2_storage_sqlite3                   : latest=0.22.8, local=0.22.8
rpyutils                                  : latest=0.3.2, local=0.3.2
rviz_common                               : latest=12.4.10, local=12.4.10
class_loader                              : latest=2.5.0, local=2.5.0
ros2run                                   : latest=0.25.8, local=0.25.8
example_interfaces                        : latest=0.10.2, local=0.10.2
tf2_eigen_kdl                             : latest=0.31.8, local=0.31.8
nav2_behavior_tree                        : latest=1.2.10, local=1.2.10
rosidl_cli                                : latest=4.0.1, local=4.0.1
nav2_simple_commander                     : latest=1.2.10, local=1.2.10
shared_queues_vendor                      : latest=0.22.8, local=0.22.8
ament_cmake_version                       : latest=2.0.7, local=2.0.7
tf2_bullet                                : latest=0.31.8, local=0.31.8
dummy_map_server                          : latest=0.27.2, local=0.27.2
lifecycle_msgs                            : latest=1.6.0, local=1.6.0
stereo_msgs                               : latest=5.0.1, local=5.0.1
ros_workspace                             : latest=1.0.3, local=1.0.3
nav2_util                                 : latest=1.2.10, local=1.2.10
action_tutorials_py                       : latest=0.27.2, local=0.27.2
ament_package                             : latest=0.15.3, local=0.15.3
nav2_core                                 : latest=1.2.10, local=1.2.10
angles                                    : latest=1.16.0, local=1.16.0
rosidl_dynamic_typesupport                : latest=0.0.5, local=0.0.5
trajectory_msgs                           : latest=5.0.1, local=5.0.1
logging_demo                              : latest=0.27.2, local=0.27.2
dummy_sensors                             : latest=0.27.2, local=0.27.2
topic_monitor                             : latest=0.27.2, local=0.27.2
generate_parameter_library                : latest=0.3.9, local=0.3.9
joint_state_publisher_gui                 : latest=2.4.0, local=2.4.0
nav2_common                               : latest=1.2.10, local=1.2.10
gazebo_plugins                            : latest=3.7.0, local=3.7.0
demo_nodes_cpp_native                     : latest=0.27.2, local=0.27.2
ament_cmake_flake8                        : latest=0.14.4, local=0.14.4
moveit_ros_move_group                     : latest=2.8.0, local=2.8.0
rosidl_default_runtime                    : latest=1.5.0, local=1.5.0
nav2_bt_navigator                         : latest=1.2.10, local=1.2.10
rosgraph_msgs                             : latest=1.6.0, local=1.6.0
eigen_stl_containers                      : latest=1.0.0, local=1.0.0
ament_cmake_ros                           : latest=0.11.2, local=0.11.2
examples_rclcpp_multithreaded_executor    : latest=0.18.2, local=0.18.2
tlsf                                      : latest=0.8.2, local=0.8.2
demo_nodes_cpp                            : latest=0.27.2, local=0.27.2
ament_lint_common                         : latest=0.14.4, local=0.14.4
shape_msgs                                : latest=5.0.1, local=5.0.1
nav_2d_utils                              : latest=1.2.10, local=1.2.10
rqt_py_common                             : latest=1.3.4, local=1.3.4
rqt_srv                                   : latest=1.1.1, local=1.1.1
python_qt_binding                         : latest=1.2.4, local=1.2.4
examples_rclpy_minimal_publisher          : latest=0.18.2, local=0.18.2
nav2_velocity_smoother                    : latest=1.2.10, local=1.2.10
controller_manager                        : latest=3.30.0, local=3.30.0
ament_cmake_export_dependencies           : latest=2.0.7, local=2.0.7
rqt_bag_plugins                           : latest=1.3.5, local=1.3.5
spdlog_vendor                             : latest=1.4.4, local=1.4.4
ament_cmake_test                          : latest=2.0.7, local=2.0.7
ament_cmake_export_link_flags             : latest=2.0.7, local=2.0.7
composition_interfaces                    : latest=1.6.0, local=1.6.0
demo_nodes_py                             : latest=0.27.2, local=0.27.2
force_torque_sensor_broadcaster           : latest=3.28.0, local=3.28.0
ament_cmake_cppcheck                      : latest=0.14.4, local=0.14.4
rosidl_cmake                              : latest=4.0.1, local=4.0.1
rqt_console                               : latest=2.1.1, local=2.1.1
nav2_constrained_smoother                 : latest=1.2.10, local=1.2.10
std_srvs                                  : latest=5.0.1, local=5.0.1
robot_state_publisher                     : latest=3.2.1, local=3.2.1
ros_base                                  : latest=0.10.0, local=0.10.0
ament_cmake_export_include_directories    : latest=2.0.7, local=2.0.7
ros_environment                           : latest=4.1.1, local=4.1.1
ament_cmake_cpplint                       : latest=0.14.4, local=0.14.4
composition                               : latest=0.27.2, local=0.27.2
nav2_mppi_controller                      : latest=1.2.10, local=1.2.10
action_msgs                               : latest=1.6.0, local=1.6.0
joy_teleop                                : latest=1.7.0, local=1.7.0
ros2interface                             : latest=0.25.8, local=0.25.8
ros2action                                : latest=0.25.8, local=0.25.8
ament_cppcheck                            : latest=0.14.4, local=0.14.4
nav_msgs                                  : latest=5.0.1, local=5.0.1
rclcpp_action                             : latest=21.0.8, local=21.0.8
examples_rclcpp_minimal_action_client     : latest=0.18.2, local=0.18.2
ament_cpplint                             : latest=0.14.4, local=0.14.4
ament_uncrustify                          : latest=0.14.4, local=0.14.4
keyboard_handler                          : latest=0.1.0, local=0.1.0
rosbag2_storage_default_plugins           : latest=0.22.8, local=0.22.8
rclcpp                                    : latest=21.0.8, local=21.0.8
moveit_common                             : latest=2.8.0, local=2.8.0
nav2_waypoint_follower                    : latest=1.2.10, local=1.2.10
srdfdom                                   : latest=2.0.5, local=2.0.5
ament_index_cpp                           : latest=1.5.2, local=1.5.2
qt_gui                                    : latest=2.4.3, local=2.4.3
rosbag2_py                                : latest=0.22.8, local=0.22.8
rosidl_core_runtime                       : latest=0.1.1, local=0.1.1
rosidl_typesupport_cpp                    : latest=3.0.1, local=3.0.1
moveit_configs_utils                      : latest=2.8.0, local=2.8.0
rosidl_dynamic_typesupport_fastrtps       : latest=0.0.2, local=0.0.2
ament_cmake_gen_version_h                 : latest=2.0.7, local=2.0.7
quality_of_service_demo_cpp               : latest=0.27.2, local=0.27.2
ament_cmake_export_definitions            : latest=2.0.7, local=2.0.7
ros2bag                                   : latest=0.22.8, local=0.22.8
rviz_ogre_vendor                          : latest=12.4.10, local=12.4.10
tf2_msgs                                  : latest=0.31.8, local=0.31.8
nav2_theta_star_planner                   : latest=1.2.10, local=1.2.10
rosidl_adapter                            : latest=4.0.1, local=4.0.1
rqt_graph                                 : latest=1.4.3, local=1.4.3
image_transport                           : latest=4.2.4, local=4.2.4
ament_cmake_core                          : latest=2.0.7, local=2.0.7
octomap_msgs                              : latest=2.0.1, local=2.0.1
examples_rclpy_minimal_action_server      : latest=0.18.2, local=0.18.2
urdf                                      : latest=2.8.2, local=2.8.2
yaml_cpp_vendor                           : latest=8.1.2, local=8.1.2
rosidl_core_generators                    : latest=0.1.1, local=0.1.1
ament_flake8                              : latest=0.14.4, local=0.14.4
rmw_implementation_cmake                  : latest=7.1.0, local=7.1.0
sqlite3_vendor                            : latest=0.22.8, local=0.22.8
rcl_logging_spdlog                        : latest=2.5.1, local=2.5.1
rosidl_typesupport_introspection_c        : latest=4.0.1, local=4.0.1
rosidl_pycommon                           : latest=4.0.1, local=4.0.1
lifecycle                                 : latest=0.27.2, local=0.27.2
rclcpp_lifecycle                          : latest=21.0.8, local=21.0.8
sdl2_vendor                               : latest=3.3.0, local=3.3.0
ros2pkg                                   : latest=0.25.8, local=0.25.8
rosbag2_compression_zstd                  : latest=0.22.8, local=0.22.8
rqt_image_view                            : latest=1.2.0, local=1.2.0
controller_interface                      : latest=3.30.0, local=3.30.0
nav2_behaviors                            : latest=1.2.10, local=1.2.10
nav2_amcl                                 : latest=1.2.10, local=1.2.10
rcl_interfaces                            : latest=1.6.0, local=1.6.0
ament_lint                                : latest=0.14.4, local=0.14.4
robot_localization                        : latest=3.7.1, local=3.7.1
rosidl_typesupport_fastrtps_cpp           : latest=3.0.2, local=3.0.2
resource_retriever                        : latest=3.2.3, local=3.2.3
console_bridge_vendor                     : latest=1.6.0, local=1.6.0
moveit_ros_planning_interface             : latest=2.8.0, local=2.8.0
joint_state_broadcaster                   : latest=3.28.0, local=3.28.0
urdf_parser_plugin                        : latest=2.8.2, local=2.8.2
moveit_msgs                               : latest=2.3.0, local=2.3.0
nav2_msgs                                 : latest=1.2.10, local=1.2.10
joint_trajectory_controller               : latest=3.28.0, local=3.28.0
launch_ros                                : latest=0.24.2, local=0.24.2
parameter_traits                          : latest=0.3.9, local=0.3.9
libyaml_vendor                            : latest=1.5.0, local=1.5.0
nav2_rviz_plugins                         : latest=1.2.10, local=1.2.10
image_geometry                            : latest=3.5.0, local=3.5.0
ompl                                      : latest=1.6.0, local=1.6.0
dwb_plugins                               : latest=1.2.10, local=1.2.10
nav2_lifecycle_manager                    : latest=1.2.10, local=1.2.10
ament_cmake_uncrustify                    : latest=0.14.4, local=0.14.4
navigation2                               : latest=1.2.10, local=1.2.10
joy                                       : latest=3.3.0, local=3.3.0
ros2launch                                : latest=0.24.2, local=0.24.2
tf2_tools                                 : latest=0.31.8, local=0.31.8
camera_calibration_parsers                : latest=4.2.4, local=4.2.4
launch_param_builder                      : latest=0.1.1, local=0.1.1
tinyxml_vendor                            : latest=0.9.2, local=0.9.2
rqt_shell                                 : latest=1.1.1, local=1.1.1
xacro                                     : latest=2.0.11, local=2.0.11
ros2node                                  : latest=0.25.8, local=0.25.8
image_tools                               : latest=0.27.2, local=0.27.2
ament_cmake_auto                          : latest=2.0.7, local=2.0.7
message_filters                           : latest=4.7.1, local=4.7.1
visualization_msgs                        : latest=5.0.1, local=5.0.1
examples_rclcpp_minimal_service           : latest=0.18.2, local=0.18.2
ros_core                                  : latest=0.10.0, local=0.10.0
rcpputils                                 : latest=2.6.4, local=2.6.4
forward_command_controller                : latest=3.28.0, local=3.28.0
tf2_geometry_msgs                         : latest=0.31.8, local=0.31.8
interactive_markers                       : latest=2.4.0, local=2.4.0
rmw_fastrtps_shared_cpp                   : latest=7.1.4, local=7.1.4
launch_xml                                : latest=2.0.4, local=2.0.4
pendulum_control                          : latest=0.27.2, local=0.27.2
ament_cmake_export_libraries              : latest=2.0.7, local=2.0.7
pybind11_vendor                           : latest=3.0.3, local=3.0.3
generate_parameter_library_py             : latest=0.3.9, local=0.3.9
common_interfaces                         : latest=5.0.1, local=5.0.1
examples_rclcpp_minimal_action_server     : latest=0.18.2, local=0.18.2

   PLATFORM INFORMATION
system           : Linux
platform info    : Linux-6.8.0-87-generic-x86_64-with-glibc2.35
release          : 6.8.0-87-generic
processor        : x86_64

   QOS COMPATIBILITY LIST
topic [type]            : /arm_controller/follow_joint_trajectory/_action/feedback [control_msgs/action/FollowJointTrajectory_FeedbackMessage]
publisher node          : arm_controller
subscriber node         : moveit_simple_controller_manager
compatibility status    : OK
topic [type]            : /arm_controller/follow_joint_trajectory/_action/feedback [control_msgs/action/FollowJointTrajectory_FeedbackMessage]
publisher node          : arm_controller
subscriber node         : play_motion2
compatibility status    : OK
topic [type]            : /arm_controller/follow_joint_trajectory/_action/status [action_msgs/msg/GoalStatusArray]
publisher node          : arm_controller
subscriber node         : moveit_simple_controller_manager
compatibility status    : OK
topic [type]            : /arm_controller/follow_joint_trajectory/_action/status [action_msgs/msg/GoalStatusArray]
publisher node          : arm_controller
subscriber node         : play_motion2
compatibility status    : OK
topic [type]            : /attached_collision_object [moveit_msgs/msg/AttachedCollisionObject]
publisher node          : _move_group_node
subscriber node         : move_group_private_99865224190016
compatibility status    : OK
topic [type]            : /attached_collision_object [moveit_msgs/msg/AttachedCollisionObject]
publisher node          : _move_group_node
subscriber node         : move_group_private_99865224190016
compatibility status    : OK
topic [type]            : /backup/_action/feedback [nav2_msgs/action/BackUp_FeedbackMessage]
publisher node          : behavior_server
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /backup/_action/feedback [nav2_msgs/action/BackUp_FeedbackMessage]
publisher node          : behavior_server
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /backup/_action/status [action_msgs/msg/GoalStatusArray]
publisher node          : behavior_server
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /backup/_action/status [action_msgs/msg/GoalStatusArray]
publisher node          : behavior_server
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : controller_server
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : controller_server
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : controller_server
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : controller_server
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : controller_server
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : controller_server
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : controller_server
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : controller_server
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : controller_server
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : controller_server
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : controller_server
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : controller_server
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : controller_server
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : controller_server
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : controller_server
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : controller_server
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : controller_server
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : controller_server
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : smoother_server
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : smoother_server
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : smoother_server
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : smoother_server
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : smoother_server
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : smoother_server
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : smoother_server
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : smoother_server
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : smoother_server
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : smoother_server
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : smoother_server
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : smoother_server
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : smoother_server
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : smoother_server
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : smoother_server
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : smoother_server
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : smoother_server
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : smoother_server
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : planner_server
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : planner_server
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : planner_server
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : planner_server
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : planner_server
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : planner_server
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : planner_server
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : planner_server
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : planner_server
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : planner_server
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : planner_server
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : planner_server
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : planner_server
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : planner_server
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : planner_server
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : planner_server
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : planner_server
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : planner_server
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : behavior_server
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : behavior_server
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : behavior_server
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : behavior_server
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : behavior_server
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : behavior_server
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : behavior_server
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : behavior_server
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : behavior_server
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : behavior_server
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : behavior_server
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : behavior_server
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : behavior_server
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : behavior_server
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : behavior_server
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : behavior_server
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : behavior_server
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : behavior_server
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : bt_navigator
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : bt_navigator
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : bt_navigator
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : bt_navigator
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : bt_navigator
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : bt_navigator
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : bt_navigator
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : bt_navigator
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : bt_navigator
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : bt_navigator
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : bt_navigator
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : bt_navigator
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : bt_navigator
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : bt_navigator
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : bt_navigator
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : bt_navigator
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : bt_navigator
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : bt_navigator
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : waypoint_follower
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : waypoint_follower
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : waypoint_follower
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : waypoint_follower
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : waypoint_follower
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : waypoint_follower
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : waypoint_follower
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : waypoint_follower
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : waypoint_follower
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : waypoint_follower
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : waypoint_follower
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : waypoint_follower
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : waypoint_follower
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : waypoint_follower
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : waypoint_follower
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : waypoint_follower
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : waypoint_follower
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : waypoint_follower
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : velocity_smoother
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : velocity_smoother
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : velocity_smoother
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : velocity_smoother
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : velocity_smoother
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : velocity_smoother
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : velocity_smoother
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : velocity_smoother
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : velocity_smoother
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : velocity_smoother
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : velocity_smoother
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : velocity_smoother
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : velocity_smoother
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : velocity_smoother
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : velocity_smoother
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : velocity_smoother
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : velocity_smoother
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : velocity_smoother
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : map_server
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : map_server
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : map_server
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : map_server
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : map_server
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : map_server
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : map_server
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : map_server
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : map_server
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : map_server
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : map_server
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : map_server
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : map_server
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : map_server
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : map_server
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : map_server
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : map_server
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : map_server
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : amcl
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : amcl
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : amcl
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : amcl
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : amcl
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : amcl
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : amcl
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : amcl
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : amcl
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : amcl
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : amcl
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : amcl
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : amcl
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : amcl
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : amcl
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : amcl
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : amcl
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : amcl
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_localization
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_localization
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_localization
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_localization
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_localization
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_localization
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_localization
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_localization
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_localization
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_localization
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_localization
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_localization
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_localization
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_localization
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_localization
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_localization
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_localization
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_localization
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_localization
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_localization
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_localization
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_localization
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_localization
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_localization
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_localization
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_localization
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_localization
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_localization
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_localization
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_localization
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_localization
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_localization
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_localization
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_localization
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_localization
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /bond [bond/msg/Status]
publisher node          : lifecycle_manager_localization
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /clock [rosgraph_msgs/msg/Clock]
publisher node          : gazebo
subscriber node         : gazebo
compatibility status    : OK
topic [type]            : /clock [rosgraph_msgs/msg/Clock]
publisher node          : gazebo
subscriber node         : base_imu
compatibility status    : OK
topic [type]            : /clock [rosgraph_msgs/msg/Clock]
publisher node          : gazebo
subscriber node         : base_laser
compatibility status    : OK
topic [type]            : /clock [rosgraph_msgs/msg/Clock]
publisher node          : gazebo
subscriber node         : base_sonar_01_gazebo_ros_range
compatibility status    : OK
topic [type]            : /clock [rosgraph_msgs/msg/Clock]
publisher node          : gazebo
subscriber node         : base_sonar_02_gazebo_ros_range
compatibility status    : OK
topic [type]            : /clock [rosgraph_msgs/msg/Clock]
publisher node          : gazebo
subscriber node         : base_sonar_03_gazebo_ros_range
compatibility status    : OK
topic [type]            : /clock [rosgraph_msgs/msg/Clock]
publisher node          : gazebo
subscriber node         : head_front_camera_frame_controller
compatibility status    : OK
topic [type]            : /clock [rosgraph_msgs/msg/Clock]
publisher node          : gazebo
subscriber node         : gazebo_ros_odometry
compatibility status    : OK
topic [type]            : /clock [rosgraph_msgs/msg/Clock]
publisher node          : gazebo
subscriber node         : gazebo_ros2_control
compatibility status    : OK
topic [type]            : /clock [rosgraph_msgs/msg/Clock]
publisher node          : gazebo
subscriber node         : controller_manager
compatibility status    : OK
topic [type]            : /clock [rosgraph_msgs/msg/Clock]
publisher node          : gazebo
subscriber node         : mobile_base_controller
compatibility status    : OK
topic [type]            : /clock [rosgraph_msgs/msg/Clock]
publisher node          : gazebo
subscriber node         : gripper_controller
compatibility status    : OK
topic [type]            : /clock [rosgraph_msgs/msg/Clock]
publisher node          : gazebo
subscriber node         : head_controller
compatibility status    : OK
topic [type]            : /clock [rosgraph_msgs/msg/Clock]
publisher node          : gazebo
subscriber node         : joint_state_broadcaster
compatibility status    : OK
topic [type]            : /clock [rosgraph_msgs/msg/Clock]
publisher node          : gazebo
subscriber node         : imu_sensor_broadcaster
compatibility status    : OK
topic [type]            : /clock [rosgraph_msgs/msg/Clock]
publisher node          : gazebo
subscriber node         : arm_controller
compatibility status    : OK
topic [type]            : /clock [rosgraph_msgs/msg/Clock]
publisher node          : gazebo
subscriber node         : torso_controller
compatibility status    : OK
topic [type]            : /clock [rosgraph_msgs/msg/Clock]
publisher node          : gazebo
subscriber node         : ft_sensor_controller
compatibility status    : OK
topic [type]            : /clock [rosgraph_msgs/msg/Clock]
publisher node          : gazebo
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /clock [rosgraph_msgs/msg/Clock]
publisher node          : gazebo
subscriber node         : local_costmap
compatibility status    : OK
topic [type]            : /clock [rosgraph_msgs/msg/Clock]
publisher node          : gazebo
subscriber node         : transform_listener_impl_5973afb268b0
compatibility status    : OK
topic [type]            : /clock [rosgraph_msgs/msg/Clock]
publisher node          : gazebo
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /clock [rosgraph_msgs/msg/Clock]
publisher node          : gazebo
subscriber node         : transform_listener_impl_654ee1c865e0
compatibility status    : OK
topic [type]            : /clock [rosgraph_msgs/msg/Clock]
publisher node          : gazebo
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /clock [rosgraph_msgs/msg/Clock]
publisher node          : gazebo
subscriber node         : global_costmap
compatibility status    : OK
topic [type]            : /clock [rosgraph_msgs/msg/Clock]
publisher node          : gazebo
subscriber node         : transform_listener_impl_623f34f20190
compatibility status    : OK
topic [type]            : /clock [rosgraph_msgs/msg/Clock]
publisher node          : gazebo
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /clock [rosgraph_msgs/msg/Clock]
publisher node          : gazebo
subscriber node         : transform_listener_impl_5ec47a4d1ab0
compatibility status    : OK
topic [type]            : /clock [rosgraph_msgs/msg/Clock]
publisher node          : gazebo
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /clock [rosgraph_msgs/msg/Clock]
publisher node          : gazebo
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /clock [rosgraph_msgs/msg/Clock]
publisher node          : gazebo
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /clock [rosgraph_msgs/msg/Clock]
publisher node          : gazebo
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /clock [rosgraph_msgs/msg/Clock]
publisher node          : gazebo
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /clock [rosgraph_msgs/msg/Clock]
publisher node          : gazebo
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /clock [rosgraph_msgs/msg/Clock]
publisher node          : gazebo
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /clock [rosgraph_msgs/msg/Clock]
publisher node          : gazebo
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /clock [rosgraph_msgs/msg/Clock]
publisher node          : gazebo
subscriber node         : transform_listener_impl_5bdaab4440f0
compatibility status    : OK
topic [type]            : /clock [rosgraph_msgs/msg/Clock]
publisher node          : gazebo
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /clock [rosgraph_msgs/msg/Clock]
publisher node          : gazebo
subscriber node         : move_group
compatibility status    : OK
topic [type]            : /clock [rosgraph_msgs/msg/Clock]
publisher node          : gazebo
subscriber node         : move_group_private_99865224190016
compatibility status    : OK
topic [type]            : /clock [rosgraph_msgs/msg/Clock]
publisher node          : gazebo
subscriber node         : transform_listener_impl_5ad3af369c80
compatibility status    : OK
topic [type]            : /clock [rosgraph_msgs/msg/Clock]
publisher node          : gazebo
subscriber node         : transform_listener_impl_5ad3afc309a0
compatibility status    : OK
topic [type]            : /clock [rosgraph_msgs/msg/Clock]
publisher node          : gazebo
subscriber node         : moveit_simple_controller_manager
compatibility status    : OK
topic [type]            : /clock [rosgraph_msgs/msg/Clock]
publisher node          : gazebo
subscriber node         : play_motion2
compatibility status    : OK
topic [type]            : /clock [rosgraph_msgs/msg/Clock]
publisher node          : gazebo
subscriber node         : _move_group_node
compatibility status    : OK
topic [type]            : /cmd_vel [geometry_msgs/msg/Twist]
publisher node          : behavior_server
subscriber node         : twist_mux
compatibility status    : OK
topic [type]            : /cmd_vel [geometry_msgs/msg/Twist]
publisher node          : behavior_server
subscriber node         : twist_mux
compatibility status    : OK
topic [type]            : /cmd_vel [geometry_msgs/msg/Twist]
publisher node          : behavior_server
subscriber node         : twist_mux
compatibility status    : OK
topic [type]            : /cmd_vel [geometry_msgs/msg/Twist]
publisher node          : behavior_server
subscriber node         : twist_mux
compatibility status    : OK
topic [type]            : /cmd_vel [geometry_msgs/msg/Twist]
publisher node          : velocity_smoother
subscriber node         : twist_mux
compatibility status    : OK
topic [type]            : /cmd_vel_nav [geometry_msgs/msg/Twist]
publisher node          : controller_server
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /compute_path_through_poses/_action/feedback [nav2_msgs/action/ComputePathThroughPoses_FeedbackMessage]
publisher node          : planner_server
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /compute_path_through_poses/_action/status [action_msgs/msg/GoalStatusArray]
publisher node          : planner_server
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /compute_path_to_pose/_action/feedback [nav2_msgs/action/ComputePathToPose_FeedbackMessage]
publisher node          : planner_server
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /compute_path_to_pose/_action/status [action_msgs/msg/GoalStatusArray]
publisher node          : planner_server
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /execute_trajectory/_action/feedback [moveit_msgs/action/ExecuteTrajectory_FeedbackMessage]
publisher node          : move_group
subscriber node         : _move_group_node
compatibility status    : OK
topic [type]            : /execute_trajectory/_action/feedback [moveit_msgs/action/ExecuteTrajectory_FeedbackMessage]
publisher node          : move_group
subscriber node         : _move_group_node
compatibility status    : OK
topic [type]            : /execute_trajectory/_action/status [action_msgs/msg/GoalStatusArray]
publisher node          : move_group
subscriber node         : _move_group_node
compatibility status    : OK
topic [type]            : /execute_trajectory/_action/status [action_msgs/msg/GoalStatusArray]
publisher node          : move_group
subscriber node         : _move_group_node
compatibility status    : OK
topic [type]            : /follow_path/_action/feedback [nav2_msgs/action/FollowPath_FeedbackMessage]
publisher node          : controller_server
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /follow_path/_action/feedback [nav2_msgs/action/FollowPath_FeedbackMessage]
publisher node          : controller_server
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /follow_path/_action/status [action_msgs/msg/GoalStatusArray]
publisher node          : controller_server
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /follow_path/_action/status [action_msgs/msg/GoalStatusArray]
publisher node          : controller_server
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /follow_waypoints/_action/feedback [nav2_msgs/action/FollowWaypoints_FeedbackMessage]
publisher node          : waypoint_follower
subscriber node         : rviz_navigation_dialog_action_client
compatibility status    : OK
topic [type]            : /follow_waypoints/_action/status [action_msgs/msg/GoalStatusArray]
publisher node          : waypoint_follower
subscriber node         : rviz_navigation_dialog_action_client
compatibility status    : OK
topic [type]            : /global_costmap/costmap [nav_msgs/msg/OccupancyGrid]
publisher node          : global_costmap
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /global_costmap/costmap_raw [nav2_msgs/msg/Costmap]
publisher node          : global_costmap
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /global_costmap/costmap_updates [map_msgs/msg/OccupancyGridUpdate]
publisher node          : global_costmap
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /global_costmap/published_footprint [geometry_msgs/msg/PolygonStamped]
publisher node          : global_costmap
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /gripper_controller/follow_joint_trajectory/_action/feedback [control_msgs/action/FollowJointTrajectory_FeedbackMessage]
publisher node          : gripper_controller
subscriber node         : moveit_simple_controller_manager
compatibility status    : OK
topic [type]            : /gripper_controller/follow_joint_trajectory/_action/status [action_msgs/msg/GoalStatusArray]
publisher node          : gripper_controller
subscriber node         : moveit_simple_controller_manager
compatibility status    : OK
topic [type]            : /head_controller/follow_joint_trajectory/_action/feedback [control_msgs/action/FollowJointTrajectory_FeedbackMessage]
publisher node          : head_controller
subscriber node         : moveit_simple_controller_manager
compatibility status    : OK
topic [type]            : /head_controller/follow_joint_trajectory/_action/status [action_msgs/msg/GoalStatusArray]
publisher node          : head_controller
subscriber node         : moveit_simple_controller_manager
compatibility status    : OK
topic [type]            : /initialpose [geometry_msgs/msg/PoseWithCovarianceStamped]
publisher node          : rviz
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /joint_states [sensor_msgs/msg/JointState]
publisher node          : joint_state_broadcaster
subscriber node         : move_group_private_99865224190016
compatibility status    : OK
topic [type]            : /joint_states [sensor_msgs/msg/JointState]
publisher node          : joint_state_broadcaster
subscriber node         : play_motion2
compatibility status    : OK
topic [type]            : /joint_states [sensor_msgs/msg/JointState]
publisher node          : joint_state_broadcaster
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /joy_priority [std_msgs/msg/Bool]
publisher node          : joystick_relay
subscriber node         : twist_mux
compatibility status    : OK
topic [type]            : /joy_vel [geometry_msgs/msg/Twist]
publisher node          : joystick_relay
subscriber node         : twist_mux
compatibility status    : OK
topic [type]            : /local_costmap/costmap [nav_msgs/msg/OccupancyGrid]
publisher node          : local_costmap
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /local_costmap/costmap_raw [nav2_msgs/msg/Costmap]
publisher node          : local_costmap
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /local_costmap/costmap_updates [map_msgs/msg/OccupancyGridUpdate]
publisher node          : local_costmap
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /local_costmap/published_footprint [geometry_msgs/msg/PolygonStamped]
publisher node          : local_costmap
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /local_costmap/published_footprint [geometry_msgs/msg/PolygonStamped]
publisher node          : local_costmap
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /local_plan [nav_msgs/msg/Path]
publisher node          : controller_server
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /map [nav_msgs/msg/OccupancyGrid]
publisher node          : map_server
subscriber node         : global_costmap
compatibility status    : OK
topic [type]            : /map [nav_msgs/msg/OccupancyGrid]
publisher node          : map_server
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /map [nav_msgs/msg/OccupancyGrid]
publisher node          : map_server
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /mobile_base_controller/cmd_vel_unstamped [geometry_msgs/msg/Twist]
publisher node          : twist_mux
subscriber node         : mobile_base_controller
compatibility status    : OK
topic [type]            : /mobile_base_controller/cmd_vel_unstamped [geometry_msgs/msg/Twist]
publisher node          : twist_mux
subscriber node         : twist_marker
compatibility status    : OK
topic [type]            : /mobile_base_controller/odom [nav_msgs/msg/Odometry]
publisher node          : mobile_base_controller
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /mobile_base_controller/odom [nav_msgs/msg/Odometry]
publisher node          : mobile_base_controller
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /move_action/_action/feedback [moveit_msgs/action/MoveGroup_FeedbackMessage]
publisher node          : move_group
subscriber node         : _move_group_node
compatibility status    : OK
topic [type]            : /move_action/_action/feedback [moveit_msgs/action/MoveGroup_FeedbackMessage]
publisher node          : move_group
subscriber node         : _move_group_node
compatibility status    : OK
topic [type]            : /move_action/_action/status [action_msgs/msg/GoalStatusArray]
publisher node          : move_group
subscriber node         : _move_group_node
compatibility status    : OK
topic [type]            : /move_action/_action/status [action_msgs/msg/GoalStatusArray]
publisher node          : move_group
subscriber node         : _move_group_node
compatibility status    : OK
topic [type]            : /navigate_through_poses/_action/feedback [nav2_msgs/action/NavigateThroughPoses_FeedbackMessage]
publisher node          : bt_navigator
subscriber node         : rviz_navigation_dialog_action_client
compatibility status    : OK
topic [type]            : /navigate_through_poses/_action/feedback [nav2_msgs/action/NavigateThroughPoses_FeedbackMessage]
publisher node          : bt_navigator
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /navigate_through_poses/_action/status [action_msgs/msg/GoalStatusArray]
publisher node          : bt_navigator
subscriber node         : rviz_navigation_dialog_action_client
compatibility status    : OK
topic [type]            : /navigate_through_poses/_action/status [action_msgs/msg/GoalStatusArray]
publisher node          : bt_navigator
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /navigate_to_pose/_action/feedback [nav2_msgs/action/NavigateToPose_FeedbackMessage]
publisher node          : bt_navigator
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /navigate_to_pose/_action/feedback [nav2_msgs/action/NavigateToPose_FeedbackMessage]
publisher node          : bt_navigator
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /navigate_to_pose/_action/feedback [nav2_msgs/action/NavigateToPose_FeedbackMessage]
publisher node          : bt_navigator
subscriber node         : rviz_navigation_dialog_action_client
compatibility status    : OK
topic [type]            : /navigate_to_pose/_action/feedback [nav2_msgs/action/NavigateToPose_FeedbackMessage]
publisher node          : bt_navigator
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /navigate_to_pose/_action/status [action_msgs/msg/GoalStatusArray]
publisher node          : bt_navigator
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /navigate_to_pose/_action/status [action_msgs/msg/GoalStatusArray]
publisher node          : bt_navigator
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /navigate_to_pose/_action/status [action_msgs/msg/GoalStatusArray]
publisher node          : bt_navigator
subscriber node         : rviz_navigation_dialog_action_client
compatibility status    : OK
topic [type]            : /navigate_to_pose/_action/status [action_msgs/msg/GoalStatusArray]
publisher node          : bt_navigator
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo
subscriber node         : gazebo
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo
subscriber node         : base_imu
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo
subscriber node         : base_laser
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo
subscriber node         : base_sonar_01_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo
subscriber node         : base_sonar_02_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo
subscriber node         : base_sonar_03_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo
subscriber node         : head_front_camera_frame_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo
subscriber node         : gazebo_ros_odometry
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo
subscriber node         : gazebo_ros2_control
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo
subscriber node         : controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo
subscriber node         : mobile_base_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo
subscriber node         : gripper_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo
subscriber node         : head_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo
subscriber node         : joint_state_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo
subscriber node         : imu_sensor_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo
subscriber node         : arm_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo
subscriber node         : torso_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo
subscriber node         : ft_sensor_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo
subscriber node         : local_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo
subscriber node         : transform_listener_impl_5973afb268b0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo
subscriber node         : transform_listener_impl_654ee1c865e0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo
subscriber node         : global_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo
subscriber node         : transform_listener_impl_623f34f20190
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo
subscriber node         : transform_listener_impl_5ec47a4d1ab0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo
subscriber node         : transform_listener_impl_5bdaab4440f0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo
subscriber node         : transform_listener_impl_61f2b5533050
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo
subscriber node         : rviz_navigation_dialog_action_client
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo
subscriber node         : transform_listener_impl_61f2b5c3f810
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo
subscriber node         : move_group
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo
subscriber node         : move_group_private_99865224190016
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo
subscriber node         : transform_listener_impl_5ad3af369c80
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo
subscriber node         : transform_listener_impl_5ad3afc309a0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo
subscriber node         : moveit_simple_controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo
subscriber node         : play_motion2
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo
subscriber node         : _move_group_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo
subscriber node         : twist_mux
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo
subscriber node         : twist_marker
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_imu
subscriber node         : gazebo
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_imu
subscriber node         : base_imu
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_imu
subscriber node         : base_laser
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_imu
subscriber node         : base_sonar_01_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_imu
subscriber node         : base_sonar_02_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_imu
subscriber node         : base_sonar_03_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_imu
subscriber node         : head_front_camera_frame_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_imu
subscriber node         : gazebo_ros_odometry
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_imu
subscriber node         : gazebo_ros2_control
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_imu
subscriber node         : controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_imu
subscriber node         : mobile_base_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_imu
subscriber node         : gripper_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_imu
subscriber node         : head_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_imu
subscriber node         : joint_state_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_imu
subscriber node         : imu_sensor_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_imu
subscriber node         : arm_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_imu
subscriber node         : torso_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_imu
subscriber node         : ft_sensor_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_imu
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_imu
subscriber node         : local_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_imu
subscriber node         : transform_listener_impl_5973afb268b0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_imu
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_imu
subscriber node         : transform_listener_impl_654ee1c865e0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_imu
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_imu
subscriber node         : global_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_imu
subscriber node         : transform_listener_impl_623f34f20190
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_imu
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_imu
subscriber node         : transform_listener_impl_5ec47a4d1ab0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_imu
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_imu
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_imu
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_imu
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_imu
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_imu
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_imu
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_imu
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_imu
subscriber node         : transform_listener_impl_5bdaab4440f0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_imu
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_imu
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_imu
subscriber node         : transform_listener_impl_61f2b5533050
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_imu
subscriber node         : rviz_navigation_dialog_action_client
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_imu
subscriber node         : transform_listener_impl_61f2b5c3f810
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_imu
subscriber node         : move_group
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_imu
subscriber node         : move_group_private_99865224190016
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_imu
subscriber node         : transform_listener_impl_5ad3af369c80
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_imu
subscriber node         : transform_listener_impl_5ad3afc309a0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_imu
subscriber node         : moveit_simple_controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_imu
subscriber node         : play_motion2
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_imu
subscriber node         : _move_group_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_imu
subscriber node         : twist_mux
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_imu
subscriber node         : twist_marker
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_imu
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_imu
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_laser
subscriber node         : gazebo
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_laser
subscriber node         : base_imu
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_laser
subscriber node         : base_laser
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_laser
subscriber node         : base_sonar_01_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_laser
subscriber node         : base_sonar_02_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_laser
subscriber node         : base_sonar_03_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_laser
subscriber node         : head_front_camera_frame_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_laser
subscriber node         : gazebo_ros_odometry
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_laser
subscriber node         : gazebo_ros2_control
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_laser
subscriber node         : controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_laser
subscriber node         : mobile_base_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_laser
subscriber node         : gripper_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_laser
subscriber node         : head_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_laser
subscriber node         : joint_state_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_laser
subscriber node         : imu_sensor_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_laser
subscriber node         : arm_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_laser
subscriber node         : torso_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_laser
subscriber node         : ft_sensor_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_laser
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_laser
subscriber node         : local_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_laser
subscriber node         : transform_listener_impl_5973afb268b0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_laser
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_laser
subscriber node         : transform_listener_impl_654ee1c865e0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_laser
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_laser
subscriber node         : global_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_laser
subscriber node         : transform_listener_impl_623f34f20190
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_laser
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_laser
subscriber node         : transform_listener_impl_5ec47a4d1ab0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_laser
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_laser
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_laser
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_laser
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_laser
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_laser
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_laser
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_laser
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_laser
subscriber node         : transform_listener_impl_5bdaab4440f0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_laser
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_laser
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_laser
subscriber node         : transform_listener_impl_61f2b5533050
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_laser
subscriber node         : rviz_navigation_dialog_action_client
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_laser
subscriber node         : transform_listener_impl_61f2b5c3f810
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_laser
subscriber node         : move_group
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_laser
subscriber node         : move_group_private_99865224190016
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_laser
subscriber node         : transform_listener_impl_5ad3af369c80
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_laser
subscriber node         : transform_listener_impl_5ad3afc309a0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_laser
subscriber node         : moveit_simple_controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_laser
subscriber node         : play_motion2
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_laser
subscriber node         : _move_group_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_laser
subscriber node         : twist_mux
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_laser
subscriber node         : twist_marker
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_laser
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_laser
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_01_gazebo_ros_range
subscriber node         : gazebo
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_01_gazebo_ros_range
subscriber node         : base_imu
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_01_gazebo_ros_range
subscriber node         : base_laser
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_01_gazebo_ros_range
subscriber node         : base_sonar_01_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_01_gazebo_ros_range
subscriber node         : base_sonar_02_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_01_gazebo_ros_range
subscriber node         : base_sonar_03_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_01_gazebo_ros_range
subscriber node         : head_front_camera_frame_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_01_gazebo_ros_range
subscriber node         : gazebo_ros_odometry
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_01_gazebo_ros_range
subscriber node         : gazebo_ros2_control
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_01_gazebo_ros_range
subscriber node         : controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_01_gazebo_ros_range
subscriber node         : mobile_base_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_01_gazebo_ros_range
subscriber node         : gripper_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_01_gazebo_ros_range
subscriber node         : head_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_01_gazebo_ros_range
subscriber node         : joint_state_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_01_gazebo_ros_range
subscriber node         : imu_sensor_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_01_gazebo_ros_range
subscriber node         : arm_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_01_gazebo_ros_range
subscriber node         : torso_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_01_gazebo_ros_range
subscriber node         : ft_sensor_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_01_gazebo_ros_range
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_01_gazebo_ros_range
subscriber node         : local_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_01_gazebo_ros_range
subscriber node         : transform_listener_impl_5973afb268b0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_01_gazebo_ros_range
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_01_gazebo_ros_range
subscriber node         : transform_listener_impl_654ee1c865e0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_01_gazebo_ros_range
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_01_gazebo_ros_range
subscriber node         : global_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_01_gazebo_ros_range
subscriber node         : transform_listener_impl_623f34f20190
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_01_gazebo_ros_range
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_01_gazebo_ros_range
subscriber node         : transform_listener_impl_5ec47a4d1ab0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_01_gazebo_ros_range
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_01_gazebo_ros_range
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_01_gazebo_ros_range
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_01_gazebo_ros_range
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_01_gazebo_ros_range
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_01_gazebo_ros_range
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_01_gazebo_ros_range
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_01_gazebo_ros_range
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_01_gazebo_ros_range
subscriber node         : transform_listener_impl_5bdaab4440f0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_01_gazebo_ros_range
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_01_gazebo_ros_range
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_01_gazebo_ros_range
subscriber node         : transform_listener_impl_61f2b5533050
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_01_gazebo_ros_range
subscriber node         : rviz_navigation_dialog_action_client
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_01_gazebo_ros_range
subscriber node         : transform_listener_impl_61f2b5c3f810
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_01_gazebo_ros_range
subscriber node         : move_group
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_01_gazebo_ros_range
subscriber node         : move_group_private_99865224190016
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_01_gazebo_ros_range
subscriber node         : transform_listener_impl_5ad3af369c80
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_01_gazebo_ros_range
subscriber node         : transform_listener_impl_5ad3afc309a0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_01_gazebo_ros_range
subscriber node         : moveit_simple_controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_01_gazebo_ros_range
subscriber node         : play_motion2
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_01_gazebo_ros_range
subscriber node         : _move_group_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_01_gazebo_ros_range
subscriber node         : twist_mux
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_01_gazebo_ros_range
subscriber node         : twist_marker
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_01_gazebo_ros_range
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_01_gazebo_ros_range
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_02_gazebo_ros_range
subscriber node         : gazebo
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_02_gazebo_ros_range
subscriber node         : base_imu
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_02_gazebo_ros_range
subscriber node         : base_laser
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_02_gazebo_ros_range
subscriber node         : base_sonar_01_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_02_gazebo_ros_range
subscriber node         : base_sonar_02_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_02_gazebo_ros_range
subscriber node         : base_sonar_03_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_02_gazebo_ros_range
subscriber node         : head_front_camera_frame_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_02_gazebo_ros_range
subscriber node         : gazebo_ros_odometry
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_02_gazebo_ros_range
subscriber node         : gazebo_ros2_control
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_02_gazebo_ros_range
subscriber node         : controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_02_gazebo_ros_range
subscriber node         : mobile_base_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_02_gazebo_ros_range
subscriber node         : gripper_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_02_gazebo_ros_range
subscriber node         : head_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_02_gazebo_ros_range
subscriber node         : joint_state_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_02_gazebo_ros_range
subscriber node         : imu_sensor_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_02_gazebo_ros_range
subscriber node         : arm_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_02_gazebo_ros_range
subscriber node         : torso_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_02_gazebo_ros_range
subscriber node         : ft_sensor_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_02_gazebo_ros_range
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_02_gazebo_ros_range
subscriber node         : local_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_02_gazebo_ros_range
subscriber node         : transform_listener_impl_5973afb268b0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_02_gazebo_ros_range
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_02_gazebo_ros_range
subscriber node         : transform_listener_impl_654ee1c865e0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_02_gazebo_ros_range
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_02_gazebo_ros_range
subscriber node         : global_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_02_gazebo_ros_range
subscriber node         : transform_listener_impl_623f34f20190
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_02_gazebo_ros_range
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_02_gazebo_ros_range
subscriber node         : transform_listener_impl_5ec47a4d1ab0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_02_gazebo_ros_range
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_02_gazebo_ros_range
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_02_gazebo_ros_range
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_02_gazebo_ros_range
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_02_gazebo_ros_range
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_02_gazebo_ros_range
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_02_gazebo_ros_range
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_02_gazebo_ros_range
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_02_gazebo_ros_range
subscriber node         : transform_listener_impl_5bdaab4440f0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_02_gazebo_ros_range
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_02_gazebo_ros_range
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_02_gazebo_ros_range
subscriber node         : transform_listener_impl_61f2b5533050
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_02_gazebo_ros_range
subscriber node         : rviz_navigation_dialog_action_client
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_02_gazebo_ros_range
subscriber node         : transform_listener_impl_61f2b5c3f810
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_02_gazebo_ros_range
subscriber node         : move_group
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_02_gazebo_ros_range
subscriber node         : move_group_private_99865224190016
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_02_gazebo_ros_range
subscriber node         : transform_listener_impl_5ad3af369c80
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_02_gazebo_ros_range
subscriber node         : transform_listener_impl_5ad3afc309a0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_02_gazebo_ros_range
subscriber node         : moveit_simple_controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_02_gazebo_ros_range
subscriber node         : play_motion2
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_02_gazebo_ros_range
subscriber node         : _move_group_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_02_gazebo_ros_range
subscriber node         : twist_mux
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_02_gazebo_ros_range
subscriber node         : twist_marker
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_02_gazebo_ros_range
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_02_gazebo_ros_range
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_03_gazebo_ros_range
subscriber node         : gazebo
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_03_gazebo_ros_range
subscriber node         : base_imu
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_03_gazebo_ros_range
subscriber node         : base_laser
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_03_gazebo_ros_range
subscriber node         : base_sonar_01_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_03_gazebo_ros_range
subscriber node         : base_sonar_02_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_03_gazebo_ros_range
subscriber node         : base_sonar_03_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_03_gazebo_ros_range
subscriber node         : head_front_camera_frame_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_03_gazebo_ros_range
subscriber node         : gazebo_ros_odometry
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_03_gazebo_ros_range
subscriber node         : gazebo_ros2_control
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_03_gazebo_ros_range
subscriber node         : controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_03_gazebo_ros_range
subscriber node         : mobile_base_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_03_gazebo_ros_range
subscriber node         : gripper_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_03_gazebo_ros_range
subscriber node         : head_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_03_gazebo_ros_range
subscriber node         : joint_state_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_03_gazebo_ros_range
subscriber node         : imu_sensor_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_03_gazebo_ros_range
subscriber node         : arm_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_03_gazebo_ros_range
subscriber node         : torso_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_03_gazebo_ros_range
subscriber node         : ft_sensor_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_03_gazebo_ros_range
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_03_gazebo_ros_range
subscriber node         : local_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_03_gazebo_ros_range
subscriber node         : transform_listener_impl_5973afb268b0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_03_gazebo_ros_range
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_03_gazebo_ros_range
subscriber node         : transform_listener_impl_654ee1c865e0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_03_gazebo_ros_range
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_03_gazebo_ros_range
subscriber node         : global_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_03_gazebo_ros_range
subscriber node         : transform_listener_impl_623f34f20190
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_03_gazebo_ros_range
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_03_gazebo_ros_range
subscriber node         : transform_listener_impl_5ec47a4d1ab0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_03_gazebo_ros_range
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_03_gazebo_ros_range
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_03_gazebo_ros_range
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_03_gazebo_ros_range
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_03_gazebo_ros_range
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_03_gazebo_ros_range
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_03_gazebo_ros_range
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_03_gazebo_ros_range
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_03_gazebo_ros_range
subscriber node         : transform_listener_impl_5bdaab4440f0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_03_gazebo_ros_range
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_03_gazebo_ros_range
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_03_gazebo_ros_range
subscriber node         : transform_listener_impl_61f2b5533050
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_03_gazebo_ros_range
subscriber node         : rviz_navigation_dialog_action_client
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_03_gazebo_ros_range
subscriber node         : transform_listener_impl_61f2b5c3f810
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_03_gazebo_ros_range
subscriber node         : move_group
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_03_gazebo_ros_range
subscriber node         : move_group_private_99865224190016
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_03_gazebo_ros_range
subscriber node         : transform_listener_impl_5ad3af369c80
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_03_gazebo_ros_range
subscriber node         : transform_listener_impl_5ad3afc309a0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_03_gazebo_ros_range
subscriber node         : moveit_simple_controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_03_gazebo_ros_range
subscriber node         : play_motion2
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_03_gazebo_ros_range
subscriber node         : _move_group_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_03_gazebo_ros_range
subscriber node         : twist_mux
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_03_gazebo_ros_range
subscriber node         : twist_marker
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_03_gazebo_ros_range
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : base_sonar_03_gazebo_ros_range
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_front_camera_frame_controller
subscriber node         : gazebo
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_front_camera_frame_controller
subscriber node         : base_imu
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_front_camera_frame_controller
subscriber node         : base_laser
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_front_camera_frame_controller
subscriber node         : base_sonar_01_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_front_camera_frame_controller
subscriber node         : base_sonar_02_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_front_camera_frame_controller
subscriber node         : base_sonar_03_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_front_camera_frame_controller
subscriber node         : head_front_camera_frame_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_front_camera_frame_controller
subscriber node         : gazebo_ros_odometry
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_front_camera_frame_controller
subscriber node         : gazebo_ros2_control
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_front_camera_frame_controller
subscriber node         : controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_front_camera_frame_controller
subscriber node         : mobile_base_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_front_camera_frame_controller
subscriber node         : gripper_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_front_camera_frame_controller
subscriber node         : head_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_front_camera_frame_controller
subscriber node         : joint_state_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_front_camera_frame_controller
subscriber node         : imu_sensor_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_front_camera_frame_controller
subscriber node         : arm_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_front_camera_frame_controller
subscriber node         : torso_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_front_camera_frame_controller
subscriber node         : ft_sensor_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_front_camera_frame_controller
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_front_camera_frame_controller
subscriber node         : local_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_front_camera_frame_controller
subscriber node         : transform_listener_impl_5973afb268b0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_front_camera_frame_controller
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_front_camera_frame_controller
subscriber node         : transform_listener_impl_654ee1c865e0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_front_camera_frame_controller
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_front_camera_frame_controller
subscriber node         : global_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_front_camera_frame_controller
subscriber node         : transform_listener_impl_623f34f20190
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_front_camera_frame_controller
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_front_camera_frame_controller
subscriber node         : transform_listener_impl_5ec47a4d1ab0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_front_camera_frame_controller
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_front_camera_frame_controller
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_front_camera_frame_controller
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_front_camera_frame_controller
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_front_camera_frame_controller
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_front_camera_frame_controller
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_front_camera_frame_controller
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_front_camera_frame_controller
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_front_camera_frame_controller
subscriber node         : transform_listener_impl_5bdaab4440f0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_front_camera_frame_controller
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_front_camera_frame_controller
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_front_camera_frame_controller
subscriber node         : transform_listener_impl_61f2b5533050
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_front_camera_frame_controller
subscriber node         : rviz_navigation_dialog_action_client
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_front_camera_frame_controller
subscriber node         : transform_listener_impl_61f2b5c3f810
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_front_camera_frame_controller
subscriber node         : move_group
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_front_camera_frame_controller
subscriber node         : move_group_private_99865224190016
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_front_camera_frame_controller
subscriber node         : transform_listener_impl_5ad3af369c80
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_front_camera_frame_controller
subscriber node         : transform_listener_impl_5ad3afc309a0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_front_camera_frame_controller
subscriber node         : moveit_simple_controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_front_camera_frame_controller
subscriber node         : play_motion2
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_front_camera_frame_controller
subscriber node         : _move_group_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_front_camera_frame_controller
subscriber node         : twist_mux
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_front_camera_frame_controller
subscriber node         : twist_marker
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_front_camera_frame_controller
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_front_camera_frame_controller
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros_odometry
subscriber node         : gazebo
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros_odometry
subscriber node         : base_imu
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros_odometry
subscriber node         : base_laser
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros_odometry
subscriber node         : base_sonar_01_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros_odometry
subscriber node         : base_sonar_02_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros_odometry
subscriber node         : base_sonar_03_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros_odometry
subscriber node         : head_front_camera_frame_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros_odometry
subscriber node         : gazebo_ros_odometry
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros_odometry
subscriber node         : gazebo_ros2_control
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros_odometry
subscriber node         : controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros_odometry
subscriber node         : mobile_base_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros_odometry
subscriber node         : gripper_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros_odometry
subscriber node         : head_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros_odometry
subscriber node         : joint_state_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros_odometry
subscriber node         : imu_sensor_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros_odometry
subscriber node         : arm_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros_odometry
subscriber node         : torso_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros_odometry
subscriber node         : ft_sensor_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros_odometry
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros_odometry
subscriber node         : local_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros_odometry
subscriber node         : transform_listener_impl_5973afb268b0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros_odometry
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros_odometry
subscriber node         : transform_listener_impl_654ee1c865e0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros_odometry
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros_odometry
subscriber node         : global_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros_odometry
subscriber node         : transform_listener_impl_623f34f20190
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros_odometry
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros_odometry
subscriber node         : transform_listener_impl_5ec47a4d1ab0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros_odometry
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros_odometry
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros_odometry
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros_odometry
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros_odometry
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros_odometry
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros_odometry
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros_odometry
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros_odometry
subscriber node         : transform_listener_impl_5bdaab4440f0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros_odometry
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros_odometry
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros_odometry
subscriber node         : transform_listener_impl_61f2b5533050
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros_odometry
subscriber node         : rviz_navigation_dialog_action_client
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros_odometry
subscriber node         : transform_listener_impl_61f2b5c3f810
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros_odometry
subscriber node         : move_group
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros_odometry
subscriber node         : move_group_private_99865224190016
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros_odometry
subscriber node         : transform_listener_impl_5ad3af369c80
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros_odometry
subscriber node         : transform_listener_impl_5ad3afc309a0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros_odometry
subscriber node         : moveit_simple_controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros_odometry
subscriber node         : play_motion2
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros_odometry
subscriber node         : _move_group_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros_odometry
subscriber node         : twist_mux
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros_odometry
subscriber node         : twist_marker
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros_odometry
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros_odometry
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros2_control
subscriber node         : gazebo
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros2_control
subscriber node         : base_imu
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros2_control
subscriber node         : base_laser
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros2_control
subscriber node         : base_sonar_01_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros2_control
subscriber node         : base_sonar_02_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros2_control
subscriber node         : base_sonar_03_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros2_control
subscriber node         : head_front_camera_frame_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros2_control
subscriber node         : gazebo_ros_odometry
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros2_control
subscriber node         : gazebo_ros2_control
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros2_control
subscriber node         : controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros2_control
subscriber node         : mobile_base_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros2_control
subscriber node         : gripper_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros2_control
subscriber node         : head_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros2_control
subscriber node         : joint_state_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros2_control
subscriber node         : imu_sensor_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros2_control
subscriber node         : arm_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros2_control
subscriber node         : torso_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros2_control
subscriber node         : ft_sensor_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros2_control
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros2_control
subscriber node         : local_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros2_control
subscriber node         : transform_listener_impl_5973afb268b0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros2_control
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros2_control
subscriber node         : transform_listener_impl_654ee1c865e0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros2_control
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros2_control
subscriber node         : global_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros2_control
subscriber node         : transform_listener_impl_623f34f20190
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros2_control
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros2_control
subscriber node         : transform_listener_impl_5ec47a4d1ab0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros2_control
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros2_control
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros2_control
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros2_control
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros2_control
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros2_control
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros2_control
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros2_control
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros2_control
subscriber node         : transform_listener_impl_5bdaab4440f0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros2_control
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros2_control
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros2_control
subscriber node         : transform_listener_impl_61f2b5533050
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros2_control
subscriber node         : rviz_navigation_dialog_action_client
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros2_control
subscriber node         : transform_listener_impl_61f2b5c3f810
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros2_control
subscriber node         : move_group
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros2_control
subscriber node         : move_group_private_99865224190016
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros2_control
subscriber node         : transform_listener_impl_5ad3af369c80
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros2_control
subscriber node         : transform_listener_impl_5ad3afc309a0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros2_control
subscriber node         : moveit_simple_controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros2_control
subscriber node         : play_motion2
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros2_control
subscriber node         : _move_group_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros2_control
subscriber node         : twist_mux
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros2_control
subscriber node         : twist_marker
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros2_control
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gazebo_ros2_control
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_manager
subscriber node         : gazebo
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_manager
subscriber node         : base_imu
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_manager
subscriber node         : base_laser
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_manager
subscriber node         : base_sonar_01_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_manager
subscriber node         : base_sonar_02_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_manager
subscriber node         : base_sonar_03_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_manager
subscriber node         : head_front_camera_frame_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_manager
subscriber node         : gazebo_ros_odometry
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_manager
subscriber node         : gazebo_ros2_control
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_manager
subscriber node         : controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_manager
subscriber node         : mobile_base_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_manager
subscriber node         : gripper_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_manager
subscriber node         : head_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_manager
subscriber node         : joint_state_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_manager
subscriber node         : imu_sensor_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_manager
subscriber node         : arm_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_manager
subscriber node         : torso_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_manager
subscriber node         : ft_sensor_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_manager
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_manager
subscriber node         : local_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_manager
subscriber node         : transform_listener_impl_5973afb268b0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_manager
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_manager
subscriber node         : transform_listener_impl_654ee1c865e0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_manager
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_manager
subscriber node         : global_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_manager
subscriber node         : transform_listener_impl_623f34f20190
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_manager
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_manager
subscriber node         : transform_listener_impl_5ec47a4d1ab0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_manager
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_manager
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_manager
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_manager
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_manager
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_manager
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_manager
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_manager
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_manager
subscriber node         : transform_listener_impl_5bdaab4440f0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_manager
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_manager
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_manager
subscriber node         : transform_listener_impl_61f2b5533050
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_manager
subscriber node         : rviz_navigation_dialog_action_client
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_manager
subscriber node         : transform_listener_impl_61f2b5c3f810
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_manager
subscriber node         : move_group
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_manager
subscriber node         : move_group_private_99865224190016
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_manager
subscriber node         : transform_listener_impl_5ad3af369c80
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_manager
subscriber node         : transform_listener_impl_5ad3afc309a0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_manager
subscriber node         : moveit_simple_controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_manager
subscriber node         : play_motion2
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_manager
subscriber node         : _move_group_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_manager
subscriber node         : twist_mux
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_manager
subscriber node         : twist_marker
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_manager
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_manager
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : mobile_base_controller
subscriber node         : gazebo
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : mobile_base_controller
subscriber node         : base_imu
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : mobile_base_controller
subscriber node         : base_laser
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : mobile_base_controller
subscriber node         : base_sonar_01_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : mobile_base_controller
subscriber node         : base_sonar_02_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : mobile_base_controller
subscriber node         : base_sonar_03_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : mobile_base_controller
subscriber node         : head_front_camera_frame_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : mobile_base_controller
subscriber node         : gazebo_ros_odometry
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : mobile_base_controller
subscriber node         : gazebo_ros2_control
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : mobile_base_controller
subscriber node         : controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : mobile_base_controller
subscriber node         : mobile_base_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : mobile_base_controller
subscriber node         : gripper_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : mobile_base_controller
subscriber node         : head_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : mobile_base_controller
subscriber node         : joint_state_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : mobile_base_controller
subscriber node         : imu_sensor_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : mobile_base_controller
subscriber node         : arm_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : mobile_base_controller
subscriber node         : torso_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : mobile_base_controller
subscriber node         : ft_sensor_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : mobile_base_controller
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : mobile_base_controller
subscriber node         : local_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : mobile_base_controller
subscriber node         : transform_listener_impl_5973afb268b0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : mobile_base_controller
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : mobile_base_controller
subscriber node         : transform_listener_impl_654ee1c865e0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : mobile_base_controller
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : mobile_base_controller
subscriber node         : global_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : mobile_base_controller
subscriber node         : transform_listener_impl_623f34f20190
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : mobile_base_controller
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : mobile_base_controller
subscriber node         : transform_listener_impl_5ec47a4d1ab0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : mobile_base_controller
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : mobile_base_controller
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : mobile_base_controller
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : mobile_base_controller
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : mobile_base_controller
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : mobile_base_controller
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : mobile_base_controller
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : mobile_base_controller
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : mobile_base_controller
subscriber node         : transform_listener_impl_5bdaab4440f0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : mobile_base_controller
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : mobile_base_controller
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : mobile_base_controller
subscriber node         : transform_listener_impl_61f2b5533050
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : mobile_base_controller
subscriber node         : rviz_navigation_dialog_action_client
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : mobile_base_controller
subscriber node         : transform_listener_impl_61f2b5c3f810
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : mobile_base_controller
subscriber node         : move_group
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : mobile_base_controller
subscriber node         : move_group_private_99865224190016
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : mobile_base_controller
subscriber node         : transform_listener_impl_5ad3af369c80
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : mobile_base_controller
subscriber node         : transform_listener_impl_5ad3afc309a0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : mobile_base_controller
subscriber node         : moveit_simple_controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : mobile_base_controller
subscriber node         : play_motion2
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : mobile_base_controller
subscriber node         : _move_group_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : mobile_base_controller
subscriber node         : twist_mux
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : mobile_base_controller
subscriber node         : twist_marker
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : mobile_base_controller
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : mobile_base_controller
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gripper_controller
subscriber node         : gazebo
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gripper_controller
subscriber node         : base_imu
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gripper_controller
subscriber node         : base_laser
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gripper_controller
subscriber node         : base_sonar_01_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gripper_controller
subscriber node         : base_sonar_02_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gripper_controller
subscriber node         : base_sonar_03_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gripper_controller
subscriber node         : head_front_camera_frame_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gripper_controller
subscriber node         : gazebo_ros_odometry
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gripper_controller
subscriber node         : gazebo_ros2_control
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gripper_controller
subscriber node         : controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gripper_controller
subscriber node         : mobile_base_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gripper_controller
subscriber node         : gripper_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gripper_controller
subscriber node         : head_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gripper_controller
subscriber node         : joint_state_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gripper_controller
subscriber node         : imu_sensor_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gripper_controller
subscriber node         : arm_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gripper_controller
subscriber node         : torso_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gripper_controller
subscriber node         : ft_sensor_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gripper_controller
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gripper_controller
subscriber node         : local_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gripper_controller
subscriber node         : transform_listener_impl_5973afb268b0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gripper_controller
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gripper_controller
subscriber node         : transform_listener_impl_654ee1c865e0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gripper_controller
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gripper_controller
subscriber node         : global_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gripper_controller
subscriber node         : transform_listener_impl_623f34f20190
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gripper_controller
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gripper_controller
subscriber node         : transform_listener_impl_5ec47a4d1ab0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gripper_controller
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gripper_controller
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gripper_controller
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gripper_controller
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gripper_controller
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gripper_controller
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gripper_controller
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gripper_controller
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gripper_controller
subscriber node         : transform_listener_impl_5bdaab4440f0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gripper_controller
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gripper_controller
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gripper_controller
subscriber node         : transform_listener_impl_61f2b5533050
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gripper_controller
subscriber node         : rviz_navigation_dialog_action_client
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gripper_controller
subscriber node         : transform_listener_impl_61f2b5c3f810
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gripper_controller
subscriber node         : move_group
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gripper_controller
subscriber node         : move_group_private_99865224190016
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gripper_controller
subscriber node         : transform_listener_impl_5ad3af369c80
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gripper_controller
subscriber node         : transform_listener_impl_5ad3afc309a0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gripper_controller
subscriber node         : moveit_simple_controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gripper_controller
subscriber node         : play_motion2
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gripper_controller
subscriber node         : _move_group_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gripper_controller
subscriber node         : twist_mux
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gripper_controller
subscriber node         : twist_marker
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gripper_controller
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : gripper_controller
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_controller
subscriber node         : gazebo
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_controller
subscriber node         : base_imu
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_controller
subscriber node         : base_laser
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_controller
subscriber node         : base_sonar_01_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_controller
subscriber node         : base_sonar_02_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_controller
subscriber node         : base_sonar_03_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_controller
subscriber node         : head_front_camera_frame_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_controller
subscriber node         : gazebo_ros_odometry
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_controller
subscriber node         : gazebo_ros2_control
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_controller
subscriber node         : controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_controller
subscriber node         : mobile_base_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_controller
subscriber node         : gripper_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_controller
subscriber node         : head_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_controller
subscriber node         : joint_state_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_controller
subscriber node         : imu_sensor_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_controller
subscriber node         : arm_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_controller
subscriber node         : torso_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_controller
subscriber node         : ft_sensor_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_controller
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_controller
subscriber node         : local_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_controller
subscriber node         : transform_listener_impl_5973afb268b0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_controller
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_controller
subscriber node         : transform_listener_impl_654ee1c865e0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_controller
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_controller
subscriber node         : global_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_controller
subscriber node         : transform_listener_impl_623f34f20190
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_controller
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_controller
subscriber node         : transform_listener_impl_5ec47a4d1ab0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_controller
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_controller
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_controller
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_controller
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_controller
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_controller
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_controller
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_controller
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_controller
subscriber node         : transform_listener_impl_5bdaab4440f0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_controller
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_controller
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_controller
subscriber node         : transform_listener_impl_61f2b5533050
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_controller
subscriber node         : rviz_navigation_dialog_action_client
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_controller
subscriber node         : transform_listener_impl_61f2b5c3f810
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_controller
subscriber node         : move_group
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_controller
subscriber node         : move_group_private_99865224190016
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_controller
subscriber node         : transform_listener_impl_5ad3af369c80
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_controller
subscriber node         : transform_listener_impl_5ad3afc309a0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_controller
subscriber node         : moveit_simple_controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_controller
subscriber node         : play_motion2
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_controller
subscriber node         : _move_group_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_controller
subscriber node         : twist_mux
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_controller
subscriber node         : twist_marker
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_controller
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : head_controller
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joint_state_broadcaster
subscriber node         : gazebo
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joint_state_broadcaster
subscriber node         : base_imu
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joint_state_broadcaster
subscriber node         : base_laser
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joint_state_broadcaster
subscriber node         : base_sonar_01_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joint_state_broadcaster
subscriber node         : base_sonar_02_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joint_state_broadcaster
subscriber node         : base_sonar_03_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joint_state_broadcaster
subscriber node         : head_front_camera_frame_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joint_state_broadcaster
subscriber node         : gazebo_ros_odometry
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joint_state_broadcaster
subscriber node         : gazebo_ros2_control
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joint_state_broadcaster
subscriber node         : controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joint_state_broadcaster
subscriber node         : mobile_base_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joint_state_broadcaster
subscriber node         : gripper_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joint_state_broadcaster
subscriber node         : head_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joint_state_broadcaster
subscriber node         : joint_state_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joint_state_broadcaster
subscriber node         : imu_sensor_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joint_state_broadcaster
subscriber node         : arm_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joint_state_broadcaster
subscriber node         : torso_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joint_state_broadcaster
subscriber node         : ft_sensor_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joint_state_broadcaster
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joint_state_broadcaster
subscriber node         : local_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joint_state_broadcaster
subscriber node         : transform_listener_impl_5973afb268b0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joint_state_broadcaster
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joint_state_broadcaster
subscriber node         : transform_listener_impl_654ee1c865e0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joint_state_broadcaster
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joint_state_broadcaster
subscriber node         : global_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joint_state_broadcaster
subscriber node         : transform_listener_impl_623f34f20190
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joint_state_broadcaster
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joint_state_broadcaster
subscriber node         : transform_listener_impl_5ec47a4d1ab0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joint_state_broadcaster
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joint_state_broadcaster
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joint_state_broadcaster
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joint_state_broadcaster
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joint_state_broadcaster
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joint_state_broadcaster
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joint_state_broadcaster
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joint_state_broadcaster
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joint_state_broadcaster
subscriber node         : transform_listener_impl_5bdaab4440f0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joint_state_broadcaster
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joint_state_broadcaster
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joint_state_broadcaster
subscriber node         : transform_listener_impl_61f2b5533050
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joint_state_broadcaster
subscriber node         : rviz_navigation_dialog_action_client
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joint_state_broadcaster
subscriber node         : transform_listener_impl_61f2b5c3f810
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joint_state_broadcaster
subscriber node         : move_group
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joint_state_broadcaster
subscriber node         : move_group_private_99865224190016
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joint_state_broadcaster
subscriber node         : transform_listener_impl_5ad3af369c80
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joint_state_broadcaster
subscriber node         : transform_listener_impl_5ad3afc309a0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joint_state_broadcaster
subscriber node         : moveit_simple_controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joint_state_broadcaster
subscriber node         : play_motion2
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joint_state_broadcaster
subscriber node         : _move_group_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joint_state_broadcaster
subscriber node         : twist_mux
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joint_state_broadcaster
subscriber node         : twist_marker
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joint_state_broadcaster
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joint_state_broadcaster
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : imu_sensor_broadcaster
subscriber node         : gazebo
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : imu_sensor_broadcaster
subscriber node         : base_imu
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : imu_sensor_broadcaster
subscriber node         : base_laser
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : imu_sensor_broadcaster
subscriber node         : base_sonar_01_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : imu_sensor_broadcaster
subscriber node         : base_sonar_02_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : imu_sensor_broadcaster
subscriber node         : base_sonar_03_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : imu_sensor_broadcaster
subscriber node         : head_front_camera_frame_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : imu_sensor_broadcaster
subscriber node         : gazebo_ros_odometry
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : imu_sensor_broadcaster
subscriber node         : gazebo_ros2_control
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : imu_sensor_broadcaster
subscriber node         : controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : imu_sensor_broadcaster
subscriber node         : mobile_base_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : imu_sensor_broadcaster
subscriber node         : gripper_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : imu_sensor_broadcaster
subscriber node         : head_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : imu_sensor_broadcaster
subscriber node         : joint_state_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : imu_sensor_broadcaster
subscriber node         : imu_sensor_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : imu_sensor_broadcaster
subscriber node         : arm_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : imu_sensor_broadcaster
subscriber node         : torso_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : imu_sensor_broadcaster
subscriber node         : ft_sensor_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : imu_sensor_broadcaster
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : imu_sensor_broadcaster
subscriber node         : local_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : imu_sensor_broadcaster
subscriber node         : transform_listener_impl_5973afb268b0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : imu_sensor_broadcaster
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : imu_sensor_broadcaster
subscriber node         : transform_listener_impl_654ee1c865e0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : imu_sensor_broadcaster
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : imu_sensor_broadcaster
subscriber node         : global_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : imu_sensor_broadcaster
subscriber node         : transform_listener_impl_623f34f20190
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : imu_sensor_broadcaster
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : imu_sensor_broadcaster
subscriber node         : transform_listener_impl_5ec47a4d1ab0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : imu_sensor_broadcaster
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : imu_sensor_broadcaster
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : imu_sensor_broadcaster
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : imu_sensor_broadcaster
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : imu_sensor_broadcaster
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : imu_sensor_broadcaster
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : imu_sensor_broadcaster
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : imu_sensor_broadcaster
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : imu_sensor_broadcaster
subscriber node         : transform_listener_impl_5bdaab4440f0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : imu_sensor_broadcaster
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : imu_sensor_broadcaster
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : imu_sensor_broadcaster
subscriber node         : transform_listener_impl_61f2b5533050
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : imu_sensor_broadcaster
subscriber node         : rviz_navigation_dialog_action_client
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : imu_sensor_broadcaster
subscriber node         : transform_listener_impl_61f2b5c3f810
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : imu_sensor_broadcaster
subscriber node         : move_group
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : imu_sensor_broadcaster
subscriber node         : move_group_private_99865224190016
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : imu_sensor_broadcaster
subscriber node         : transform_listener_impl_5ad3af369c80
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : imu_sensor_broadcaster
subscriber node         : transform_listener_impl_5ad3afc309a0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : imu_sensor_broadcaster
subscriber node         : moveit_simple_controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : imu_sensor_broadcaster
subscriber node         : play_motion2
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : imu_sensor_broadcaster
subscriber node         : _move_group_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : imu_sensor_broadcaster
subscriber node         : twist_mux
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : imu_sensor_broadcaster
subscriber node         : twist_marker
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : imu_sensor_broadcaster
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : imu_sensor_broadcaster
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : arm_controller
subscriber node         : gazebo
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : arm_controller
subscriber node         : base_imu
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : arm_controller
subscriber node         : base_laser
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : arm_controller
subscriber node         : base_sonar_01_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : arm_controller
subscriber node         : base_sonar_02_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : arm_controller
subscriber node         : base_sonar_03_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : arm_controller
subscriber node         : head_front_camera_frame_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : arm_controller
subscriber node         : gazebo_ros_odometry
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : arm_controller
subscriber node         : gazebo_ros2_control
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : arm_controller
subscriber node         : controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : arm_controller
subscriber node         : mobile_base_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : arm_controller
subscriber node         : gripper_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : arm_controller
subscriber node         : head_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : arm_controller
subscriber node         : joint_state_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : arm_controller
subscriber node         : imu_sensor_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : arm_controller
subscriber node         : arm_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : arm_controller
subscriber node         : torso_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : arm_controller
subscriber node         : ft_sensor_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : arm_controller
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : arm_controller
subscriber node         : local_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : arm_controller
subscriber node         : transform_listener_impl_5973afb268b0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : arm_controller
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : arm_controller
subscriber node         : transform_listener_impl_654ee1c865e0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : arm_controller
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : arm_controller
subscriber node         : global_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : arm_controller
subscriber node         : transform_listener_impl_623f34f20190
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : arm_controller
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : arm_controller
subscriber node         : transform_listener_impl_5ec47a4d1ab0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : arm_controller
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : arm_controller
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : arm_controller
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : arm_controller
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : arm_controller
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : arm_controller
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : arm_controller
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : arm_controller
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : arm_controller
subscriber node         : transform_listener_impl_5bdaab4440f0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : arm_controller
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : arm_controller
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : arm_controller
subscriber node         : transform_listener_impl_61f2b5533050
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : arm_controller
subscriber node         : rviz_navigation_dialog_action_client
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : arm_controller
subscriber node         : transform_listener_impl_61f2b5c3f810
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : arm_controller
subscriber node         : move_group
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : arm_controller
subscriber node         : move_group_private_99865224190016
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : arm_controller
subscriber node         : transform_listener_impl_5ad3af369c80
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : arm_controller
subscriber node         : transform_listener_impl_5ad3afc309a0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : arm_controller
subscriber node         : moveit_simple_controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : arm_controller
subscriber node         : play_motion2
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : arm_controller
subscriber node         : _move_group_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : arm_controller
subscriber node         : twist_mux
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : arm_controller
subscriber node         : twist_marker
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : arm_controller
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : arm_controller
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : torso_controller
subscriber node         : gazebo
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : torso_controller
subscriber node         : base_imu
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : torso_controller
subscriber node         : base_laser
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : torso_controller
subscriber node         : base_sonar_01_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : torso_controller
subscriber node         : base_sonar_02_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : torso_controller
subscriber node         : base_sonar_03_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : torso_controller
subscriber node         : head_front_camera_frame_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : torso_controller
subscriber node         : gazebo_ros_odometry
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : torso_controller
subscriber node         : gazebo_ros2_control
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : torso_controller
subscriber node         : controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : torso_controller
subscriber node         : mobile_base_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : torso_controller
subscriber node         : gripper_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : torso_controller
subscriber node         : head_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : torso_controller
subscriber node         : joint_state_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : torso_controller
subscriber node         : imu_sensor_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : torso_controller
subscriber node         : arm_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : torso_controller
subscriber node         : torso_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : torso_controller
subscriber node         : ft_sensor_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : torso_controller
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : torso_controller
subscriber node         : local_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : torso_controller
subscriber node         : transform_listener_impl_5973afb268b0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : torso_controller
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : torso_controller
subscriber node         : transform_listener_impl_654ee1c865e0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : torso_controller
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : torso_controller
subscriber node         : global_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : torso_controller
subscriber node         : transform_listener_impl_623f34f20190
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : torso_controller
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : torso_controller
subscriber node         : transform_listener_impl_5ec47a4d1ab0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : torso_controller
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : torso_controller
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : torso_controller
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : torso_controller
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : torso_controller
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : torso_controller
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : torso_controller
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : torso_controller
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : torso_controller
subscriber node         : transform_listener_impl_5bdaab4440f0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : torso_controller
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : torso_controller
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : torso_controller
subscriber node         : transform_listener_impl_61f2b5533050
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : torso_controller
subscriber node         : rviz_navigation_dialog_action_client
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : torso_controller
subscriber node         : transform_listener_impl_61f2b5c3f810
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : torso_controller
subscriber node         : move_group
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : torso_controller
subscriber node         : move_group_private_99865224190016
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : torso_controller
subscriber node         : transform_listener_impl_5ad3af369c80
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : torso_controller
subscriber node         : transform_listener_impl_5ad3afc309a0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : torso_controller
subscriber node         : moveit_simple_controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : torso_controller
subscriber node         : play_motion2
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : torso_controller
subscriber node         : _move_group_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : torso_controller
subscriber node         : twist_mux
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : torso_controller
subscriber node         : twist_marker
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : torso_controller
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : torso_controller
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : ft_sensor_controller
subscriber node         : gazebo
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : ft_sensor_controller
subscriber node         : base_imu
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : ft_sensor_controller
subscriber node         : base_laser
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : ft_sensor_controller
subscriber node         : base_sonar_01_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : ft_sensor_controller
subscriber node         : base_sonar_02_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : ft_sensor_controller
subscriber node         : base_sonar_03_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : ft_sensor_controller
subscriber node         : head_front_camera_frame_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : ft_sensor_controller
subscriber node         : gazebo_ros_odometry
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : ft_sensor_controller
subscriber node         : gazebo_ros2_control
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : ft_sensor_controller
subscriber node         : controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : ft_sensor_controller
subscriber node         : mobile_base_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : ft_sensor_controller
subscriber node         : gripper_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : ft_sensor_controller
subscriber node         : head_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : ft_sensor_controller
subscriber node         : joint_state_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : ft_sensor_controller
subscriber node         : imu_sensor_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : ft_sensor_controller
subscriber node         : arm_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : ft_sensor_controller
subscriber node         : torso_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : ft_sensor_controller
subscriber node         : ft_sensor_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : ft_sensor_controller
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : ft_sensor_controller
subscriber node         : local_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : ft_sensor_controller
subscriber node         : transform_listener_impl_5973afb268b0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : ft_sensor_controller
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : ft_sensor_controller
subscriber node         : transform_listener_impl_654ee1c865e0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : ft_sensor_controller
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : ft_sensor_controller
subscriber node         : global_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : ft_sensor_controller
subscriber node         : transform_listener_impl_623f34f20190
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : ft_sensor_controller
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : ft_sensor_controller
subscriber node         : transform_listener_impl_5ec47a4d1ab0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : ft_sensor_controller
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : ft_sensor_controller
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : ft_sensor_controller
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : ft_sensor_controller
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : ft_sensor_controller
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : ft_sensor_controller
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : ft_sensor_controller
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : ft_sensor_controller
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : ft_sensor_controller
subscriber node         : transform_listener_impl_5bdaab4440f0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : ft_sensor_controller
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : ft_sensor_controller
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : ft_sensor_controller
subscriber node         : transform_listener_impl_61f2b5533050
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : ft_sensor_controller
subscriber node         : rviz_navigation_dialog_action_client
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : ft_sensor_controller
subscriber node         : transform_listener_impl_61f2b5c3f810
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : ft_sensor_controller
subscriber node         : move_group
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : ft_sensor_controller
subscriber node         : move_group_private_99865224190016
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : ft_sensor_controller
subscriber node         : transform_listener_impl_5ad3af369c80
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : ft_sensor_controller
subscriber node         : transform_listener_impl_5ad3afc309a0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : ft_sensor_controller
subscriber node         : moveit_simple_controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : ft_sensor_controller
subscriber node         : play_motion2
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : ft_sensor_controller
subscriber node         : _move_group_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : ft_sensor_controller
subscriber node         : twist_mux
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : ft_sensor_controller
subscriber node         : twist_marker
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : ft_sensor_controller
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : ft_sensor_controller
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_server
subscriber node         : gazebo
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_server
subscriber node         : base_imu
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_server
subscriber node         : base_laser
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_server
subscriber node         : base_sonar_01_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_server
subscriber node         : base_sonar_02_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_server
subscriber node         : base_sonar_03_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_server
subscriber node         : head_front_camera_frame_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_server
subscriber node         : gazebo_ros_odometry
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_server
subscriber node         : gazebo_ros2_control
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_server
subscriber node         : controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_server
subscriber node         : mobile_base_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_server
subscriber node         : gripper_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_server
subscriber node         : head_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_server
subscriber node         : joint_state_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_server
subscriber node         : imu_sensor_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_server
subscriber node         : arm_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_server
subscriber node         : torso_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_server
subscriber node         : ft_sensor_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_server
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_server
subscriber node         : local_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_server
subscriber node         : transform_listener_impl_5973afb268b0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_server
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_server
subscriber node         : transform_listener_impl_654ee1c865e0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_server
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_server
subscriber node         : global_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_server
subscriber node         : transform_listener_impl_623f34f20190
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_server
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_server
subscriber node         : transform_listener_impl_5ec47a4d1ab0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_server
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_server
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_server
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_server
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_server
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_server
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_server
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_server
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_server
subscriber node         : transform_listener_impl_5bdaab4440f0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_server
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_server
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_server
subscriber node         : transform_listener_impl_61f2b5533050
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_server
subscriber node         : rviz_navigation_dialog_action_client
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_server
subscriber node         : transform_listener_impl_61f2b5c3f810
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_server
subscriber node         : move_group
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_server
subscriber node         : move_group_private_99865224190016
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_server
subscriber node         : transform_listener_impl_5ad3af369c80
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_server
subscriber node         : transform_listener_impl_5ad3afc309a0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_server
subscriber node         : moveit_simple_controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_server
subscriber node         : play_motion2
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_server
subscriber node         : _move_group_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_server
subscriber node         : twist_mux
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_server
subscriber node         : twist_marker
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_server
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : controller_server
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : local_costmap
subscriber node         : gazebo
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : local_costmap
subscriber node         : base_imu
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : local_costmap
subscriber node         : base_laser
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : local_costmap
subscriber node         : base_sonar_01_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : local_costmap
subscriber node         : base_sonar_02_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : local_costmap
subscriber node         : base_sonar_03_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : local_costmap
subscriber node         : head_front_camera_frame_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : local_costmap
subscriber node         : gazebo_ros_odometry
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : local_costmap
subscriber node         : gazebo_ros2_control
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : local_costmap
subscriber node         : controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : local_costmap
subscriber node         : mobile_base_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : local_costmap
subscriber node         : gripper_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : local_costmap
subscriber node         : head_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : local_costmap
subscriber node         : joint_state_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : local_costmap
subscriber node         : imu_sensor_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : local_costmap
subscriber node         : arm_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : local_costmap
subscriber node         : torso_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : local_costmap
subscriber node         : ft_sensor_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : local_costmap
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : local_costmap
subscriber node         : local_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : local_costmap
subscriber node         : transform_listener_impl_5973afb268b0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : local_costmap
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : local_costmap
subscriber node         : transform_listener_impl_654ee1c865e0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : local_costmap
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : local_costmap
subscriber node         : global_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : local_costmap
subscriber node         : transform_listener_impl_623f34f20190
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : local_costmap
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : local_costmap
subscriber node         : transform_listener_impl_5ec47a4d1ab0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : local_costmap
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : local_costmap
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : local_costmap
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : local_costmap
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : local_costmap
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : local_costmap
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : local_costmap
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : local_costmap
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : local_costmap
subscriber node         : transform_listener_impl_5bdaab4440f0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : local_costmap
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : local_costmap
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : local_costmap
subscriber node         : transform_listener_impl_61f2b5533050
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : local_costmap
subscriber node         : rviz_navigation_dialog_action_client
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : local_costmap
subscriber node         : transform_listener_impl_61f2b5c3f810
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : local_costmap
subscriber node         : move_group
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : local_costmap
subscriber node         : move_group_private_99865224190016
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : local_costmap
subscriber node         : transform_listener_impl_5ad3af369c80
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : local_costmap
subscriber node         : transform_listener_impl_5ad3afc309a0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : local_costmap
subscriber node         : moveit_simple_controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : local_costmap
subscriber node         : play_motion2
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : local_costmap
subscriber node         : _move_group_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : local_costmap
subscriber node         : twist_mux
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : local_costmap
subscriber node         : twist_marker
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : local_costmap
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : local_costmap
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : smoother_server
subscriber node         : gazebo
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : smoother_server
subscriber node         : base_imu
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : smoother_server
subscriber node         : base_laser
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : smoother_server
subscriber node         : base_sonar_01_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : smoother_server
subscriber node         : base_sonar_02_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : smoother_server
subscriber node         : base_sonar_03_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : smoother_server
subscriber node         : head_front_camera_frame_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : smoother_server
subscriber node         : gazebo_ros_odometry
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : smoother_server
subscriber node         : gazebo_ros2_control
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : smoother_server
subscriber node         : controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : smoother_server
subscriber node         : mobile_base_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : smoother_server
subscriber node         : gripper_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : smoother_server
subscriber node         : head_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : smoother_server
subscriber node         : joint_state_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : smoother_server
subscriber node         : imu_sensor_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : smoother_server
subscriber node         : arm_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : smoother_server
subscriber node         : torso_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : smoother_server
subscriber node         : ft_sensor_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : smoother_server
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : smoother_server
subscriber node         : local_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : smoother_server
subscriber node         : transform_listener_impl_5973afb268b0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : smoother_server
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : smoother_server
subscriber node         : transform_listener_impl_654ee1c865e0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : smoother_server
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : smoother_server
subscriber node         : global_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : smoother_server
subscriber node         : transform_listener_impl_623f34f20190
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : smoother_server
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : smoother_server
subscriber node         : transform_listener_impl_5ec47a4d1ab0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : smoother_server
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : smoother_server
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : smoother_server
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : smoother_server
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : smoother_server
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : smoother_server
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : smoother_server
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : smoother_server
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : smoother_server
subscriber node         : transform_listener_impl_5bdaab4440f0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : smoother_server
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : smoother_server
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : smoother_server
subscriber node         : transform_listener_impl_61f2b5533050
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : smoother_server
subscriber node         : rviz_navigation_dialog_action_client
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : smoother_server
subscriber node         : transform_listener_impl_61f2b5c3f810
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : smoother_server
subscriber node         : move_group
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : smoother_server
subscriber node         : move_group_private_99865224190016
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : smoother_server
subscriber node         : transform_listener_impl_5ad3af369c80
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : smoother_server
subscriber node         : transform_listener_impl_5ad3afc309a0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : smoother_server
subscriber node         : moveit_simple_controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : smoother_server
subscriber node         : play_motion2
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : smoother_server
subscriber node         : _move_group_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : smoother_server
subscriber node         : twist_mux
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : smoother_server
subscriber node         : twist_marker
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : smoother_server
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : smoother_server
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : planner_server
subscriber node         : gazebo
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : planner_server
subscriber node         : base_imu
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : planner_server
subscriber node         : base_laser
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : planner_server
subscriber node         : base_sonar_01_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : planner_server
subscriber node         : base_sonar_02_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : planner_server
subscriber node         : base_sonar_03_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : planner_server
subscriber node         : head_front_camera_frame_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : planner_server
subscriber node         : gazebo_ros_odometry
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : planner_server
subscriber node         : gazebo_ros2_control
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : planner_server
subscriber node         : controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : planner_server
subscriber node         : mobile_base_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : planner_server
subscriber node         : gripper_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : planner_server
subscriber node         : head_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : planner_server
subscriber node         : joint_state_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : planner_server
subscriber node         : imu_sensor_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : planner_server
subscriber node         : arm_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : planner_server
subscriber node         : torso_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : planner_server
subscriber node         : ft_sensor_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : planner_server
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : planner_server
subscriber node         : local_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : planner_server
subscriber node         : transform_listener_impl_5973afb268b0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : planner_server
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : planner_server
subscriber node         : transform_listener_impl_654ee1c865e0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : planner_server
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : planner_server
subscriber node         : global_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : planner_server
subscriber node         : transform_listener_impl_623f34f20190
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : planner_server
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : planner_server
subscriber node         : transform_listener_impl_5ec47a4d1ab0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : planner_server
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : planner_server
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : planner_server
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : planner_server
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : planner_server
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : planner_server
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : planner_server
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : planner_server
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : planner_server
subscriber node         : transform_listener_impl_5bdaab4440f0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : planner_server
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : planner_server
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : planner_server
subscriber node         : transform_listener_impl_61f2b5533050
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : planner_server
subscriber node         : rviz_navigation_dialog_action_client
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : planner_server
subscriber node         : transform_listener_impl_61f2b5c3f810
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : planner_server
subscriber node         : move_group
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : planner_server
subscriber node         : move_group_private_99865224190016
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : planner_server
subscriber node         : transform_listener_impl_5ad3af369c80
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : planner_server
subscriber node         : transform_listener_impl_5ad3afc309a0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : planner_server
subscriber node         : moveit_simple_controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : planner_server
subscriber node         : play_motion2
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : planner_server
subscriber node         : _move_group_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : planner_server
subscriber node         : twist_mux
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : planner_server
subscriber node         : twist_marker
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : planner_server
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : planner_server
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : global_costmap
subscriber node         : gazebo
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : global_costmap
subscriber node         : base_imu
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : global_costmap
subscriber node         : base_laser
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : global_costmap
subscriber node         : base_sonar_01_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : global_costmap
subscriber node         : base_sonar_02_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : global_costmap
subscriber node         : base_sonar_03_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : global_costmap
subscriber node         : head_front_camera_frame_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : global_costmap
subscriber node         : gazebo_ros_odometry
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : global_costmap
subscriber node         : gazebo_ros2_control
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : global_costmap
subscriber node         : controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : global_costmap
subscriber node         : mobile_base_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : global_costmap
subscriber node         : gripper_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : global_costmap
subscriber node         : head_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : global_costmap
subscriber node         : joint_state_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : global_costmap
subscriber node         : imu_sensor_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : global_costmap
subscriber node         : arm_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : global_costmap
subscriber node         : torso_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : global_costmap
subscriber node         : ft_sensor_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : global_costmap
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : global_costmap
subscriber node         : local_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : global_costmap
subscriber node         : transform_listener_impl_5973afb268b0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : global_costmap
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : global_costmap
subscriber node         : transform_listener_impl_654ee1c865e0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : global_costmap
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : global_costmap
subscriber node         : global_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : global_costmap
subscriber node         : transform_listener_impl_623f34f20190
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : global_costmap
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : global_costmap
subscriber node         : transform_listener_impl_5ec47a4d1ab0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : global_costmap
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : global_costmap
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : global_costmap
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : global_costmap
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : global_costmap
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : global_costmap
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : global_costmap
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : global_costmap
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : global_costmap
subscriber node         : transform_listener_impl_5bdaab4440f0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : global_costmap
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : global_costmap
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : global_costmap
subscriber node         : transform_listener_impl_61f2b5533050
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : global_costmap
subscriber node         : rviz_navigation_dialog_action_client
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : global_costmap
subscriber node         : transform_listener_impl_61f2b5c3f810
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : global_costmap
subscriber node         : move_group
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : global_costmap
subscriber node         : move_group_private_99865224190016
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : global_costmap
subscriber node         : transform_listener_impl_5ad3af369c80
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : global_costmap
subscriber node         : transform_listener_impl_5ad3afc309a0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : global_costmap
subscriber node         : moveit_simple_controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : global_costmap
subscriber node         : play_motion2
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : global_costmap
subscriber node         : _move_group_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : global_costmap
subscriber node         : twist_mux
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : global_costmap
subscriber node         : twist_marker
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : global_costmap
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : global_costmap
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : behavior_server
subscriber node         : gazebo
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : behavior_server
subscriber node         : base_imu
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : behavior_server
subscriber node         : base_laser
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : behavior_server
subscriber node         : base_sonar_01_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : behavior_server
subscriber node         : base_sonar_02_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : behavior_server
subscriber node         : base_sonar_03_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : behavior_server
subscriber node         : head_front_camera_frame_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : behavior_server
subscriber node         : gazebo_ros_odometry
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : behavior_server
subscriber node         : gazebo_ros2_control
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : behavior_server
subscriber node         : controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : behavior_server
subscriber node         : mobile_base_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : behavior_server
subscriber node         : gripper_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : behavior_server
subscriber node         : head_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : behavior_server
subscriber node         : joint_state_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : behavior_server
subscriber node         : imu_sensor_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : behavior_server
subscriber node         : arm_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : behavior_server
subscriber node         : torso_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : behavior_server
subscriber node         : ft_sensor_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : behavior_server
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : behavior_server
subscriber node         : local_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : behavior_server
subscriber node         : transform_listener_impl_5973afb268b0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : behavior_server
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : behavior_server
subscriber node         : transform_listener_impl_654ee1c865e0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : behavior_server
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : behavior_server
subscriber node         : global_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : behavior_server
subscriber node         : transform_listener_impl_623f34f20190
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : behavior_server
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : behavior_server
subscriber node         : transform_listener_impl_5ec47a4d1ab0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : behavior_server
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : behavior_server
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : behavior_server
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : behavior_server
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : behavior_server
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : behavior_server
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : behavior_server
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : behavior_server
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : behavior_server
subscriber node         : transform_listener_impl_5bdaab4440f0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : behavior_server
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : behavior_server
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : behavior_server
subscriber node         : transform_listener_impl_61f2b5533050
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : behavior_server
subscriber node         : rviz_navigation_dialog_action_client
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : behavior_server
subscriber node         : transform_listener_impl_61f2b5c3f810
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : behavior_server
subscriber node         : move_group
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : behavior_server
subscriber node         : move_group_private_99865224190016
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : behavior_server
subscriber node         : transform_listener_impl_5ad3af369c80
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : behavior_server
subscriber node         : transform_listener_impl_5ad3afc309a0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : behavior_server
subscriber node         : moveit_simple_controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : behavior_server
subscriber node         : play_motion2
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : behavior_server
subscriber node         : _move_group_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : behavior_server
subscriber node         : twist_mux
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : behavior_server
subscriber node         : twist_marker
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : behavior_server
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : behavior_server
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator
subscriber node         : gazebo
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator
subscriber node         : base_imu
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator
subscriber node         : base_laser
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator
subscriber node         : base_sonar_01_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator
subscriber node         : base_sonar_02_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator
subscriber node         : base_sonar_03_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator
subscriber node         : head_front_camera_frame_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator
subscriber node         : gazebo_ros_odometry
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator
subscriber node         : gazebo_ros2_control
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator
subscriber node         : controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator
subscriber node         : mobile_base_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator
subscriber node         : gripper_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator
subscriber node         : head_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator
subscriber node         : joint_state_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator
subscriber node         : imu_sensor_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator
subscriber node         : arm_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator
subscriber node         : torso_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator
subscriber node         : ft_sensor_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator
subscriber node         : local_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator
subscriber node         : transform_listener_impl_5973afb268b0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator
subscriber node         : transform_listener_impl_654ee1c865e0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator
subscriber node         : global_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator
subscriber node         : transform_listener_impl_623f34f20190
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator
subscriber node         : transform_listener_impl_5ec47a4d1ab0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator
subscriber node         : transform_listener_impl_5bdaab4440f0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator
subscriber node         : transform_listener_impl_61f2b5533050
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator
subscriber node         : rviz_navigation_dialog_action_client
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator
subscriber node         : transform_listener_impl_61f2b5c3f810
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator
subscriber node         : move_group
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator
subscriber node         : move_group_private_99865224190016
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator
subscriber node         : transform_listener_impl_5ad3af369c80
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator
subscriber node         : transform_listener_impl_5ad3afc309a0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator
subscriber node         : moveit_simple_controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator
subscriber node         : play_motion2
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator
subscriber node         : _move_group_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator
subscriber node         : twist_mux
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator
subscriber node         : twist_marker
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_to_pose_rclcpp_node
subscriber node         : gazebo
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_to_pose_rclcpp_node
subscriber node         : base_imu
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_to_pose_rclcpp_node
subscriber node         : base_laser
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_to_pose_rclcpp_node
subscriber node         : base_sonar_01_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_to_pose_rclcpp_node
subscriber node         : base_sonar_02_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_to_pose_rclcpp_node
subscriber node         : base_sonar_03_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_to_pose_rclcpp_node
subscriber node         : head_front_camera_frame_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_to_pose_rclcpp_node
subscriber node         : gazebo_ros_odometry
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_to_pose_rclcpp_node
subscriber node         : gazebo_ros2_control
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_to_pose_rclcpp_node
subscriber node         : controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_to_pose_rclcpp_node
subscriber node         : mobile_base_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_to_pose_rclcpp_node
subscriber node         : gripper_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_to_pose_rclcpp_node
subscriber node         : head_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_to_pose_rclcpp_node
subscriber node         : joint_state_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_to_pose_rclcpp_node
subscriber node         : imu_sensor_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_to_pose_rclcpp_node
subscriber node         : arm_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_to_pose_rclcpp_node
subscriber node         : torso_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_to_pose_rclcpp_node
subscriber node         : ft_sensor_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_to_pose_rclcpp_node
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_to_pose_rclcpp_node
subscriber node         : local_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_to_pose_rclcpp_node
subscriber node         : transform_listener_impl_5973afb268b0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_to_pose_rclcpp_node
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_to_pose_rclcpp_node
subscriber node         : transform_listener_impl_654ee1c865e0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_to_pose_rclcpp_node
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_to_pose_rclcpp_node
subscriber node         : global_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_to_pose_rclcpp_node
subscriber node         : transform_listener_impl_623f34f20190
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_to_pose_rclcpp_node
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_to_pose_rclcpp_node
subscriber node         : transform_listener_impl_5ec47a4d1ab0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_to_pose_rclcpp_node
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_to_pose_rclcpp_node
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_to_pose_rclcpp_node
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_to_pose_rclcpp_node
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_to_pose_rclcpp_node
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_to_pose_rclcpp_node
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_to_pose_rclcpp_node
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_to_pose_rclcpp_node
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_to_pose_rclcpp_node
subscriber node         : transform_listener_impl_5bdaab4440f0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_to_pose_rclcpp_node
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_to_pose_rclcpp_node
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_to_pose_rclcpp_node
subscriber node         : transform_listener_impl_61f2b5533050
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_to_pose_rclcpp_node
subscriber node         : rviz_navigation_dialog_action_client
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_to_pose_rclcpp_node
subscriber node         : transform_listener_impl_61f2b5c3f810
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_to_pose_rclcpp_node
subscriber node         : move_group
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_to_pose_rclcpp_node
subscriber node         : move_group_private_99865224190016
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_to_pose_rclcpp_node
subscriber node         : transform_listener_impl_5ad3af369c80
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_to_pose_rclcpp_node
subscriber node         : transform_listener_impl_5ad3afc309a0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_to_pose_rclcpp_node
subscriber node         : moveit_simple_controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_to_pose_rclcpp_node
subscriber node         : play_motion2
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_to_pose_rclcpp_node
subscriber node         : _move_group_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_to_pose_rclcpp_node
subscriber node         : twist_mux
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_to_pose_rclcpp_node
subscriber node         : twist_marker
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_to_pose_rclcpp_node
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_to_pose_rclcpp_node
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_through_poses_rclcpp_node
subscriber node         : gazebo
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_through_poses_rclcpp_node
subscriber node         : base_imu
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_through_poses_rclcpp_node
subscriber node         : base_laser
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_through_poses_rclcpp_node
subscriber node         : base_sonar_01_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_through_poses_rclcpp_node
subscriber node         : base_sonar_02_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_through_poses_rclcpp_node
subscriber node         : base_sonar_03_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_through_poses_rclcpp_node
subscriber node         : head_front_camera_frame_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_through_poses_rclcpp_node
subscriber node         : gazebo_ros_odometry
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_through_poses_rclcpp_node
subscriber node         : gazebo_ros2_control
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_through_poses_rclcpp_node
subscriber node         : controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_through_poses_rclcpp_node
subscriber node         : mobile_base_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_through_poses_rclcpp_node
subscriber node         : gripper_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_through_poses_rclcpp_node
subscriber node         : head_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_through_poses_rclcpp_node
subscriber node         : joint_state_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_through_poses_rclcpp_node
subscriber node         : imu_sensor_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_through_poses_rclcpp_node
subscriber node         : arm_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_through_poses_rclcpp_node
subscriber node         : torso_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_through_poses_rclcpp_node
subscriber node         : ft_sensor_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_through_poses_rclcpp_node
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_through_poses_rclcpp_node
subscriber node         : local_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_through_poses_rclcpp_node
subscriber node         : transform_listener_impl_5973afb268b0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_through_poses_rclcpp_node
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_through_poses_rclcpp_node
subscriber node         : transform_listener_impl_654ee1c865e0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_through_poses_rclcpp_node
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_through_poses_rclcpp_node
subscriber node         : global_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_through_poses_rclcpp_node
subscriber node         : transform_listener_impl_623f34f20190
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_through_poses_rclcpp_node
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_through_poses_rclcpp_node
subscriber node         : transform_listener_impl_5ec47a4d1ab0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_through_poses_rclcpp_node
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_through_poses_rclcpp_node
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_through_poses_rclcpp_node
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_through_poses_rclcpp_node
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_through_poses_rclcpp_node
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_through_poses_rclcpp_node
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_through_poses_rclcpp_node
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_through_poses_rclcpp_node
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_through_poses_rclcpp_node
subscriber node         : transform_listener_impl_5bdaab4440f0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_through_poses_rclcpp_node
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_through_poses_rclcpp_node
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_through_poses_rclcpp_node
subscriber node         : transform_listener_impl_61f2b5533050
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_through_poses_rclcpp_node
subscriber node         : rviz_navigation_dialog_action_client
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_through_poses_rclcpp_node
subscriber node         : transform_listener_impl_61f2b5c3f810
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_through_poses_rclcpp_node
subscriber node         : move_group
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_through_poses_rclcpp_node
subscriber node         : move_group_private_99865224190016
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_through_poses_rclcpp_node
subscriber node         : transform_listener_impl_5ad3af369c80
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_through_poses_rclcpp_node
subscriber node         : transform_listener_impl_5ad3afc309a0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_through_poses_rclcpp_node
subscriber node         : moveit_simple_controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_through_poses_rclcpp_node
subscriber node         : play_motion2
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_through_poses_rclcpp_node
subscriber node         : _move_group_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_through_poses_rclcpp_node
subscriber node         : twist_mux
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_through_poses_rclcpp_node
subscriber node         : twist_marker
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_through_poses_rclcpp_node
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : bt_navigator_navigate_through_poses_rclcpp_node
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : waypoint_follower
subscriber node         : gazebo
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : waypoint_follower
subscriber node         : base_imu
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : waypoint_follower
subscriber node         : base_laser
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : waypoint_follower
subscriber node         : base_sonar_01_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : waypoint_follower
subscriber node         : base_sonar_02_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : waypoint_follower
subscriber node         : base_sonar_03_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : waypoint_follower
subscriber node         : head_front_camera_frame_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : waypoint_follower
subscriber node         : gazebo_ros_odometry
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : waypoint_follower
subscriber node         : gazebo_ros2_control
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : waypoint_follower
subscriber node         : controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : waypoint_follower
subscriber node         : mobile_base_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : waypoint_follower
subscriber node         : gripper_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : waypoint_follower
subscriber node         : head_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : waypoint_follower
subscriber node         : joint_state_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : waypoint_follower
subscriber node         : imu_sensor_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : waypoint_follower
subscriber node         : arm_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : waypoint_follower
subscriber node         : torso_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : waypoint_follower
subscriber node         : ft_sensor_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : waypoint_follower
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : waypoint_follower
subscriber node         : local_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : waypoint_follower
subscriber node         : transform_listener_impl_5973afb268b0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : waypoint_follower
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : waypoint_follower
subscriber node         : transform_listener_impl_654ee1c865e0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : waypoint_follower
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : waypoint_follower
subscriber node         : global_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : waypoint_follower
subscriber node         : transform_listener_impl_623f34f20190
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : waypoint_follower
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : waypoint_follower
subscriber node         : transform_listener_impl_5ec47a4d1ab0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : waypoint_follower
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : waypoint_follower
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : waypoint_follower
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : waypoint_follower
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : waypoint_follower
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : waypoint_follower
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : waypoint_follower
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : waypoint_follower
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : waypoint_follower
subscriber node         : transform_listener_impl_5bdaab4440f0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : waypoint_follower
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : waypoint_follower
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : waypoint_follower
subscriber node         : transform_listener_impl_61f2b5533050
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : waypoint_follower
subscriber node         : rviz_navigation_dialog_action_client
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : waypoint_follower
subscriber node         : transform_listener_impl_61f2b5c3f810
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : waypoint_follower
subscriber node         : move_group
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : waypoint_follower
subscriber node         : move_group_private_99865224190016
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : waypoint_follower
subscriber node         : transform_listener_impl_5ad3af369c80
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : waypoint_follower
subscriber node         : transform_listener_impl_5ad3afc309a0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : waypoint_follower
subscriber node         : moveit_simple_controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : waypoint_follower
subscriber node         : play_motion2
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : waypoint_follower
subscriber node         : _move_group_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : waypoint_follower
subscriber node         : twist_mux
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : waypoint_follower
subscriber node         : twist_marker
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : waypoint_follower
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : waypoint_follower
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : velocity_smoother
subscriber node         : gazebo
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : velocity_smoother
subscriber node         : base_imu
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : velocity_smoother
subscriber node         : base_laser
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : velocity_smoother
subscriber node         : base_sonar_01_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : velocity_smoother
subscriber node         : base_sonar_02_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : velocity_smoother
subscriber node         : base_sonar_03_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : velocity_smoother
subscriber node         : head_front_camera_frame_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : velocity_smoother
subscriber node         : gazebo_ros_odometry
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : velocity_smoother
subscriber node         : gazebo_ros2_control
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : velocity_smoother
subscriber node         : controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : velocity_smoother
subscriber node         : mobile_base_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : velocity_smoother
subscriber node         : gripper_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : velocity_smoother
subscriber node         : head_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : velocity_smoother
subscriber node         : joint_state_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : velocity_smoother
subscriber node         : imu_sensor_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : velocity_smoother
subscriber node         : arm_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : velocity_smoother
subscriber node         : torso_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : velocity_smoother
subscriber node         : ft_sensor_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : velocity_smoother
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : velocity_smoother
subscriber node         : local_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : velocity_smoother
subscriber node         : transform_listener_impl_5973afb268b0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : velocity_smoother
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : velocity_smoother
subscriber node         : transform_listener_impl_654ee1c865e0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : velocity_smoother
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : velocity_smoother
subscriber node         : global_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : velocity_smoother
subscriber node         : transform_listener_impl_623f34f20190
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : velocity_smoother
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : velocity_smoother
subscriber node         : transform_listener_impl_5ec47a4d1ab0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : velocity_smoother
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : velocity_smoother
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : velocity_smoother
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : velocity_smoother
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : velocity_smoother
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : velocity_smoother
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : velocity_smoother
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : velocity_smoother
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : velocity_smoother
subscriber node         : transform_listener_impl_5bdaab4440f0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : velocity_smoother
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : velocity_smoother
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : velocity_smoother
subscriber node         : transform_listener_impl_61f2b5533050
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : velocity_smoother
subscriber node         : rviz_navigation_dialog_action_client
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : velocity_smoother
subscriber node         : transform_listener_impl_61f2b5c3f810
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : velocity_smoother
subscriber node         : move_group
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : velocity_smoother
subscriber node         : move_group_private_99865224190016
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : velocity_smoother
subscriber node         : transform_listener_impl_5ad3af369c80
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : velocity_smoother
subscriber node         : transform_listener_impl_5ad3afc309a0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : velocity_smoother
subscriber node         : moveit_simple_controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : velocity_smoother
subscriber node         : play_motion2
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : velocity_smoother
subscriber node         : _move_group_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : velocity_smoother
subscriber node         : twist_mux
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : velocity_smoother
subscriber node         : twist_marker
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : velocity_smoother
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : velocity_smoother
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _ros2cli_daemon_0_b01b7a1b025248fc824e9438d41e4800
subscriber node         : gazebo
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _ros2cli_daemon_0_b01b7a1b025248fc824e9438d41e4800
subscriber node         : base_imu
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _ros2cli_daemon_0_b01b7a1b025248fc824e9438d41e4800
subscriber node         : base_laser
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _ros2cli_daemon_0_b01b7a1b025248fc824e9438d41e4800
subscriber node         : base_sonar_01_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _ros2cli_daemon_0_b01b7a1b025248fc824e9438d41e4800
subscriber node         : base_sonar_02_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _ros2cli_daemon_0_b01b7a1b025248fc824e9438d41e4800
subscriber node         : base_sonar_03_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _ros2cli_daemon_0_b01b7a1b025248fc824e9438d41e4800
subscriber node         : head_front_camera_frame_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _ros2cli_daemon_0_b01b7a1b025248fc824e9438d41e4800
subscriber node         : gazebo_ros_odometry
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _ros2cli_daemon_0_b01b7a1b025248fc824e9438d41e4800
subscriber node         : gazebo_ros2_control
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _ros2cli_daemon_0_b01b7a1b025248fc824e9438d41e4800
subscriber node         : controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _ros2cli_daemon_0_b01b7a1b025248fc824e9438d41e4800
subscriber node         : mobile_base_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _ros2cli_daemon_0_b01b7a1b025248fc824e9438d41e4800
subscriber node         : gripper_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _ros2cli_daemon_0_b01b7a1b025248fc824e9438d41e4800
subscriber node         : head_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _ros2cli_daemon_0_b01b7a1b025248fc824e9438d41e4800
subscriber node         : joint_state_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _ros2cli_daemon_0_b01b7a1b025248fc824e9438d41e4800
subscriber node         : imu_sensor_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _ros2cli_daemon_0_b01b7a1b025248fc824e9438d41e4800
subscriber node         : arm_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _ros2cli_daemon_0_b01b7a1b025248fc824e9438d41e4800
subscriber node         : torso_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _ros2cli_daemon_0_b01b7a1b025248fc824e9438d41e4800
subscriber node         : ft_sensor_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _ros2cli_daemon_0_b01b7a1b025248fc824e9438d41e4800
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _ros2cli_daemon_0_b01b7a1b025248fc824e9438d41e4800
subscriber node         : local_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _ros2cli_daemon_0_b01b7a1b025248fc824e9438d41e4800
subscriber node         : transform_listener_impl_5973afb268b0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _ros2cli_daemon_0_b01b7a1b025248fc824e9438d41e4800
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _ros2cli_daemon_0_b01b7a1b025248fc824e9438d41e4800
subscriber node         : transform_listener_impl_654ee1c865e0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _ros2cli_daemon_0_b01b7a1b025248fc824e9438d41e4800
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _ros2cli_daemon_0_b01b7a1b025248fc824e9438d41e4800
subscriber node         : global_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _ros2cli_daemon_0_b01b7a1b025248fc824e9438d41e4800
subscriber node         : transform_listener_impl_623f34f20190
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _ros2cli_daemon_0_b01b7a1b025248fc824e9438d41e4800
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _ros2cli_daemon_0_b01b7a1b025248fc824e9438d41e4800
subscriber node         : transform_listener_impl_5ec47a4d1ab0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _ros2cli_daemon_0_b01b7a1b025248fc824e9438d41e4800
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _ros2cli_daemon_0_b01b7a1b025248fc824e9438d41e4800
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _ros2cli_daemon_0_b01b7a1b025248fc824e9438d41e4800
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _ros2cli_daemon_0_b01b7a1b025248fc824e9438d41e4800
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _ros2cli_daemon_0_b01b7a1b025248fc824e9438d41e4800
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _ros2cli_daemon_0_b01b7a1b025248fc824e9438d41e4800
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _ros2cli_daemon_0_b01b7a1b025248fc824e9438d41e4800
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _ros2cli_daemon_0_b01b7a1b025248fc824e9438d41e4800
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _ros2cli_daemon_0_b01b7a1b025248fc824e9438d41e4800
subscriber node         : transform_listener_impl_5bdaab4440f0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _ros2cli_daemon_0_b01b7a1b025248fc824e9438d41e4800
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _ros2cli_daemon_0_b01b7a1b025248fc824e9438d41e4800
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _ros2cli_daemon_0_b01b7a1b025248fc824e9438d41e4800
subscriber node         : transform_listener_impl_61f2b5533050
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _ros2cli_daemon_0_b01b7a1b025248fc824e9438d41e4800
subscriber node         : rviz_navigation_dialog_action_client
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _ros2cli_daemon_0_b01b7a1b025248fc824e9438d41e4800
subscriber node         : transform_listener_impl_61f2b5c3f810
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _ros2cli_daemon_0_b01b7a1b025248fc824e9438d41e4800
subscriber node         : move_group
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _ros2cli_daemon_0_b01b7a1b025248fc824e9438d41e4800
subscriber node         : move_group_private_99865224190016
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _ros2cli_daemon_0_b01b7a1b025248fc824e9438d41e4800
subscriber node         : transform_listener_impl_5ad3af369c80
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _ros2cli_daemon_0_b01b7a1b025248fc824e9438d41e4800
subscriber node         : transform_listener_impl_5ad3afc309a0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _ros2cli_daemon_0_b01b7a1b025248fc824e9438d41e4800
subscriber node         : moveit_simple_controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _ros2cli_daemon_0_b01b7a1b025248fc824e9438d41e4800
subscriber node         : play_motion2
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _ros2cli_daemon_0_b01b7a1b025248fc824e9438d41e4800
subscriber node         : _move_group_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _ros2cli_daemon_0_b01b7a1b025248fc824e9438d41e4800
subscriber node         : twist_mux
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _ros2cli_daemon_0_b01b7a1b025248fc824e9438d41e4800
subscriber node         : twist_marker
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _ros2cli_daemon_0_b01b7a1b025248fc824e9438d41e4800
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _ros2cli_daemon_0_b01b7a1b025248fc824e9438d41e4800
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_navigation
subscriber node         : gazebo
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_navigation
subscriber node         : base_imu
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_navigation
subscriber node         : base_laser
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_navigation
subscriber node         : base_sonar_01_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_navigation
subscriber node         : base_sonar_02_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_navigation
subscriber node         : base_sonar_03_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_navigation
subscriber node         : head_front_camera_frame_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_navigation
subscriber node         : gazebo_ros_odometry
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_navigation
subscriber node         : gazebo_ros2_control
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_navigation
subscriber node         : controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_navigation
subscriber node         : mobile_base_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_navigation
subscriber node         : gripper_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_navigation
subscriber node         : head_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_navigation
subscriber node         : joint_state_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_navigation
subscriber node         : imu_sensor_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_navigation
subscriber node         : arm_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_navigation
subscriber node         : torso_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_navigation
subscriber node         : ft_sensor_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_navigation
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_navigation
subscriber node         : local_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_navigation
subscriber node         : transform_listener_impl_5973afb268b0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_navigation
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_navigation
subscriber node         : transform_listener_impl_654ee1c865e0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_navigation
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_navigation
subscriber node         : global_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_navigation
subscriber node         : transform_listener_impl_623f34f20190
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_navigation
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_navigation
subscriber node         : transform_listener_impl_5ec47a4d1ab0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_navigation
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_navigation
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_navigation
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_navigation
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_navigation
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_navigation
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_navigation
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_navigation
subscriber node         : transform_listener_impl_5bdaab4440f0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_navigation
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_navigation
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_navigation
subscriber node         : transform_listener_impl_61f2b5533050
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_navigation
subscriber node         : rviz_navigation_dialog_action_client
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_navigation
subscriber node         : transform_listener_impl_61f2b5c3f810
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_navigation
subscriber node         : move_group
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_navigation
subscriber node         : move_group_private_99865224190016
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_navigation
subscriber node         : transform_listener_impl_5ad3af369c80
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_navigation
subscriber node         : transform_listener_impl_5ad3afc309a0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_navigation
subscriber node         : moveit_simple_controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_navigation
subscriber node         : play_motion2
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_navigation
subscriber node         : _move_group_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_navigation
subscriber node         : twist_mux
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_navigation
subscriber node         : twist_marker
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_navigation
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_navigation
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : map_server
subscriber node         : gazebo
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : map_server
subscriber node         : base_imu
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : map_server
subscriber node         : base_laser
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : map_server
subscriber node         : base_sonar_01_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : map_server
subscriber node         : base_sonar_02_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : map_server
subscriber node         : base_sonar_03_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : map_server
subscriber node         : head_front_camera_frame_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : map_server
subscriber node         : gazebo_ros_odometry
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : map_server
subscriber node         : gazebo_ros2_control
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : map_server
subscriber node         : controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : map_server
subscriber node         : mobile_base_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : map_server
subscriber node         : gripper_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : map_server
subscriber node         : head_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : map_server
subscriber node         : joint_state_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : map_server
subscriber node         : imu_sensor_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : map_server
subscriber node         : arm_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : map_server
subscriber node         : torso_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : map_server
subscriber node         : ft_sensor_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : map_server
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : map_server
subscriber node         : local_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : map_server
subscriber node         : transform_listener_impl_5973afb268b0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : map_server
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : map_server
subscriber node         : transform_listener_impl_654ee1c865e0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : map_server
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : map_server
subscriber node         : global_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : map_server
subscriber node         : transform_listener_impl_623f34f20190
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : map_server
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : map_server
subscriber node         : transform_listener_impl_5ec47a4d1ab0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : map_server
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : map_server
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : map_server
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : map_server
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : map_server
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : map_server
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : map_server
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : map_server
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : map_server
subscriber node         : transform_listener_impl_5bdaab4440f0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : map_server
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : map_server
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : map_server
subscriber node         : transform_listener_impl_61f2b5533050
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : map_server
subscriber node         : rviz_navigation_dialog_action_client
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : map_server
subscriber node         : transform_listener_impl_61f2b5c3f810
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : map_server
subscriber node         : move_group
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : map_server
subscriber node         : move_group_private_99865224190016
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : map_server
subscriber node         : transform_listener_impl_5ad3af369c80
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : map_server
subscriber node         : transform_listener_impl_5ad3afc309a0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : map_server
subscriber node         : moveit_simple_controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : map_server
subscriber node         : play_motion2
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : map_server
subscriber node         : _move_group_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : map_server
subscriber node         : twist_mux
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : map_server
subscriber node         : twist_marker
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : map_server
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : map_server
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : amcl
subscriber node         : gazebo
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : amcl
subscriber node         : base_imu
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : amcl
subscriber node         : base_laser
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : amcl
subscriber node         : base_sonar_01_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : amcl
subscriber node         : base_sonar_02_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : amcl
subscriber node         : base_sonar_03_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : amcl
subscriber node         : head_front_camera_frame_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : amcl
subscriber node         : gazebo_ros_odometry
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : amcl
subscriber node         : gazebo_ros2_control
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : amcl
subscriber node         : controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : amcl
subscriber node         : mobile_base_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : amcl
subscriber node         : gripper_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : amcl
subscriber node         : head_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : amcl
subscriber node         : joint_state_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : amcl
subscriber node         : imu_sensor_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : amcl
subscriber node         : arm_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : amcl
subscriber node         : torso_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : amcl
subscriber node         : ft_sensor_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : amcl
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : amcl
subscriber node         : local_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : amcl
subscriber node         : transform_listener_impl_5973afb268b0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : amcl
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : amcl
subscriber node         : transform_listener_impl_654ee1c865e0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : amcl
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : amcl
subscriber node         : global_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : amcl
subscriber node         : transform_listener_impl_623f34f20190
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : amcl
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : amcl
subscriber node         : transform_listener_impl_5ec47a4d1ab0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : amcl
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : amcl
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : amcl
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : amcl
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : amcl
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : amcl
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : amcl
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : amcl
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : amcl
subscriber node         : transform_listener_impl_5bdaab4440f0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : amcl
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : amcl
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : amcl
subscriber node         : transform_listener_impl_61f2b5533050
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : amcl
subscriber node         : rviz_navigation_dialog_action_client
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : amcl
subscriber node         : transform_listener_impl_61f2b5c3f810
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : amcl
subscriber node         : move_group
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : amcl
subscriber node         : move_group_private_99865224190016
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : amcl
subscriber node         : transform_listener_impl_5ad3af369c80
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : amcl
subscriber node         : transform_listener_impl_5ad3afc309a0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : amcl
subscriber node         : moveit_simple_controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : amcl
subscriber node         : play_motion2
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : amcl
subscriber node         : _move_group_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : amcl
subscriber node         : twist_mux
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : amcl
subscriber node         : twist_marker
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : amcl
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : amcl
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_localization
subscriber node         : gazebo
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_localization
subscriber node         : base_imu
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_localization
subscriber node         : base_laser
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_localization
subscriber node         : base_sonar_01_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_localization
subscriber node         : base_sonar_02_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_localization
subscriber node         : base_sonar_03_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_localization
subscriber node         : head_front_camera_frame_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_localization
subscriber node         : gazebo_ros_odometry
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_localization
subscriber node         : gazebo_ros2_control
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_localization
subscriber node         : controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_localization
subscriber node         : mobile_base_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_localization
subscriber node         : gripper_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_localization
subscriber node         : head_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_localization
subscriber node         : joint_state_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_localization
subscriber node         : imu_sensor_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_localization
subscriber node         : arm_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_localization
subscriber node         : torso_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_localization
subscriber node         : ft_sensor_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_localization
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_localization
subscriber node         : local_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_localization
subscriber node         : transform_listener_impl_5973afb268b0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_localization
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_localization
subscriber node         : transform_listener_impl_654ee1c865e0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_localization
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_localization
subscriber node         : global_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_localization
subscriber node         : transform_listener_impl_623f34f20190
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_localization
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_localization
subscriber node         : transform_listener_impl_5ec47a4d1ab0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_localization
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_localization
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_localization
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_localization
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_localization
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_localization
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_localization
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_localization
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_localization
subscriber node         : transform_listener_impl_5bdaab4440f0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_localization
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_localization
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_localization
subscriber node         : transform_listener_impl_61f2b5533050
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_localization
subscriber node         : rviz_navigation_dialog_action_client
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_localization
subscriber node         : transform_listener_impl_61f2b5c3f810
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_localization
subscriber node         : move_group
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_localization
subscriber node         : move_group_private_99865224190016
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_localization
subscriber node         : transform_listener_impl_5ad3af369c80
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_localization
subscriber node         : transform_listener_impl_5ad3afc309a0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_localization
subscriber node         : moveit_simple_controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_localization
subscriber node         : play_motion2
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_localization
subscriber node         : _move_group_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_localization
subscriber node         : twist_mux
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_localization
subscriber node         : twist_marker
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_localization
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : lifecycle_manager_localization
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz
subscriber node         : gazebo
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz
subscriber node         : base_imu
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz
subscriber node         : base_laser
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz
subscriber node         : base_sonar_01_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz
subscriber node         : base_sonar_02_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz
subscriber node         : base_sonar_03_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz
subscriber node         : head_front_camera_frame_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz
subscriber node         : gazebo_ros_odometry
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz
subscriber node         : gazebo_ros2_control
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz
subscriber node         : controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz
subscriber node         : mobile_base_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz
subscriber node         : gripper_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz
subscriber node         : head_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz
subscriber node         : joint_state_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz
subscriber node         : imu_sensor_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz
subscriber node         : arm_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz
subscriber node         : torso_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz
subscriber node         : ft_sensor_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz
subscriber node         : local_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz
subscriber node         : transform_listener_impl_5973afb268b0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz
subscriber node         : transform_listener_impl_654ee1c865e0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz
subscriber node         : global_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz
subscriber node         : transform_listener_impl_623f34f20190
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz
subscriber node         : transform_listener_impl_5ec47a4d1ab0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz
subscriber node         : transform_listener_impl_5bdaab4440f0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz
subscriber node         : transform_listener_impl_61f2b5533050
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz
subscriber node         : rviz_navigation_dialog_action_client
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz
subscriber node         : transform_listener_impl_61f2b5c3f810
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz
subscriber node         : move_group
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz
subscriber node         : move_group_private_99865224190016
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz
subscriber node         : transform_listener_impl_5ad3af369c80
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz
subscriber node         : transform_listener_impl_5ad3afc309a0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz
subscriber node         : moveit_simple_controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz
subscriber node         : play_motion2
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz
subscriber node         : _move_group_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz
subscriber node         : twist_mux
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz
subscriber node         : twist_marker
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz_navigation_dialog_action_client
subscriber node         : gazebo
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz_navigation_dialog_action_client
subscriber node         : base_imu
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz_navigation_dialog_action_client
subscriber node         : base_laser
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz_navigation_dialog_action_client
subscriber node         : base_sonar_01_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz_navigation_dialog_action_client
subscriber node         : base_sonar_02_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz_navigation_dialog_action_client
subscriber node         : base_sonar_03_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz_navigation_dialog_action_client
subscriber node         : head_front_camera_frame_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz_navigation_dialog_action_client
subscriber node         : gazebo_ros_odometry
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz_navigation_dialog_action_client
subscriber node         : gazebo_ros2_control
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz_navigation_dialog_action_client
subscriber node         : controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz_navigation_dialog_action_client
subscriber node         : mobile_base_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz_navigation_dialog_action_client
subscriber node         : gripper_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz_navigation_dialog_action_client
subscriber node         : head_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz_navigation_dialog_action_client
subscriber node         : joint_state_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz_navigation_dialog_action_client
subscriber node         : imu_sensor_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz_navigation_dialog_action_client
subscriber node         : arm_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz_navigation_dialog_action_client
subscriber node         : torso_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz_navigation_dialog_action_client
subscriber node         : ft_sensor_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz_navigation_dialog_action_client
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz_navigation_dialog_action_client
subscriber node         : local_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz_navigation_dialog_action_client
subscriber node         : transform_listener_impl_5973afb268b0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz_navigation_dialog_action_client
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz_navigation_dialog_action_client
subscriber node         : transform_listener_impl_654ee1c865e0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz_navigation_dialog_action_client
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz_navigation_dialog_action_client
subscriber node         : global_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz_navigation_dialog_action_client
subscriber node         : transform_listener_impl_623f34f20190
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz_navigation_dialog_action_client
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz_navigation_dialog_action_client
subscriber node         : transform_listener_impl_5ec47a4d1ab0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz_navigation_dialog_action_client
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz_navigation_dialog_action_client
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz_navigation_dialog_action_client
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz_navigation_dialog_action_client
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz_navigation_dialog_action_client
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz_navigation_dialog_action_client
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz_navigation_dialog_action_client
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz_navigation_dialog_action_client
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz_navigation_dialog_action_client
subscriber node         : transform_listener_impl_5bdaab4440f0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz_navigation_dialog_action_client
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz_navigation_dialog_action_client
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz_navigation_dialog_action_client
subscriber node         : transform_listener_impl_61f2b5533050
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz_navigation_dialog_action_client
subscriber node         : rviz_navigation_dialog_action_client
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz_navigation_dialog_action_client
subscriber node         : transform_listener_impl_61f2b5c3f810
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz_navigation_dialog_action_client
subscriber node         : move_group
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz_navigation_dialog_action_client
subscriber node         : move_group_private_99865224190016
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz_navigation_dialog_action_client
subscriber node         : transform_listener_impl_5ad3af369c80
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz_navigation_dialog_action_client
subscriber node         : transform_listener_impl_5ad3afc309a0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz_navigation_dialog_action_client
subscriber node         : moveit_simple_controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz_navigation_dialog_action_client
subscriber node         : play_motion2
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz_navigation_dialog_action_client
subscriber node         : _move_group_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz_navigation_dialog_action_client
subscriber node         : twist_mux
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz_navigation_dialog_action_client
subscriber node         : twist_marker
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz_navigation_dialog_action_client
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : rviz_navigation_dialog_action_client
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group
subscriber node         : gazebo
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group
subscriber node         : base_imu
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group
subscriber node         : base_laser
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group
subscriber node         : base_sonar_01_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group
subscriber node         : base_sonar_02_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group
subscriber node         : base_sonar_03_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group
subscriber node         : head_front_camera_frame_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group
subscriber node         : gazebo_ros_odometry
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group
subscriber node         : gazebo_ros2_control
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group
subscriber node         : controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group
subscriber node         : mobile_base_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group
subscriber node         : gripper_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group
subscriber node         : head_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group
subscriber node         : joint_state_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group
subscriber node         : imu_sensor_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group
subscriber node         : arm_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group
subscriber node         : torso_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group
subscriber node         : ft_sensor_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group
subscriber node         : local_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group
subscriber node         : transform_listener_impl_5973afb268b0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group
subscriber node         : transform_listener_impl_654ee1c865e0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group
subscriber node         : global_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group
subscriber node         : transform_listener_impl_623f34f20190
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group
subscriber node         : transform_listener_impl_5ec47a4d1ab0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group
subscriber node         : transform_listener_impl_5bdaab4440f0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group
subscriber node         : transform_listener_impl_61f2b5533050
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group
subscriber node         : rviz_navigation_dialog_action_client
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group
subscriber node         : transform_listener_impl_61f2b5c3f810
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group
subscriber node         : move_group
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group
subscriber node         : move_group_private_99865224190016
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group
subscriber node         : transform_listener_impl_5ad3af369c80
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group
subscriber node         : transform_listener_impl_5ad3afc309a0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group
subscriber node         : moveit_simple_controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group
subscriber node         : play_motion2
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group
subscriber node         : _move_group_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group
subscriber node         : twist_mux
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group
subscriber node         : twist_marker
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group_private_99865224190016
subscriber node         : gazebo
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group_private_99865224190016
subscriber node         : base_imu
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group_private_99865224190016
subscriber node         : base_laser
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group_private_99865224190016
subscriber node         : base_sonar_01_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group_private_99865224190016
subscriber node         : base_sonar_02_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group_private_99865224190016
subscriber node         : base_sonar_03_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group_private_99865224190016
subscriber node         : head_front_camera_frame_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group_private_99865224190016
subscriber node         : gazebo_ros_odometry
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group_private_99865224190016
subscriber node         : gazebo_ros2_control
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group_private_99865224190016
subscriber node         : controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group_private_99865224190016
subscriber node         : mobile_base_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group_private_99865224190016
subscriber node         : gripper_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group_private_99865224190016
subscriber node         : head_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group_private_99865224190016
subscriber node         : joint_state_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group_private_99865224190016
subscriber node         : imu_sensor_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group_private_99865224190016
subscriber node         : arm_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group_private_99865224190016
subscriber node         : torso_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group_private_99865224190016
subscriber node         : ft_sensor_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group_private_99865224190016
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group_private_99865224190016
subscriber node         : local_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group_private_99865224190016
subscriber node         : transform_listener_impl_5973afb268b0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group_private_99865224190016
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group_private_99865224190016
subscriber node         : transform_listener_impl_654ee1c865e0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group_private_99865224190016
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group_private_99865224190016
subscriber node         : global_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group_private_99865224190016
subscriber node         : transform_listener_impl_623f34f20190
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group_private_99865224190016
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group_private_99865224190016
subscriber node         : transform_listener_impl_5ec47a4d1ab0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group_private_99865224190016
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group_private_99865224190016
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group_private_99865224190016
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group_private_99865224190016
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group_private_99865224190016
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group_private_99865224190016
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group_private_99865224190016
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group_private_99865224190016
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group_private_99865224190016
subscriber node         : transform_listener_impl_5bdaab4440f0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group_private_99865224190016
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group_private_99865224190016
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group_private_99865224190016
subscriber node         : transform_listener_impl_61f2b5533050
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group_private_99865224190016
subscriber node         : rviz_navigation_dialog_action_client
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group_private_99865224190016
subscriber node         : transform_listener_impl_61f2b5c3f810
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group_private_99865224190016
subscriber node         : move_group
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group_private_99865224190016
subscriber node         : move_group_private_99865224190016
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group_private_99865224190016
subscriber node         : transform_listener_impl_5ad3af369c80
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group_private_99865224190016
subscriber node         : transform_listener_impl_5ad3afc309a0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group_private_99865224190016
subscriber node         : moveit_simple_controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group_private_99865224190016
subscriber node         : play_motion2
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group_private_99865224190016
subscriber node         : _move_group_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group_private_99865224190016
subscriber node         : twist_mux
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group_private_99865224190016
subscriber node         : twist_marker
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group_private_99865224190016
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : move_group_private_99865224190016
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : moveit_simple_controller_manager
subscriber node         : gazebo
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : moveit_simple_controller_manager
subscriber node         : base_imu
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : moveit_simple_controller_manager
subscriber node         : base_laser
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : moveit_simple_controller_manager
subscriber node         : base_sonar_01_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : moveit_simple_controller_manager
subscriber node         : base_sonar_02_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : moveit_simple_controller_manager
subscriber node         : base_sonar_03_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : moveit_simple_controller_manager
subscriber node         : head_front_camera_frame_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : moveit_simple_controller_manager
subscriber node         : gazebo_ros_odometry
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : moveit_simple_controller_manager
subscriber node         : gazebo_ros2_control
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : moveit_simple_controller_manager
subscriber node         : controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : moveit_simple_controller_manager
subscriber node         : mobile_base_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : moveit_simple_controller_manager
subscriber node         : gripper_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : moveit_simple_controller_manager
subscriber node         : head_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : moveit_simple_controller_manager
subscriber node         : joint_state_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : moveit_simple_controller_manager
subscriber node         : imu_sensor_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : moveit_simple_controller_manager
subscriber node         : arm_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : moveit_simple_controller_manager
subscriber node         : torso_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : moveit_simple_controller_manager
subscriber node         : ft_sensor_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : moveit_simple_controller_manager
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : moveit_simple_controller_manager
subscriber node         : local_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : moveit_simple_controller_manager
subscriber node         : transform_listener_impl_5973afb268b0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : moveit_simple_controller_manager
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : moveit_simple_controller_manager
subscriber node         : transform_listener_impl_654ee1c865e0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : moveit_simple_controller_manager
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : moveit_simple_controller_manager
subscriber node         : global_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : moveit_simple_controller_manager
subscriber node         : transform_listener_impl_623f34f20190
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : moveit_simple_controller_manager
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : moveit_simple_controller_manager
subscriber node         : transform_listener_impl_5ec47a4d1ab0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : moveit_simple_controller_manager
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : moveit_simple_controller_manager
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : moveit_simple_controller_manager
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : moveit_simple_controller_manager
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : moveit_simple_controller_manager
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : moveit_simple_controller_manager
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : moveit_simple_controller_manager
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : moveit_simple_controller_manager
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : moveit_simple_controller_manager
subscriber node         : transform_listener_impl_5bdaab4440f0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : moveit_simple_controller_manager
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : moveit_simple_controller_manager
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : moveit_simple_controller_manager
subscriber node         : transform_listener_impl_61f2b5533050
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : moveit_simple_controller_manager
subscriber node         : rviz_navigation_dialog_action_client
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : moveit_simple_controller_manager
subscriber node         : transform_listener_impl_61f2b5c3f810
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : moveit_simple_controller_manager
subscriber node         : move_group
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : moveit_simple_controller_manager
subscriber node         : move_group_private_99865224190016
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : moveit_simple_controller_manager
subscriber node         : transform_listener_impl_5ad3af369c80
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : moveit_simple_controller_manager
subscriber node         : transform_listener_impl_5ad3afc309a0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : moveit_simple_controller_manager
subscriber node         : moveit_simple_controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : moveit_simple_controller_manager
subscriber node         : play_motion2
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : moveit_simple_controller_manager
subscriber node         : _move_group_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : moveit_simple_controller_manager
subscriber node         : twist_mux
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : moveit_simple_controller_manager
subscriber node         : twist_marker
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : moveit_simple_controller_manager
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : moveit_simple_controller_manager
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : play_motion2
subscriber node         : gazebo
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : play_motion2
subscriber node         : base_imu
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : play_motion2
subscriber node         : base_laser
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : play_motion2
subscriber node         : base_sonar_01_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : play_motion2
subscriber node         : base_sonar_02_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : play_motion2
subscriber node         : base_sonar_03_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : play_motion2
subscriber node         : head_front_camera_frame_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : play_motion2
subscriber node         : gazebo_ros_odometry
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : play_motion2
subscriber node         : gazebo_ros2_control
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : play_motion2
subscriber node         : controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : play_motion2
subscriber node         : mobile_base_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : play_motion2
subscriber node         : gripper_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : play_motion2
subscriber node         : head_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : play_motion2
subscriber node         : joint_state_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : play_motion2
subscriber node         : imu_sensor_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : play_motion2
subscriber node         : arm_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : play_motion2
subscriber node         : torso_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : play_motion2
subscriber node         : ft_sensor_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : play_motion2
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : play_motion2
subscriber node         : local_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : play_motion2
subscriber node         : transform_listener_impl_5973afb268b0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : play_motion2
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : play_motion2
subscriber node         : transform_listener_impl_654ee1c865e0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : play_motion2
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : play_motion2
subscriber node         : global_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : play_motion2
subscriber node         : transform_listener_impl_623f34f20190
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : play_motion2
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : play_motion2
subscriber node         : transform_listener_impl_5ec47a4d1ab0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : play_motion2
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : play_motion2
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : play_motion2
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : play_motion2
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : play_motion2
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : play_motion2
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : play_motion2
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : play_motion2
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : play_motion2
subscriber node         : transform_listener_impl_5bdaab4440f0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : play_motion2
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : play_motion2
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : play_motion2
subscriber node         : transform_listener_impl_61f2b5533050
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : play_motion2
subscriber node         : rviz_navigation_dialog_action_client
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : play_motion2
subscriber node         : transform_listener_impl_61f2b5c3f810
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : play_motion2
subscriber node         : move_group
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : play_motion2
subscriber node         : move_group_private_99865224190016
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : play_motion2
subscriber node         : transform_listener_impl_5ad3af369c80
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : play_motion2
subscriber node         : transform_listener_impl_5ad3afc309a0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : play_motion2
subscriber node         : moveit_simple_controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : play_motion2
subscriber node         : play_motion2
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : play_motion2
subscriber node         : _move_group_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : play_motion2
subscriber node         : twist_mux
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : play_motion2
subscriber node         : twist_marker
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : play_motion2
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : play_motion2
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _move_group_node
subscriber node         : gazebo
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _move_group_node
subscriber node         : base_imu
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _move_group_node
subscriber node         : base_laser
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _move_group_node
subscriber node         : base_sonar_01_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _move_group_node
subscriber node         : base_sonar_02_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _move_group_node
subscriber node         : base_sonar_03_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _move_group_node
subscriber node         : head_front_camera_frame_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _move_group_node
subscriber node         : gazebo_ros_odometry
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _move_group_node
subscriber node         : gazebo_ros2_control
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _move_group_node
subscriber node         : controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _move_group_node
subscriber node         : mobile_base_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _move_group_node
subscriber node         : gripper_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _move_group_node
subscriber node         : head_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _move_group_node
subscriber node         : joint_state_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _move_group_node
subscriber node         : imu_sensor_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _move_group_node
subscriber node         : arm_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _move_group_node
subscriber node         : torso_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _move_group_node
subscriber node         : ft_sensor_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _move_group_node
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _move_group_node
subscriber node         : local_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _move_group_node
subscriber node         : transform_listener_impl_5973afb268b0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _move_group_node
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _move_group_node
subscriber node         : transform_listener_impl_654ee1c865e0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _move_group_node
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _move_group_node
subscriber node         : global_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _move_group_node
subscriber node         : transform_listener_impl_623f34f20190
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _move_group_node
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _move_group_node
subscriber node         : transform_listener_impl_5ec47a4d1ab0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _move_group_node
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _move_group_node
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _move_group_node
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _move_group_node
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _move_group_node
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _move_group_node
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _move_group_node
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _move_group_node
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _move_group_node
subscriber node         : transform_listener_impl_5bdaab4440f0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _move_group_node
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _move_group_node
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _move_group_node
subscriber node         : transform_listener_impl_61f2b5533050
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _move_group_node
subscriber node         : rviz_navigation_dialog_action_client
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _move_group_node
subscriber node         : transform_listener_impl_61f2b5c3f810
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _move_group_node
subscriber node         : move_group
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _move_group_node
subscriber node         : move_group_private_99865224190016
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _move_group_node
subscriber node         : transform_listener_impl_5ad3af369c80
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _move_group_node
subscriber node         : transform_listener_impl_5ad3afc309a0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _move_group_node
subscriber node         : moveit_simple_controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _move_group_node
subscriber node         : play_motion2
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _move_group_node
subscriber node         : _move_group_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _move_group_node
subscriber node         : twist_mux
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _move_group_node
subscriber node         : twist_marker
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _move_group_node
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : _move_group_node
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_mux
subscriber node         : gazebo
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_mux
subscriber node         : base_imu
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_mux
subscriber node         : base_laser
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_mux
subscriber node         : base_sonar_01_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_mux
subscriber node         : base_sonar_02_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_mux
subscriber node         : base_sonar_03_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_mux
subscriber node         : head_front_camera_frame_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_mux
subscriber node         : gazebo_ros_odometry
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_mux
subscriber node         : gazebo_ros2_control
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_mux
subscriber node         : controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_mux
subscriber node         : mobile_base_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_mux
subscriber node         : gripper_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_mux
subscriber node         : head_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_mux
subscriber node         : joint_state_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_mux
subscriber node         : imu_sensor_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_mux
subscriber node         : arm_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_mux
subscriber node         : torso_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_mux
subscriber node         : ft_sensor_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_mux
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_mux
subscriber node         : local_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_mux
subscriber node         : transform_listener_impl_5973afb268b0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_mux
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_mux
subscriber node         : transform_listener_impl_654ee1c865e0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_mux
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_mux
subscriber node         : global_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_mux
subscriber node         : transform_listener_impl_623f34f20190
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_mux
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_mux
subscriber node         : transform_listener_impl_5ec47a4d1ab0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_mux
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_mux
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_mux
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_mux
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_mux
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_mux
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_mux
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_mux
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_mux
subscriber node         : transform_listener_impl_5bdaab4440f0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_mux
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_mux
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_mux
subscriber node         : transform_listener_impl_61f2b5533050
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_mux
subscriber node         : rviz_navigation_dialog_action_client
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_mux
subscriber node         : transform_listener_impl_61f2b5c3f810
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_mux
subscriber node         : move_group
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_mux
subscriber node         : move_group_private_99865224190016
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_mux
subscriber node         : transform_listener_impl_5ad3af369c80
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_mux
subscriber node         : transform_listener_impl_5ad3afc309a0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_mux
subscriber node         : moveit_simple_controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_mux
subscriber node         : play_motion2
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_mux
subscriber node         : _move_group_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_mux
subscriber node         : twist_mux
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_mux
subscriber node         : twist_marker
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_mux
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_mux
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_marker
subscriber node         : gazebo
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_marker
subscriber node         : base_imu
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_marker
subscriber node         : base_laser
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_marker
subscriber node         : base_sonar_01_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_marker
subscriber node         : base_sonar_02_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_marker
subscriber node         : base_sonar_03_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_marker
subscriber node         : head_front_camera_frame_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_marker
subscriber node         : gazebo_ros_odometry
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_marker
subscriber node         : gazebo_ros2_control
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_marker
subscriber node         : controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_marker
subscriber node         : mobile_base_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_marker
subscriber node         : gripper_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_marker
subscriber node         : head_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_marker
subscriber node         : joint_state_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_marker
subscriber node         : imu_sensor_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_marker
subscriber node         : arm_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_marker
subscriber node         : torso_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_marker
subscriber node         : ft_sensor_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_marker
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_marker
subscriber node         : local_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_marker
subscriber node         : transform_listener_impl_5973afb268b0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_marker
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_marker
subscriber node         : transform_listener_impl_654ee1c865e0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_marker
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_marker
subscriber node         : global_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_marker
subscriber node         : transform_listener_impl_623f34f20190
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_marker
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_marker
subscriber node         : transform_listener_impl_5ec47a4d1ab0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_marker
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_marker
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_marker
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_marker
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_marker
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_marker
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_marker
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_marker
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_marker
subscriber node         : transform_listener_impl_5bdaab4440f0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_marker
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_marker
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_marker
subscriber node         : transform_listener_impl_61f2b5533050
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_marker
subscriber node         : rviz_navigation_dialog_action_client
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_marker
subscriber node         : transform_listener_impl_61f2b5c3f810
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_marker
subscriber node         : move_group
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_marker
subscriber node         : move_group_private_99865224190016
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_marker
subscriber node         : transform_listener_impl_5ad3af369c80
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_marker
subscriber node         : transform_listener_impl_5ad3afc309a0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_marker
subscriber node         : moveit_simple_controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_marker
subscriber node         : play_motion2
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_marker
subscriber node         : _move_group_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_marker
subscriber node         : twist_mux
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_marker
subscriber node         : twist_marker
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_marker
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : twist_marker
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joystick_relay
subscriber node         : gazebo
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joystick_relay
subscriber node         : base_imu
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joystick_relay
subscriber node         : base_laser
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joystick_relay
subscriber node         : base_sonar_01_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joystick_relay
subscriber node         : base_sonar_02_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joystick_relay
subscriber node         : base_sonar_03_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joystick_relay
subscriber node         : head_front_camera_frame_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joystick_relay
subscriber node         : gazebo_ros_odometry
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joystick_relay
subscriber node         : gazebo_ros2_control
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joystick_relay
subscriber node         : controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joystick_relay
subscriber node         : mobile_base_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joystick_relay
subscriber node         : gripper_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joystick_relay
subscriber node         : head_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joystick_relay
subscriber node         : joint_state_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joystick_relay
subscriber node         : imu_sensor_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joystick_relay
subscriber node         : arm_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joystick_relay
subscriber node         : torso_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joystick_relay
subscriber node         : ft_sensor_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joystick_relay
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joystick_relay
subscriber node         : local_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joystick_relay
subscriber node         : transform_listener_impl_5973afb268b0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joystick_relay
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joystick_relay
subscriber node         : transform_listener_impl_654ee1c865e0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joystick_relay
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joystick_relay
subscriber node         : global_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joystick_relay
subscriber node         : transform_listener_impl_623f34f20190
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joystick_relay
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joystick_relay
subscriber node         : transform_listener_impl_5ec47a4d1ab0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joystick_relay
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joystick_relay
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joystick_relay
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joystick_relay
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joystick_relay
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joystick_relay
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joystick_relay
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joystick_relay
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joystick_relay
subscriber node         : transform_listener_impl_5bdaab4440f0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joystick_relay
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joystick_relay
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joystick_relay
subscriber node         : transform_listener_impl_61f2b5533050
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joystick_relay
subscriber node         : rviz_navigation_dialog_action_client
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joystick_relay
subscriber node         : transform_listener_impl_61f2b5c3f810
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joystick_relay
subscriber node         : move_group
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joystick_relay
subscriber node         : move_group_private_99865224190016
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joystick_relay
subscriber node         : transform_listener_impl_5ad3af369c80
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joystick_relay
subscriber node         : transform_listener_impl_5ad3afc309a0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joystick_relay
subscriber node         : moveit_simple_controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joystick_relay
subscriber node         : play_motion2
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joystick_relay
subscriber node         : _move_group_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joystick_relay
subscriber node         : twist_mux
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joystick_relay
subscriber node         : twist_marker
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joystick_relay
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : joystick_relay
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : robot_state_publisher
subscriber node         : gazebo
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : robot_state_publisher
subscriber node         : base_imu
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : robot_state_publisher
subscriber node         : base_laser
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : robot_state_publisher
subscriber node         : base_sonar_01_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : robot_state_publisher
subscriber node         : base_sonar_02_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : robot_state_publisher
subscriber node         : base_sonar_03_gazebo_ros_range
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : robot_state_publisher
subscriber node         : head_front_camera_frame_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : robot_state_publisher
subscriber node         : gazebo_ros_odometry
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : robot_state_publisher
subscriber node         : gazebo_ros2_control
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : robot_state_publisher
subscriber node         : controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : robot_state_publisher
subscriber node         : mobile_base_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : robot_state_publisher
subscriber node         : gripper_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : robot_state_publisher
subscriber node         : head_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : robot_state_publisher
subscriber node         : joint_state_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : robot_state_publisher
subscriber node         : imu_sensor_broadcaster
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : robot_state_publisher
subscriber node         : arm_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : robot_state_publisher
subscriber node         : torso_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : robot_state_publisher
subscriber node         : ft_sensor_controller
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : robot_state_publisher
subscriber node         : controller_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : robot_state_publisher
subscriber node         : local_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : robot_state_publisher
subscriber node         : transform_listener_impl_5973afb268b0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : robot_state_publisher
subscriber node         : smoother_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : robot_state_publisher
subscriber node         : transform_listener_impl_654ee1c865e0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : robot_state_publisher
subscriber node         : planner_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : robot_state_publisher
subscriber node         : global_costmap
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : robot_state_publisher
subscriber node         : transform_listener_impl_623f34f20190
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : robot_state_publisher
subscriber node         : behavior_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : robot_state_publisher
subscriber node         : transform_listener_impl_5ec47a4d1ab0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : robot_state_publisher
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : robot_state_publisher
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : robot_state_publisher
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : robot_state_publisher
subscriber node         : waypoint_follower
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : robot_state_publisher
subscriber node         : velocity_smoother
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : robot_state_publisher
subscriber node         : lifecycle_manager_navigation
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : robot_state_publisher
subscriber node         : map_server
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : robot_state_publisher
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : robot_state_publisher
subscriber node         : transform_listener_impl_5bdaab4440f0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : robot_state_publisher
subscriber node         : lifecycle_manager_localization
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : robot_state_publisher
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : robot_state_publisher
subscriber node         : transform_listener_impl_61f2b5533050
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : robot_state_publisher
subscriber node         : rviz_navigation_dialog_action_client
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : robot_state_publisher
subscriber node         : transform_listener_impl_61f2b5c3f810
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : robot_state_publisher
subscriber node         : move_group
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : robot_state_publisher
subscriber node         : move_group_private_99865224190016
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : robot_state_publisher
subscriber node         : transform_listener_impl_5ad3af369c80
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : robot_state_publisher
subscriber node         : transform_listener_impl_5ad3afc309a0
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : robot_state_publisher
subscriber node         : moveit_simple_controller_manager
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : robot_state_publisher
subscriber node         : play_motion2
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : robot_state_publisher
subscriber node         : _move_group_node
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : robot_state_publisher
subscriber node         : twist_mux
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : robot_state_publisher
subscriber node         : twist_marker
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : robot_state_publisher
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /parameter_events [rcl_interfaces/msg/ParameterEvent]
publisher node          : robot_state_publisher
subscriber node         : robot_state_publisher
compatibility status    : OK
topic [type]            : /particle_cloud [nav2_msgs/msg/ParticleCloud]
publisher node          : amcl
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /plan [nav_msgs/msg/Path]
publisher node          : planner_server
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /robot_description [std_msgs/msg/String]
publisher node          : robot_state_publisher
subscriber node         : rviz
compatibility status    : OK
topic [type]            : /scan_raw [sensor_msgs/msg/LaserScan]
publisher node          : base_laser
subscriber node         : local_costmap
compatibility status    : OK
topic [type]            : /scan_raw [sensor_msgs/msg/LaserScan]
publisher node          : base_laser
subscriber node         : global_costmap
compatibility status    : OK
topic [type]            : /scan_raw [sensor_msgs/msg/LaserScan]
publisher node          : base_laser
subscriber node         : amcl
compatibility status    : OK
topic [type]            : /spin/_action/feedback [nav2_msgs/action/Spin_FeedbackMessage]
publisher node          : behavior_server
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /spin/_action/feedback [nav2_msgs/action/Spin_FeedbackMessage]
publisher node          : behavior_server
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /spin/_action/status [action_msgs/msg/GoalStatusArray]
publisher node          : behavior_server
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /spin/_action/status [action_msgs/msg/GoalStatusArray]
publisher node          : behavior_server
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /tf [tf2_msgs/msg/TFMessage]
publisher node          : mobile_base_controller
subscriber node         : transform_listener_impl_5973afb268b0
compatibility status    : OK
topic [type]            : /tf [tf2_msgs/msg/TFMessage]
publisher node          : mobile_base_controller
subscriber node         : transform_listener_impl_654ee1c865e0
compatibility status    : OK
topic [type]            : /tf [tf2_msgs/msg/TFMessage]
publisher node          : mobile_base_controller
subscriber node         : transform_listener_impl_623f34f20190
compatibility status    : OK
topic [type]            : /tf [tf2_msgs/msg/TFMessage]
publisher node          : mobile_base_controller
subscriber node         : transform_listener_impl_5ec47a4d1ab0
compatibility status    : OK
topic [type]            : /tf [tf2_msgs/msg/TFMessage]
publisher node          : mobile_base_controller
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /tf [tf2_msgs/msg/TFMessage]
publisher node          : mobile_base_controller
subscriber node         : transform_listener_impl_5bdaab4440f0
compatibility status    : OK
topic [type]            : /tf [tf2_msgs/msg/TFMessage]
publisher node          : mobile_base_controller
subscriber node         : transform_listener_impl_61f2b5533050
compatibility status    : OK
topic [type]            : /tf [tf2_msgs/msg/TFMessage]
publisher node          : mobile_base_controller
subscriber node         : transform_listener_impl_61f2b5c3f810
compatibility status    : OK
topic [type]            : /tf [tf2_msgs/msg/TFMessage]
publisher node          : mobile_base_controller
subscriber node         : transform_listener_impl_5ad3af369c80
compatibility status    : OK
topic [type]            : /tf [tf2_msgs/msg/TFMessage]
publisher node          : mobile_base_controller
subscriber node         : transform_listener_impl_5ad3afc309a0
compatibility status    : OK
topic [type]            : /tf [tf2_msgs/msg/TFMessage]
publisher node          : amcl
subscriber node         : transform_listener_impl_5973afb268b0
compatibility status    : OK
topic [type]            : /tf [tf2_msgs/msg/TFMessage]
publisher node          : amcl
subscriber node         : transform_listener_impl_654ee1c865e0
compatibility status    : OK
topic [type]            : /tf [tf2_msgs/msg/TFMessage]
publisher node          : amcl
subscriber node         : transform_listener_impl_623f34f20190
compatibility status    : OK
topic [type]            : /tf [tf2_msgs/msg/TFMessage]
publisher node          : amcl
subscriber node         : transform_listener_impl_5ec47a4d1ab0
compatibility status    : OK
topic [type]            : /tf [tf2_msgs/msg/TFMessage]
publisher node          : amcl
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /tf [tf2_msgs/msg/TFMessage]
publisher node          : amcl
subscriber node         : transform_listener_impl_5bdaab4440f0
compatibility status    : OK
topic [type]            : /tf [tf2_msgs/msg/TFMessage]
publisher node          : amcl
subscriber node         : transform_listener_impl_61f2b5533050
compatibility status    : OK
topic [type]            : /tf [tf2_msgs/msg/TFMessage]
publisher node          : amcl
subscriber node         : transform_listener_impl_61f2b5c3f810
compatibility status    : OK
topic [type]            : /tf [tf2_msgs/msg/TFMessage]
publisher node          : amcl
subscriber node         : transform_listener_impl_5ad3af369c80
compatibility status    : OK
topic [type]            : /tf [tf2_msgs/msg/TFMessage]
publisher node          : amcl
subscriber node         : transform_listener_impl_5ad3afc309a0
compatibility status    : OK
topic [type]            : /tf [tf2_msgs/msg/TFMessage]
publisher node          : robot_state_publisher
subscriber node         : transform_listener_impl_5973afb268b0
compatibility status    : OK
topic [type]            : /tf [tf2_msgs/msg/TFMessage]
publisher node          : robot_state_publisher
subscriber node         : transform_listener_impl_654ee1c865e0
compatibility status    : OK
topic [type]            : /tf [tf2_msgs/msg/TFMessage]
publisher node          : robot_state_publisher
subscriber node         : transform_listener_impl_623f34f20190
compatibility status    : OK
topic [type]            : /tf [tf2_msgs/msg/TFMessage]
publisher node          : robot_state_publisher
subscriber node         : transform_listener_impl_5ec47a4d1ab0
compatibility status    : OK
topic [type]            : /tf [tf2_msgs/msg/TFMessage]
publisher node          : robot_state_publisher
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /tf [tf2_msgs/msg/TFMessage]
publisher node          : robot_state_publisher
subscriber node         : transform_listener_impl_5bdaab4440f0
compatibility status    : OK
topic [type]            : /tf [tf2_msgs/msg/TFMessage]
publisher node          : robot_state_publisher
subscriber node         : transform_listener_impl_61f2b5533050
compatibility status    : OK
topic [type]            : /tf [tf2_msgs/msg/TFMessage]
publisher node          : robot_state_publisher
subscriber node         : transform_listener_impl_61f2b5c3f810
compatibility status    : OK
topic [type]            : /tf [tf2_msgs/msg/TFMessage]
publisher node          : robot_state_publisher
subscriber node         : transform_listener_impl_5ad3af369c80
compatibility status    : OK
topic [type]            : /tf [tf2_msgs/msg/TFMessage]
publisher node          : robot_state_publisher
subscriber node         : transform_listener_impl_5ad3afc309a0
compatibility status    : OK
topic [type]            : /tf_static [tf2_msgs/msg/TFMessage]
publisher node          : robot_state_publisher
subscriber node         : transform_listener_impl_5973afb268b0
compatibility status    : OK
topic [type]            : /tf_static [tf2_msgs/msg/TFMessage]
publisher node          : robot_state_publisher
subscriber node         : transform_listener_impl_654ee1c865e0
compatibility status    : OK
topic [type]            : /tf_static [tf2_msgs/msg/TFMessage]
publisher node          : robot_state_publisher
subscriber node         : transform_listener_impl_623f34f20190
compatibility status    : OK
topic [type]            : /tf_static [tf2_msgs/msg/TFMessage]
publisher node          : robot_state_publisher
subscriber node         : transform_listener_impl_5ec47a4d1ab0
compatibility status    : OK
topic [type]            : /tf_static [tf2_msgs/msg/TFMessage]
publisher node          : robot_state_publisher
subscriber node         : bt_navigator
compatibility status    : OK
topic [type]            : /tf_static [tf2_msgs/msg/TFMessage]
publisher node          : robot_state_publisher
subscriber node         : transform_listener_impl_5bdaab4440f0
compatibility status    : OK
topic [type]            : /tf_static [tf2_msgs/msg/TFMessage]
publisher node          : robot_state_publisher
subscriber node         : transform_listener_impl_61f2b5533050
compatibility status    : OK
topic [type]            : /tf_static [tf2_msgs/msg/TFMessage]
publisher node          : robot_state_publisher
subscriber node         : transform_listener_impl_61f2b5c3f810
compatibility status    : OK
topic [type]            : /tf_static [tf2_msgs/msg/TFMessage]
publisher node          : robot_state_publisher
subscriber node         : transform_listener_impl_5ad3af369c80
compatibility status    : OK
topic [type]            : /tf_static [tf2_msgs/msg/TFMessage]
publisher node          : robot_state_publisher
subscriber node         : transform_listener_impl_5ad3afc309a0
compatibility status    : OK
topic [type]            : /torso_controller/follow_joint_trajectory/_action/feedback [control_msgs/action/FollowJointTrajectory_FeedbackMessage]
publisher node          : torso_controller
subscriber node         : moveit_simple_controller_manager
compatibility status    : OK
topic [type]            : /torso_controller/follow_joint_trajectory/_action/feedback [control_msgs/action/FollowJointTrajectory_FeedbackMessage]
publisher node          : torso_controller
subscriber node         : play_motion2
compatibility status    : OK
topic [type]            : /torso_controller/follow_joint_trajectory/_action/status [action_msgs/msg/GoalStatusArray]
publisher node          : torso_controller
subscriber node         : moveit_simple_controller_manager
compatibility status    : OK
topic [type]            : /torso_controller/follow_joint_trajectory/_action/status [action_msgs/msg/GoalStatusArray]
publisher node          : torso_controller
subscriber node         : play_motion2
compatibility status    : OK
topic [type]            : /trajectory_execution_event [std_msgs/msg/String]
publisher node          : _move_group_node
subscriber node         : move_group
compatibility status    : OK
topic [type]            : /trajectory_execution_event [std_msgs/msg/String]
publisher node          : _move_group_node
subscriber node         : move_group
compatibility status    : OK
topic [type]            : /wait/_action/feedback [nav2_msgs/action/Wait_FeedbackMessage]
publisher node          : behavior_server
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /wait/_action/feedback [nav2_msgs/action/Wait_FeedbackMessage]
publisher node          : behavior_server
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /wait/_action/status [action_msgs/msg/GoalStatusArray]
publisher node          : behavior_server
subscriber node         : bt_navigator_navigate_to_pose_rclcpp_node
compatibility status    : OK
topic [type]            : /wait/_action/status [action_msgs/msg/GoalStatusArray]
publisher node          : behavior_server
subscriber node         : bt_navigator_navigate_through_poses_rclcpp_node
compatibility status    : OK
topic [type]            : /waypoints [visualization_msgs/msg/MarkerArray]
publisher node          : rviz_navigation_dialog_action_client
subscriber node         : rviz
compatibility status    : OK

   RMW MIDDLEWARE
middleware name    : rmw_fastrtps_cpp

   ROS 2 INFORMATION
distribution name      : iron
distribution type      : ros2
distribution status    : end-of-life
release platforms      : {'rhel': ['9'], 'ubuntu': ['jammy']}

   TOPIC LIST
topic               : /amcl/transition_event
publisher count     : 1
subscriber count    : 0
topic               : /amcl_pose
publisher count     : 1
subscriber count    : 0
topic               : /arm_controller/controller_state
publisher count     : 1
subscriber count    : 0
topic               : /arm_controller/follow_joint_trajectory/_action/feedback
publisher count     : 1
subscriber count    : 1
topic               : /arm_controller/follow_joint_trajectory/_action/status
publisher count     : 1
subscriber count    : 1
topic               : /arm_controller/joint_trajectory
publisher count     : 0
subscriber count    : 0
topic               : /arm_controller/transition_event
publisher count     : 1
subscriber count    : 0
topic               : /attached_collision_object
publisher count     : 2
subscriber count    : 0
topic               : /backup/_action/feedback
publisher count     : 1
subscriber count    : 0
topic               : /backup/_action/status
publisher count     : 1
subscriber count    : 0
topic               : /base_imu
publisher count     : 1
subscriber count    : 0
topic               : /behavior_server/transition_event
publisher count     : 1
subscriber count    : 0
topic               : /behavior_tree_log
publisher count     : 0
subscriber count    : 0
topic               : /bond
publisher count     : 15
subscriber count    : 2
topic               : /bt_navigator/transition_event
publisher count     : 0
subscriber count    : 0
topic               : /clicked_point
publisher count     : 0
subscriber count    : 0
topic               : /clock
publisher count     : 1
subscriber count    : 4
topic               : /cmd_vel
publisher count     : 4
subscriber count    : 1
topic               : /cmd_vel_nav
publisher count     : 1
subscriber count    : 1
topic               : /collision_object
publisher count     : 0
subscriber count    : 0
topic               : /compute_path_through_poses/_action/feedback
publisher count     : 1
subscriber count    : 0
topic               : /compute_path_through_poses/_action/status
publisher count     : 1
subscriber count    : 0
topic               : /compute_path_to_pose/_action/feedback
publisher count     : 1
subscriber count    : 0
topic               : /compute_path_to_pose/_action/status
publisher count     : 1
subscriber count    : 0
topic               : /controller_manager/robot_description
publisher count     : 0
subscriber count    : 0
topic               : /controller_server/transition_event
publisher count     : 1
subscriber count    : 0
topic               : /cost_cloud
publisher count     : 1
subscriber count    : 0
topic               : /diagnostics
publisher count     : 4
subscriber count    : 0
topic               : /display_contacts
publisher count     : 1
subscriber count    : 0
topic               : /display_planned_path
publisher count     : 2
subscriber count    : 0
topic               : /downsampled_costmap
publisher count     : 0
subscriber count    : 1
topic               : /downsampled_costmap_updates
publisher count     : 0
subscriber count    : 1
topic               : /drive_on_heading/_action/feedback
publisher count     : 1
subscriber count    : 0
topic               : /drive_on_heading/_action/status
publisher count     : 1
subscriber count    : 0
topic               : /dynamic_joint_states
publisher count     : 1
subscriber count    : 0
topic               : /evaluation
publisher count     : 1
subscriber count    : 0
topic               : /execute_trajectory/_action/feedback
publisher count     : 1
subscriber count    : 2
topic               : /execute_trajectory/_action/status
publisher count     : 1
subscriber count    : 2
topic               : /filtered_cloud
publisher count     : 1
subscriber count    : 0
topic               : /follow_gps_waypoints/_action/feedback
publisher count     : 1
subscriber count    : 0
topic               : /follow_gps_waypoints/_action/status
publisher count     : 1
subscriber count    : 0
topic               : /follow_path/_action/feedback
publisher count     : 1
subscriber count    : 0
topic               : /follow_path/_action/status
publisher count     : 1
subscriber count    : 0
topic               : /follow_waypoints/_action/feedback
publisher count     : 1
subscriber count    : 1
topic               : /follow_waypoints/_action/status
publisher count     : 1
subscriber count    : 1
topic               : /ft_sensor_controller/transition_event
publisher count     : 1
subscriber count    : 0
topic               : /ft_sensor_controller/wrench
publisher count     : 1
subscriber count    : 0
topic               : /global_costmap/costmap
publisher count     : 1
subscriber count    : 1
topic               : /global_costmap/costmap_raw
publisher count     : 1
subscriber count    : 0
topic               : /global_costmap/costmap_updates
publisher count     : 1
subscriber count    : 1
topic               : /global_costmap/footprint
publisher count     : 0
subscriber count    : 0
topic               : /global_costmap/global_costmap/transition_event
publisher count     : 1
subscriber count    : 0
topic               : /global_costmap/obstacle_layer
publisher count     : 1
subscriber count    : 0
topic               : /global_costmap/obstacle_layer_raw
publisher count     : 1
subscriber count    : 0
topic               : /global_costmap/obstacle_layer_updates
publisher count     : 1
subscriber count    : 0
topic               : /global_costmap/published_footprint
publisher count     : 1
subscriber count    : 0
topic               : /global_costmap/static_layer
publisher count     : 1
subscriber count    : 0
topic               : /global_costmap/static_layer_raw
publisher count     : 1
subscriber count    : 0
topic               : /global_costmap/static_layer_updates
publisher count     : 1
subscriber count    : 0
topic               : /global_costmap/voxel_marked_cloud
publisher count     : 0
subscriber count    : 1
topic               : /goal_pose
publisher count     : 0
subscriber count    : 0
topic               : /gripper_controller/controller_state
publisher count     : 1
subscriber count    : 0
topic               : /gripper_controller/follow_joint_trajectory/_action/feedback
publisher count     : 1
subscriber count    : 0
topic               : /gripper_controller/follow_joint_trajectory/_action/status
publisher count     : 1
subscriber count    : 0
topic               : /gripper_controller/joint_trajectory
publisher count     : 0
subscriber count    : 0
topic               : /gripper_controller/transition_event
publisher count     : 1
subscriber count    : 0
topic               : /ground_truth_odom
publisher count     : 1
subscriber count    : 0
topic               : /head_controller/controller_state
publisher count     : 1
subscriber count    : 0
topic               : /head_controller/follow_joint_trajectory/_action/feedback
publisher count     : 1
subscriber count    : 0
topic               : /head_controller/follow_joint_trajectory/_action/status
publisher count     : 1
subscriber count    : 0
topic               : /head_controller/joint_trajectory
publisher count     : 0
subscriber count    : 0
topic               : /head_controller/transition_event
publisher count     : 1
subscriber count    : 0
topic               : /head_front_camera/depth_registered/camera_info
publisher count     : 1
subscriber count    : 0
topic               : /head_front_camera/depth_registered/image_raw
publisher count     : 1
subscriber count    : 0
topic               : /head_front_camera/depth_registered/points
publisher count     : 1
subscriber count    : 0
topic               : /head_front_camera/rgb/camera_info
publisher count     : 1
subscriber count    : 0
topic               : /head_front_camera/rgb/image_raw
publisher count     : 1
subscriber count    : 0
topic               : /imu_sensor_broadcaster/imu
publisher count     : 1
subscriber count    : 0
topic               : /imu_sensor_broadcaster/transition_event
publisher count     : 1
subscriber count    : 0
topic               : /initialpose
publisher count     : 0
subscriber count    : 0
topic               : /input_joy/cmd_vel
publisher count     : 0
subscriber count    : 0
topic               : /joint_state_broadcaster/transition_event
publisher count     : 1
subscriber count    : 0
topic               : /joint_states
publisher count     : 1
subscriber count    : 2
topic               : /joy_priority
publisher count     : 1
subscriber count    : 1
topic               : /joy_priority_action/_action/feedback
publisher count     : 1
subscriber count    : 0
topic               : /joy_priority_action/_action/status
publisher count     : 1
subscriber count    : 0
topic               : /joy_turbo_angular_decrease/_action/feedback
publisher count     : 1
subscriber count    : 0
topic               : /joy_turbo_angular_decrease/_action/status
publisher count     : 1
subscriber count    : 0
topic               : /joy_turbo_angular_increase/_action/feedback
publisher count     : 1
subscriber count    : 0
topic               : /joy_turbo_angular_increase/_action/status
publisher count     : 1
subscriber count    : 0
topic               : /joy_turbo_decrease/_action/feedback
publisher count     : 1
subscriber count    : 0
topic               : /joy_turbo_decrease/_action/status
publisher count     : 1
subscriber count    : 0
topic               : /joy_turbo_increase/_action/feedback
publisher count     : 1
subscriber count    : 0
topic               : /joy_turbo_increase/_action/status
publisher count     : 1
subscriber count    : 0
topic               : /joy_turbo_reset/_action/feedback
publisher count     : 1
subscriber count    : 0
topic               : /joy_turbo_reset/_action/status
publisher count     : 1
subscriber count    : 0
topic               : /joy_vel
publisher count     : 1
subscriber count    : 1
topic               : /key_vel
publisher count     : 0
subscriber count    : 1
topic               : /local_costmap/clearing_endpoints
publisher count     : 1
subscriber count    : 0
topic               : /local_costmap/costmap
publisher count     : 1
subscriber count    : 1
topic               : /local_costmap/costmap_raw
publisher count     : 1
subscriber count    : 0
topic               : /local_costmap/costmap_updates
publisher count     : 1
subscriber count    : 1
topic               : /local_costmap/footprint
publisher count     : 0
subscriber count    : 0
topic               : /local_costmap/local_costmap/transition_event
publisher count     : 1
subscriber count    : 0
topic               : /local_costmap/published_footprint
publisher count     : 1
subscriber count    : 1
topic               : /local_costmap/voxel_grid
publisher count     : 1
subscriber count    : 0
topic               : /local_costmap/voxel_layer
publisher count     : 1
subscriber count    : 0
topic               : /local_costmap/voxel_layer_raw
publisher count     : 1
subscriber count    : 0
topic               : /local_costmap/voxel_layer_updates
publisher count     : 1
subscriber count    : 0
topic               : /local_costmap/voxel_marked_cloud
publisher count     : 0
subscriber count    : 1
topic               : /local_plan
publisher count     : 1
subscriber count    : 1
topic               : /map
publisher count     : 1
subscriber count    : 1
topic               : /map_server/transition_event
publisher count     : 1
subscriber count    : 0
topic               : /map_updates
publisher count     : 0
subscriber count    : 1
topic               : /marker
publisher count     : 2
subscriber count    : 0
topic               : /marker_vel
publisher count     : 0
subscriber count    : 1
topic               : /mobile_base/sensors/bumper_pointcloud
publisher count     : 0
subscriber count    : 1
topic               : /mobile_base_controller/cmd_vel_out
publisher count     : 1
subscriber count    : 0
topic               : /mobile_base_controller/cmd_vel_unstamped
publisher count     : 1
subscriber count    : 0
topic               : /mobile_base_controller/odom
publisher count     : 1
subscriber count    : 0
topic               : /mobile_base_controller/transition_event
publisher count     : 1
subscriber count    : 0
topic               : /monitored_planning_scene
publisher count     : 1
subscriber count    : 0
topic               : /motion_plan_request
publisher count     : 1
subscriber count    : 0
topic               : /move_action/_action/feedback
publisher count     : 1
subscriber count    : 2
topic               : /move_action/_action/status
publisher count     : 1
subscriber count    : 2
topic               : /navigate_through_poses/_action/feedback
publisher count     : 0
subscriber count    : 2
topic               : /navigate_through_poses/_action/status
publisher count     : 0
subscriber count    : 2
topic               : /navigate_to_pose/_action/feedback
publisher count     : 0
subscriber count    : 2
topic               : /navigate_to_pose/_action/status
publisher count     : 0
subscriber count    : 2
topic               : /particle_cloud
publisher count     : 1
subscriber count    : 1
topic               : /pause_navigation
publisher count     : 0
subscriber count    : 1
topic               : /performance_metrics
publisher count     : 1
subscriber count    : 0
topic               : /phone_vel
publisher count     : 0
subscriber count    : 1
topic               : /plan
publisher count     : 1
subscriber count    : 1
topic               : /plan_smoothed
publisher count     : 0
subscriber count    : 0
topic               : /planner_server/transition_event
publisher count     : 1
subscriber count    : 0
topic               : /planning_scene
publisher count     : 0
subscriber count    : 0
topic               : /planning_scene_world
publisher count     : 0
subscriber count    : 0
topic               : /play_motion2/_action/feedback
publisher count     : 1
subscriber count    : 0
topic               : /play_motion2/_action/status
publisher count     : 1
subscriber count    : 0
topic               : /play_motion2/transition_event
publisher count     : 1
subscriber count    : 0
topic               : /received_global_plan
publisher count     : 1
subscriber count    : 0
topic               : /robot_description
publisher count     : 0
subscriber count    : 1
topic               : /robot_description_semantic
publisher count     : 1
subscriber count    : 0
topic               : /rviz_joy_vel
publisher count     : 0
subscriber count    : 1
topic               : /scan
publisher count     : 0
subscriber count    : 1
topic               : /scan_raw
publisher count     : 1
subscriber count    : 0
topic               : /servoing_cmd_vel
publisher count     : 0
subscriber count    : 1
topic               : /smooth_path/_action/feedback
publisher count     : 0
subscriber count    : 0
topic               : /smooth_path/_action/status
publisher count     : 0
subscriber count    : 0
topic               : /smoother_server/transition_event
publisher count     : 0
subscriber count    : 0
topic               : /sonar_base
publisher count     : 3
subscriber count    : 0
topic               : /speed_limit
publisher count     : 0
subscriber count    : 0
topic               : /spin/_action/feedback
publisher count     : 1
subscriber count    : 0
topic               : /spin/_action/status
publisher count     : 1
subscriber count    : 0
topic               : /stop_closing_loop
publisher count     : 0
subscriber count    : 1
topic               : /tab_vel
publisher count     : 0
subscriber count    : 1
topic               : /text_marker
publisher count     : 1
subscriber count    : 0
topic               : /tf
publisher count     : 2
subscriber count    : 2
topic               : /tf_static
publisher count     : 0
subscriber count    : 2
topic               : /throttle_filtering_points/filtered_points
publisher count     : 0
subscriber count    : 0
topic               : /torso_controller/controller_state
publisher count     : 1
subscriber count    : 0
topic               : /torso_controller/follow_joint_trajectory/_action/feedback
publisher count     : 1
subscriber count    : 1
topic               : /torso_controller/follow_joint_trajectory/_action/status
publisher count     : 1
subscriber count    : 1
topic               : /torso_controller/joint_trajectory
publisher count     : 0
subscriber count    : 0
topic               : /torso_controller/transition_event
publisher count     : 1
subscriber count    : 0
topic               : /trajectory_execution_event
publisher count     : 2
subscriber count    : 0
topic               : /transformed_global_plan
publisher count     : 1
subscriber count    : 0
topic               : /velocity_smoother/transition_event
publisher count     : 0
subscriber count    : 0
topic               : /wait/_action/feedback
publisher count     : 1
subscriber count    : 0
topic               : /wait/_action/status
publisher count     : 1
subscriber count    : 0
topic               : /waypoint_follower/transition_event
publisher count     : 1
subscriber count    : 0
topic               : /waypoints
publisher count     : 0
subscriber count    : 1
