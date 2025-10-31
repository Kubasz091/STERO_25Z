# zadanie 1
stworzyliśmy pliki launch jak w poleceniu/wskazówkach

# zadanie 2
to polecenie uruchamia system z nowym światem:

``` bash
ros2 launch hello_moveit  tiago_gazebo.launch.py navigation:=True moveit:=True is_public_sim:=True use_grasp_fix_plugin:=True world_name:=stero
```

# zadanie 3
``` bash
ros2 node info /gazebo_ros_state
/gazebo_ros_state
  Subscribers:
    /clock: rosgraph_msgs/msg/Clock
    /parameter_events: rcl_interfaces/msg/ParameterEvent
  Publishers:
    /link_states: gazebo_msgs/msg/LinkStates
    /model_states: gazebo_msgs/msg/ModelStates
    /parameter_events: rcl_interfaces/msg/ParameterEvent
    /rosout: rcl_interfaces/msg/Log
  Service Servers:
    /gazebo_ros_state/describe_parameters: rcl_interfaces/srv/DescribeParameters
    /gazebo_ros_state/get_parameter_types: rcl_interfaces/srv/GetParameterTypes
    /gazebo_ros_state/get_parameters: rcl_interfaces/srv/GetParameters
    /gazebo_ros_state/get_type_description: type_description_interfaces/srv/GetTypeDescription
    /gazebo_ros_state/list_parameters: rcl_interfaces/srv/ListParameters
    /gazebo_ros_state/set_parameters: rcl_interfaces/srv/SetParameters
    /gazebo_ros_state/set_parameters_atomically: rcl_interfaces/srv/SetParametersAtomically
    /get_entity_state: gazebo_msgs/srv/GetEntityState
    /set_entity_state: gazebo_msgs/srv/SetEntityState
  Service Clients:

  Action Servers:

  Action Clients:
```
## Publishers:
  - /link_states: gazebo_msgs/msg/LinkStates
  - /model_states: gazebo_msgs/msg/ModelStates

## Service Servers:
  - /get_entity_state: gazebo_msgs/srv/GetEntityState
  - /set_entity_state: gazebo_msgs/srv/SetEntityState

``` bash
ros2 topic type /model_states | xargs ros2 interface show
# broadcast all model states in world frame
string[] name                 # model names
geometry_msgs/Pose[] pose     # desired pose in world frame
        Point position
                float64 x
                float64 y
                float64 z
        Quaternion orientation
                float64 x 0
                float64 y 0
                float64 z 0
                float64 w 1
geometry_msgs/Twist[] twist   # desired twist in world frame
        Vector3  linear
                float64 x
                float64 y
                float64 z
        Vector3  angular
                float64 x
                float64 y
                float64 z
```

``` bash
ros2 topic type /link_states  | xargs ros2 interface show
# broadcast all link states in world frame
string[] name                 # link names
geometry_msgs/Pose[] pose     # desired pose in world frame
        Point position
                float64 x
                float64 y
                float64 z
        Quaternion orientation
                float64 x 0
                float64 y 0
                float64 z 0
                float64 w 1
geometry_msgs/Twist[] twist   # desired twist in world frame
        Vector3  linear
                float64 x
                float64 y
                float64 z
        Vector3  angular
                float64 x
                float64 y
                float64 z
```

``` bash
ros2 service type /get_entity_state | xargs ros2 interface show
string name                          # Entity's scoped name.
                                     # An entity can be a model, link, collision, light, etc.
                                     # Be sure to use gazebo scoped naming notation (e.g. [model_name::link_name])
string reference_frame               # Return pose and twist relative to this entity.
                                     # Leaving empty or "world" will use inertial world frame.
---
std_msgs/Header header               # Standard metadata for higher-level stamped data types.
        builtin_interfaces/Time stamp
                int32 sec
                uint32 nanosec
        string frame_id
                                     # * header.stamp Timestamp related to the pose.
                                     # * header.frame_id Filled with the relative_frame.
gazebo_msgs/EntityState state        # Contains pose and twist.
        string name                 #
                                    # An entity can be a model, link, collision, light, etc.
                                    # Be sure to use gazebo scoped naming notation (e.g. [model_name::link_name])
        geometry_msgs/Pose pose     #
                Point position
                        float64 x
                        float64 y
                        float64 z
                Quaternion orientation
                        float64 x 0
                        float64 y 0
                        float64 z 0
                        float64 w 1
        geometry_msgs/Twist twist   #
                Vector3  linear
                        float64 x
                        float64 y
                        float64 z
                Vector3  angular
                        float64 x
                        float64 y
                        float64 z
        string reference_frame      #
                                    # Leaving empty or "world" defaults to inertial world frame.
bool success                         # Return true if get was successful. If false, the state contains garbage.
```

