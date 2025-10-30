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
gazebo_msgs.srv.GetEntityState_Response(header=std_msgs.msg.Header(stamp=builtin_interfaces.msg.Time(sec=1637, nanosec=363000000), frame_id='green_cube_3::link'), state=gazebo_msgs.msg.EntityState(name='', pose=geometry_msgs.msg.Pose(position=geometry_msgs.msg.Point(x=-0.11715316595570938, y=0.011255571747410821, z=0.17084676237693494), orientation=geometry_msgs.msg.Quaternion(x=-0.01889789731646686, y=-0.9508321331087073, z=0.0006154360172647764, w=-0.30912901087324474)), twist=geometry_msgs.msg.Twist(linear=geometry_msgs.msg.Vector3(x=-0.0003437078388581281, y=0.00015858456514122865, z=-0.014847305736156743), angular=geometry_msgs.msg.Vector3(x=0.0005012500353512025, y=0.00020410866515100648, z=0.0013159494995272343)), reference_frame=''), success=True)

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
gazebo_msgs.srv.GetEntityState_Response(header=std_msgs.msg.Header(stamp=builtin_interfaces.msg.Time(sec=1817, nanosec=444000000), frame_id='tiago::base_footprint'), state=gazebo_msgs.msg.EntityState(name='', pose=geometry_msgs.msg.Pose(position=geometry_msgs.msg.Point(x=0.756924645849133, y=0.027207768736044545, z=0.7229894810121328), orientation=geometry_msgs.msg.Quaternion(x=-0.018892318345926508, y=-0.9513398384679023, z=0.0006519781544774585, w=-0.3075632731258205)), twist=geometry_msgs.msg.Twist(linear=geometry_msgs.msg.Vector3(x=-0.00045957726516427657, y=0.00017136587312620562, z=-0.0027253052122070925), angular=geometry_msgs.msg.Vector3(x=0.0005761047888237207, y=0.0020631866171665503, z=0.0012312165507350151)), reference_frame=''), success=True)
```

## O względem B
``` bash
ros2 service call /get_entity_state gazebo_msgs/srv/GetEntityState "{name: 'green_cube_3::link', reference_frame: 'tiago::base_footprint'}"
waiting for service to become available...
requester: making request: gazebo_msgs.srv.GetEntityState_Request(name='green_cube_3::link', reference_frame='tiago::base_footprint')

response:
gazebo_msgs.srv.GetEntityState_Response(header=std_msgs.msg.Header(stamp=builtin_interfaces.msg.Time(sec=1859, nanosec=320000000), frame_id='tiago::base_footprint'), state=gazebo_msgs.msg.EntityState(name='', pose=geometry_msgs.msg.Pose(position=geometry_msgs.msg.Point(x=0.8735142103011186, y=0.01594947998641261, z=0.5517736488522262), orientation=geometry_msgs.msg.Quaternion(x=-7.380010184172177e-06, y=0.0016454448241037037, z=1.4293460463888912e-06, w=0.9999986462264953)), twist=geometry_msgs.msg.Twist(linear=geometry_msgs.msg.Vector3(x=-6.700983781698309e-05, y=1.30021137441599e-05, z=0.012120791482537675), angular=geometry_msgs.msg.Vector3(x=7.052908006112184e-05, y=0.0018590560483133936, z=-8.307366800166921e-05)), reference_frame=''), success=True)
```

# Zadanie 7 - nie wykonane jako że 0 pkt za nie

# Zadanie 8