``` bash
ros2 service type /set_entity_state | xargs ros2 interface show
gazebo_msgs/EntityState state   # Entity state to set to.
        string name                 #
                                    # An entity can be a model, link, collision, light, etc.
                                    # Be sure to use gazebo scoped naming notation (e.g. [model_name::link_name])
        geometry_msgs/Pose pose     #
                Point position
                        float64 x
                        float64 y
                        float64 z
                Quaternion orientation
                        float64 x 0
                        float64 y 0
                        float64 z 0
                        float64 w 1
        geometry_msgs/Twist twist   #
                Vector3  linear
                        float64 x
                        float64 y
                        float64 z
                Vector3  angular
                        float64 x
                        float64 y
                        float64 z
        string reference_frame      #
                                    # Leaving empty or "world" defaults to inertial world frame.
                                # Be sure to fill all fields, values of zero have meaning.
---
bool success                    # Return true if setting state was successful.
```

# zadanie 4
zrobiono jak w poleceniu, dodano w cmake install na folder models

# zadanie 5
stworzono node-a, którego celem jest wykorzystanie klasy MoveGroupInterface, w celu odczytania nazw układów B i E
``` cpp
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
```
efektem jego wywołania (pomijając warningi) było:
``` bash
ros2 run hello_moveit print_frames --ros-args -p group:=arm_torso
[INFO] [1761860177.071313753] [moveit_rdf_loader.rdf_loader]: Loaded robot model in 3.08074 seconds
[INFO] [1761860177.071416864] [moveit_robot_model.robot_model]: Loading robot model 'tiago'...
[INFO] [1761860177.071426863] [moveit_robot_model.robot_model]: No root/virtual joint specified in SRDF. Assuming fixed joint

--- Warnings ---

[INFO] [1761860177.224469807] [move_group_interface]: Ready to take commands for planning group arm_torso.
[INFO] [1761860177.224604367] [print_frames]: B (planning frame): base_footprint
[INFO] [1761860177.224799629] [print_frames]: E (end effector):  arm_tool_link
```
## **mam wątpliwość czy nie brać jako E `gripper_grasping_frame` - spytać sie jak mają inni**
chyba sobie jednak sam odpowiedzialem bo parent `wrist_ft_link` to `arm_tool_link`

jako układ F wybrano `wrist_ft_link` z:
``` bash
ros2 topic echo /link_states --once
name:
- ground_plane::link
- table::link
- tiago::base_footprint
- tiago::wheel_left_link
- tiago::wheel_right_link
- tiago::torso_lift_link
- tiago::arm_1_link
- tiago::arm_2_link
- tiago::arm_3_link
- tiago::arm_4_link
- tiago::arm_5_link
- tiago::arm_6_link
- tiago::arm_7_link
- tiago::wrist_ft_link
- tiago::gripper_left_finger_link
- tiago::gripper_right_finger_link
- tiago::head_1_link
- tiago::head_2_link
```

## Pozycja F względem E:
- x: 0.007849999703466892
- y: 0
- z: 0

# zad 6
otworzono chwytak używając rviz i motionPlanning

## F wzgledem O
``` bash
ros2 service call /get_entity_state gazebo_msgs/srv/GetEntityState "{name: 'tiago::wrist_ft_link', reference_frame: 'green_cube_3::link'}"
requester: making request: gazebo_msgs.srv.GetEntityState_Request(name='tiago::wrist_ft_link', reference_frame='green_cube_3::link')

response:
gazebo_msgs.srv.GetEntityState_Response(header=std_msgs.msg.Header(stamp=builtin_interfaces.msg.Time(sec=1809, nanosec=258000000), frame_id='green_cube_3::link'), state=gazebo_msgs.msg.EntityState(name='', pose=geometry_msgs.msg.Pose(position=geometry_msgs.msg.Point(x=0.005071250542391959, y=-0.001078510009209965, z=0.232017062226551), orientation=geometry_msgs.msg.Quaternion(x=0.997776211667235, y=-0.06661632963077202, z=-0.0019340518557168878, w=0.0010749422891682054)), twist=geometry_msgs.msg.Twist(linear=geometry_msgs.msg.Vector3(x=-0.0009333835761639284, y=0.0022413252256606783, z=-0.02600894296413523), angular=geometry_msgs.msg.Vector3(x=0.0024435304333426766, y=-0.0014682882225467188, z=-0.0026977951713324914)), reference_frame=''), success=True)

```
## E wzgledem O (T_EO = T_EF ∘ T_FO)
``` bash
ros2 run tf2_ros tf2_echo arm_tool_link wrist_ft_link
[INFO] [1761864215.141386840] [tf2_echo]: Waiting for transform arm_tool_link ->  wrist_ft_link: Invalid frame ID "arm_tool_link" passed to canTransform argument target_frame - frame does not exist
At time 0.0
- Translation: [0.008, 0.000, 0.000]
- Rotation: in Quaternion [0.500, 0.500, 0.500, 0.500]
- Rotation: in RPY (radian) [1.571, -0.000, 1.571]
- Rotation: in RPY (degree) [90.000, -0.000, 90.000]
- Matrix:
  0.000 -0.000  1.000  0.008
  1.000  0.000 -0.000  0.000
  0.000  1.000  0.000  0.000
  0.000  0.000  0.000  1.000
```

## F wzgledem B
``` bash
ros2 service call /get_entity_state gazebo_msgs/srv/GetEntityState "{name: 'tiago::wrist_ft_link', reference_frame: 'tiago::base_footprint'}"
waiting for service to become available...
requester: making request: gazebo_msgs.srv.GetEntityState_Request(name='tiago::wrist_ft_link', reference_frame='tiago::base_footprint')

response:
gazebo_msgs.srv.GetEntityState_Response(header=std_msgs.msg.Header(stamp=builtin_interfaces.msg.Time(sec=1995, nanosec=291000000), frame_id='tiago::base_footprint'), state=gazebo_msgs.msg.EntityState(name='', pose=geometry_msgs.msg.Pose(position=geometry_msgs.msg.Point(x=0.39332776673891007, y=-0.09863482333063534, z=0.7868290413468051), orientation=geometry_msgs.msg.Quaternion(x=0.9977762936492878, y=-0.06662188357063846, z=-0.0016919394901435264, w=0.0010629213293110872)), twist=geometry_msgs.msg.Twist(linear=geometry_msgs.msg.Vector3(x=-0.0009908262546113322, y=0.002241275188744823, z=-0.014251062105096047), angular=geometry_msgs.msg.Vector3(x=0.0025067494139460844, y=-0.0010613873228364251, z=-0.00269660655380948)), reference_frame=''), success=True)
```

## O względem B
``` bash
ros2 service call /get_entity_state gazebo_msgs/srv/GetEntityState "{name: 'green_cube_3::link', reference_frame: 'tiago::base_footprint'}"
waiting for service to become available...
requester: making request: gazebo_msgs.srv.GetEntityState_Request(name='green_cube_3::link', reference_frame='tiago::base_footprint')

response:
gazebo_msgs.srv.GetEntityState_Response(header=std_msgs.msg.Header(stamp=builtin_interfaces.msg.Time(sec=2006, nanosec=862000000), frame_id='tiago::base_footprint'), state=gazebo_msgs.msg.EntityState(name='', pose=geometry_msgs.msg.Pose(position=geometry_msgs.msg.Point(x=0.38836927153429057, y=-0.09756135619150655, z=0.5548355697949557), orientation=geometry_msgs.msg.Quaternion(x=-5.262173338224914e-06, y=-0.00024179374027266792, z=-4.852887181252426e-06, w=0.9999999707422726)), twist=geometry_msgs.msg.Twist(linear=geometry_msgs.msg.Vector3(x=-7.003816584000018e-05, y=2.1610094366687647e-07, z=0.011758353089382514), angular=geometry_msgs.msg.Vector3(x=6.192646530910378e-05, y=0.00040694896052922866, z=-8.816560441352007e-09)), reference_frame=''), success=True)
```

# Zadanie 7 - nie wykonane jako że 0 pkt za nie

# Zadanie 8
stworzono skrypt `one_grasp.cpp`. Skonfigurowano Rviz, zgodnie z tutorialem do którego link był w slajdach z wykładu. Otrzymano i wyświetlono pozycje kostki, która została manualnie sprawdzona w gazebo

``` bash
ros2 run hello_moveit one_grasp --ros-args -p group:=arm_torso -p object:=green_cube_3 -p reference_frame:=tiago::base_footprint -p rviz_frame:=base_footprint -p use_sim_time:=true
[INFO] [1761905904.180772681] [moveit_rdf_loader.rdf_loader]: Loaded robot model in 1968.43 seconds
[INFO] [1761905904.180925796] [moveit_robot_model.robot_model]: Loading robot model 'tiago'...
[INFO] [1761905904.180948478] [moveit_robot_model.robot_model]: No root/virtual joint specified in SRDF. Assuming fixed joint

--- URDF Warnings ---

[INFO] [1761905904.369498300] [move_group_interface]: Ready to take commands for planning group arm_torso.
[INFO] [1761905904.373717467] [one_grasp.remote_control]: RemoteControl Ready.
[INFO] [1761905904.384077222] [one_grasp]: Object '' in 'tiago::base_footprint': pos [0.388 -0.098 0.555], quat [-0.000 -0.000 -0.000 1.000]
```

_uwaga_: _parametr `use_sim_time` okazał się tutaj kluczowy, bez niego w rviz errory zwiazane z czase i tf_

![alt text](photos\zad8.png)

# zadanie 9

