# zadanie 1

Stworzyliśmy pliki launch według poleceń i wskazówek

# zadanie 2

to polecenie uruchamia system z nowym światem:

```bash
ros2 launch hello_moveit  tiago_gazebo.launch.py navigation:=True moveit:=True is_public_sim:=True use_grasp_fix_plugin:=True world_name:=stero
```

# zadanie 3

```bash
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

- **/link_states: gazebo_msgs/msg/LinkStates** - publikuje pozycje i prędkości wszystkich linków w symulacji względem układu świata. Zawiera nazwy linków, ich pozy (pozycja + orientacja) oraz prędkości (liniowa + kątowa).
- **/model_states: gazebo_msgs/msg/ModelStates** - publikuje pozycje i prędkości wszystkich modeli w symulacji względem układu świata. Zawiera nazwy modeli, ich pozy (pozycja + orientacja) oraz prędkości (liniowa + kątowa).

## Service Servers:

- **/get_entity_state: gazebo_msgs/srv/GetEntityState** - umożliwia pobranie aktualnej pozy i prędkości wybranej encji (model, link, kolizja, światło) względem wybranego układu odniesienia. Zwraca pozycję, orientację, prędkość liniową i kątową.
- **/set_entity_state: gazebo_msgs/srv/SetEntityState** - umożliwia ustawienie pozy i prędkości wybranej encji względem wybranego układu odniesienia. Można w ten sposób teleportować obiekty lub nadawać im prędkość początkową.

```bash
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

Topic `/model_states` zawiera tablice z nazwami wszystkich modeli w symulacji oraz odpowiadające im pozy i prędkości. Każdy model ma pozycję (x, y, z), orientację (kwaternion), prędkość liniową i kątową. Jest to broadcast wszystkich stanów modeli w układzie świata.

```bash
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

Topic `/link_states` zawiera tablice z nazwami wszystkich linków w symulacji oraz odpowiadające im pozy i prędkości. Każdy link (element robota lub obiektu) ma pozycję (x, y, z), orientację (kwaternion), prędkość liniową i kątową. Jest to broadcast wszystkich stanów linków w układzie świata.

```bash
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

Serwis `/get_entity_state` służy do pobierania aktualnego stanu wybranej encji (model, link, kolizja, światło). W żądaniu podajemy:

- `name` - nazwę encji w notacji Gazebo (np. `tiago::wrist_ft_link`)
- `reference_frame` - układ odniesienia względem którego chcemy otrzymać pozę i prędkość (domyślnie układ świata)

W odpowiedzi otrzymujemy pozę (pozycja + orientacja jako kwaternion) oraz prędkość (liniowa + kątowa) encji względem wybranego układu. Serwis zwraca również `success` wskazujący powodzenie operacji.

```bash
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

Serwis `/set_entity_state` służy do ustawiania stanu wybranej encji w symulacji. W żądaniu podajemy:

- `state.name` - nazwę encji w notacji Gazebo (np. `green_cube_3::link`)
- `state.pose` - docelową pozę (pozycja + orientacja jako kwaternion)
- `state.twist` - docelową prędkość (liniowa + kątowa)
- `state.reference_frame` - układ odniesienia względem którego podajemy pozę (domyślnie układ świata)

Serwis umożliwia "teleportowanie" obiektów do wybranej pozycji lub nadawanie im prędkości początkowej. Jest przydatny do resetowania pozycji obiektów, umieszczania ich w określonych miejscach lub testowania dynamiki. Zwraca `success` wskazujący czy operacja się powiodła.

# zadanie 4

Zrobiono tak jak w poleceniu. Stworzono katalog models i dodano do niego 3 modele. Dodano owy katalog do instalowanych folderów w CMakeLists.txt.

# zadanie 5

stworzono node-a, którego celem jest wykorzystanie klasy MoveGroupInterface, w celu odczytania nazw układów B i E

```cpp
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

```bash
ros2 run hello_moveit print_frames --ros-args -p group:=arm_torso
[INFO] [1761860177.071313753] [moveit_rdf_loader.rdf_loader]: Loaded robot model in 3.08074 seconds
[INFO] [1761860177.071416864] [moveit_robot_model.robot_model]: Loading robot model 'tiago'...
[INFO] [1761860177.071426863] [moveit_robot_model.robot_model]: No root/virtual joint specified in SRDF. Assuming fixed joint

--- Warnings ---

[INFO] [1761860177.224469807] [move_group_interface]: Ready to take commands for planning group arm_torso.
[INFO] [1761860177.224604367] [print_frames]: B (planning frame): base_footprint
[INFO] [1761860177.224799629] [print_frames]: E (end effector):  arm_tool_link
```

jako układ F wybrano `wrist_ft_link` z:

```bash
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

Otworzono chwytak, a następnie ustawiono go w taki sposób, aby szczęki obejmowały obiekt na rys. 1. Użyto rviz i motionPlanning. Następnie odczytano pozycje istotnych układów, które są opisane poniżej:

## F wzgledem O

```bash
ros2 service call /get_entity_state gazebo_msgs/srv/GetEntityState "{name: 'tiago::wrist_ft_link', reference_frame: 'green_cube_3::link'}"
requester: making request: gazebo_msgs.srv.GetEntityState_Request(name='tiago::wrist_ft_link', reference_frame='green_cube_3::link')

response:
gazebo_msgs.srv.GetEntityState_Response(header=std_msgs.msg.Header(stamp=builtin_interfaces.msg.Time(sec=1809, nanosec=258000000), frame_id='green_cube_3::link'), state=gazebo_msgs.msg.EntityState(name='', pose=geometry_msgs.msg.Pose(position=geometry_msgs.msg.Point(x=0.005071250542391959, y=-0.001078510009209965, z=0.232017062226551), orientation=geometry_msgs.msg.Quaternion(x=0.997776211667235, y=-0.06661632963077202, z=-0.0019340518557168878, w=0.0010749422891682054)), twist=geometry_msgs.msg.Twist(linear=geometry_msgs.msg.Vector3(x=-0.0009333835761639284, y=0.0022413252256606783, z=-0.02600894296413523), angular=geometry_msgs.msg.Vector3(x=0.0024435304333426766, y=-0.0014682882225467188, z=-0.0026977951713324914)), reference_frame=''), success=True)

```

## E wzgledem O (T_EO = T_EF ∘ T_FO)

```bash
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

```bash
ros2 service call /get_entity_state gazebo_msgs/srv/GetEntityState "{name: 'tiago::wrist_ft_link', reference_frame: 'tiago::base_footprint'}"
waiting for service to become available...
requester: making request: gazebo_msgs.srv.GetEntityState_Request(name='tiago::wrist_ft_link', reference_frame='tiago::base_footprint')

response:
gazebo_msgs.srv.GetEntityState_Response(header=std_msgs.msg.Header(stamp=builtin_interfaces.msg.Time(sec=1995, nanosec=291000000), frame_id='tiago::base_footprint'), state=gazebo_msgs.msg.EntityState(name='', pose=geometry_msgs.msg.Pose(position=geometry_msgs.msg.Point(x=0.39332776673891007, y=-0.09863482333063534, z=0.7868290413468051), orientation=geometry_msgs.msg.Quaternion(x=0.9977762936492878, y=-0.06662188357063846, z=-0.0016919394901435264, w=0.0010629213293110872)), twist=geometry_msgs.msg.Twist(linear=geometry_msgs.msg.Vector3(x=-0.0009908262546113322, y=0.002241275188744823, z=-0.014251062105096047), angular=geometry_msgs.msg.Vector3(x=0.0025067494139460844, y=-0.0010613873228364251, z=-0.00269660655380948)), reference_frame=''), success=True)
```

## O względem B

```bash
ros2 service call /get_entity_state gazebo_msgs/srv/GetEntityState "{name: 'green_cube_3::link', reference_frame: 'tiago::base_footprint'}"
waiting for service to become available...
requester: making request: gazebo_msgs.srv.GetEntityState_Request(name='green_cube_3::link', reference_frame='tiago::base_footprint')

response:
gazebo_msgs.srv.GetEntityState_Response(header=std_msgs.msg.Header(stamp=builtin_interfaces.msg.Time(sec=2006, nanosec=862000000), frame_id='tiago::base_footprint'), state=gazebo_msgs.msg.EntityState(name='', pose=geometry_msgs.msg.Pose(position=geometry_msgs.msg.Point(x=0.38836927153429057, y=-0.09756135619150655, z=0.5548355697949557), orientation=geometry_msgs.msg.Quaternion(x=-5.262173338224914e-06, y=-0.00024179374027266792, z=-4.852887181252426e-06, w=0.9999999707422726)), twist=geometry_msgs.msg.Twist(linear=geometry_msgs.msg.Vector3(x=-7.003816584000018e-05, y=2.1610094366687647e-07, z=0.011758353089382514), angular=geometry_msgs.msg.Vector3(x=6.192646530910378e-05, y=0.00040694896052922866, z=-8.816560441352007e-09)), reference_frame=''), success=True)
```

# Zadanie 7 - nie wykonano, ponieważ nie jest ono punktowane.

# Zadanie 8

stworzono skrypt `one_grasp.cpp`. Skonfigurowano Rviz, zgodnie z tutorialem do którego link był w slajdach z wykładu. Otrzymano i wyświetlono pozycje kostki, która została manualnie sprawdzona w gazebo

```bash
ros2 run hello_moveit one_grasp --ros-args -p group:=arm_torso -p object:=green_cube_3 -p reference_frame:=tiago::base_footprint -p rviz_frame:=base_footprint -p use_sim_time:=true
[INFO] [1761905904.180772681] [moveit_rdf_loader.rdf_loader]: Loaded robot model in 1968.43 seconds
[INFO] [1761905904.180925796] [moveit_robot_model.robot_model]: Loading robot model 'tiago'...
[INFO] [1761905904.180948478] [moveit_robot_model.robot_model]: No root/virtual joint specified in SRDF. Assuming fixed joint

--- URDF Warnings ---

[INFO] [1761905904.369498300] [move_group_interface]: Ready to take commands for planning group arm_torso.
[INFO] [1761905904.373717467] [one_grasp.remote_control]: RemoteControl Ready.
[INFO] [1761905904.384077222] [one_grasp]: Object '' in 'tiago::base_footprint': pos [0.388 -0.098 0.555], quat [-0.000 -0.000 -0.000 1.000]
```

_uwaga_: _parametr `use_sim_time` okazał się tutaj kluczowy, bez niego w rviz wyrzucał errory zwiazane z czasem i tf_

![alt text](photos\zad8.png)

# zadanie 9 i 10

Zadania 9 i 10 zrobiono jednocześnie, jako że obejmowały podobny zakres.
zmodyfikowano skrypt `one_grasp.cpp` aby spełniał założenia, i uruchomiono go:

```bash
ros2 run hello_moveit one_grasp --ros-args \
  -p group:=arm_torso \
  -p object:=green_cube_3 \
  -p reference_frame:=tiago::base_footprint \
  -p rviz_frame:=base_footprint \
  -p approach_distance:=0.12 \
  -p use_sim_time:=true

[INFO] [1761908133.889214360] [moveit_rdf_loader.rdf_loader]: Loaded robot model in 2765.76 seconds
[INFO] [1761908133.889503031] [moveit_robot_model.robot_model]: Loading robot model 'tiago'...
[INFO] [1761908133.889578250] [moveit_robot_model.robot_model]: No root/virtual joint specified in SRDF. Assuming fixed joint

--- WARNINGS ---

[INFO] [1761908134.039783481] [move_group_interface]: Ready to take commands for planning group arm_torso.
[INFO] [1761908134.047633571] [one_grasp.remote_control]: RemoteControl Ready.
[INFO] [1761908134.057078755] [one_grasp]: Object 'green_cube_3::link' in 'tiago::base_footprint': pos [0.388 -0.098 0.555], quat [-0.000 -0.000 -0.000 1.000]
[INFO] [1761908134.384962270] [one_grasp]: E_grasp in 'base_footprint': pos [0.393 -0.099 0.795] quat [-0.531 -0.466 0.533 -0.465]
[INFO] [1761908134.385089225] [one_grasp]: E_pregrasp (d=0.120m) in 'base_footprint': pos [0.393 -0.098 0.915] quat [-0.531 -0.466 0.533 -0.465]
```

![alt text](photos\zad9_10.png)

# zadanie 11 i 12

zmodyfikowano skrypt `one_grasp.cpp` aby wykonywał zalecone czynności. Przebieg ich przedstawiono na zdjeciach

```bash
ros2 run hello_moveit one_grasp --ros-args \
  -p group:=arm_torso \
  -p reference_frame:=tiago::base_footprint \
  -p rviz_frame:=base_footprint \
  -p object:=green_cube_3 \
  -p gripper_group:=gripper \
  -p finger_left_joint:=gripper_left_finger_joint \
  -p finger_right_joint:=gripper_right_finger_joint \
  -p gripper_open:=0.044 -p gripper_close:=0.035 \
  -p torso_up:=0.35 -p arm1_angle:=1.5708 -p lift_height:=0.05 \
  -p approach_distance:=0.12 \
  -p use_sim_time:=true
[INFO] [1761914258.335666050] [moveit_rdf_loader.rdf_loader]: Loaded robot model in 1883.36 seconds
[INFO] [1761914258.335829043] [moveit_robot_model.robot_model]: Loading robot model 'tiago'...
[INFO] [1761914258.335894023] [moveit_robot_model.robot_model]: No root/virtual joint specified in SRDF. Assuming fixed joint

--- WARNINGS ---

[INFO] [1761914258.505242777] [move_group_interface]: Ready to take commands for planning group arm_torso.
[INFO] [1761914258.509728545] [one_grasp.remote_control]: RemoteControl Ready.
[INFO] [1761914258.521250903] [one_grasp]: Object 'green_cube_3::link' in 'tiago::base_footprint': pos [0.388 -0.098 0.555], quat [-0.000 -0.000 -0.000 1.000]
[INFO] [1761914258.855567052] [one_grasp]: E_grasp in 'base_footprint': pos [0.393 -0.099 0.795] quat [-0.531 -0.466 0.533 -0.465]
[INFO] [1761914258.855724925] [one_grasp]: E_pregrasp (d=0.120m) in 'base_footprint': pos [0.393 -0.098 0.915] quat [-0.531 -0.466 0.533 -0.465]
[INFO] [1761914259.241541125] [move_group_interface]: Ready to take commands for planning group gripper.
[INFO] [1761914259.245603690] [move_group_interface]: MoveGroup action client/server ready
[INFO] [1761914259.250241434] [move_group_interface]: Planning request accepted
[INFO] [1761914259.453365448] [move_group_interface]: Planning request complete!
[INFO] [1761914259.453914863] [move_group_interface]: time taken to generate plan: 0.0267501 seconds
[INFO] [1761914259.453987338] [one_grasp]: Raise torso plan: OK
[INFO] [1761914259.458724454] [move_group_interface]: Execute request accepted
[INFO] [1761914279.335640998] [move_group_interface]: Execute request success!
[INFO] [1761914279.335783933] [one_grasp]: Raise torso exec: OK
[INFO] [1761914279.336499553] [move_group_interface]: MoveGroup action client/server ready
[INFO] [1761914279.338139188] [move_group_interface]: Planning request accepted
[INFO] [1761914279.518169158] [move_group_interface]: Planning request complete!
[INFO] [1761914279.519478310] [move_group_interface]: time taken to generate plan: 0.0335651 seconds
[INFO] [1761914279.519586791] [one_grasp]: Rotate arm_1 to 90deg plan: OK
[INFO] [1761914279.522162711] [move_group_interface]: Execute request accepted
[INFO] [1761914282.901684438] [move_group_interface]: Execute request success!
[INFO] [1761914282.901863019] [one_grasp]: Rotate arm_1 to 90deg exec: OK
[INFO] [1761914282.902501064] [move_group_interface]: MoveGroup action client/server ready
[INFO] [1761914282.906055521] [move_group_interface]: Planning request accepted
[INFO] [1761914283.076397207] [move_group_interface]: Planning request complete!
[INFO] [1761914283.077465621] [move_group_interface]: time taken to generate plan: 0.0649676 seconds
[INFO] [1761914283.077594441] [one_grasp]: Open gripper plan: OK
[INFO] [1761914283.079362906] [move_group_interface]: Execute request accepted
[INFO] [1761914291.250336487] [move_group_interface]: Execute request success!
[INFO] [1761914291.250924450] [one_grasp]: Open gripper exec: OK
[INFO] [1761914291.251608060] [move_group_interface]: MoveGroup action client/server ready
[INFO] [1761914291.253035361] [move_group_interface]: Planning request accepted
[INFO] [1761914291.517692532] [move_group_interface]: Planning request complete!
[INFO] [1761914291.517858761] [move_group_interface]: time taken to generate plan: 0.0859204 seconds
[INFO] [1761914291.517898384] [one_grasp]: Pregrasp plan: OK
[INFO] [1761914291.521838905] [move_group_interface]: Execute request accepted
[INFO] [1761914306.597049150] [move_group_interface]: Execute request success!
[INFO] [1761914306.597911194] [one_grasp]: Pregrasp exec: OK
[INFO] [1761914306.598725606] [move_group_interface]: MoveGroup action client/server ready
[INFO] [1761914306.601702343] [move_group_interface]: Planning request accepted
[INFO] [1761914306.819292374] [move_group_interface]: Planning request complete!
[INFO] [1761914306.820325318] [move_group_interface]: time taken to generate plan: 0.0269923 seconds
[INFO] [1761914306.820389507] [one_grasp]: Grasp pose plan: OK
[INFO] [1761914306.822632137] [move_group_interface]: Execute request accepted
[INFO] [1761914313.652378600] [move_group_interface]: Execute request success!
[INFO] [1761914313.653154231] [one_grasp]: Grasp pose exec: OK
[INFO] [1761914313.655121656] [move_group_interface]: MoveGroup action client/server ready
[INFO] [1761914313.657945641] [move_group_interface]: Planning request accepted
[INFO] [1761914313.745859488] [move_group_interface]: Planning request complete!
[INFO] [1761914313.745929180] [move_group_interface]: time taken to generate plan: 0.0231453 seconds
[INFO] [1761914313.746234931] [one_grasp]: Close gripper plan: OK
[INFO] [1761914313.749200193] [move_group_interface]: Execute request accepted
[INFO] [1761914315.469478256] [move_group_interface]: Execute request success!
[INFO] [1761914315.470910860] [one_grasp]: Close gripper exec: OK
[INFO] [1761914315.777590151] [move_group_interface]: MoveGroup action client/server ready
[INFO] [1761914315.779308542] [move_group_interface]: Planning request accepted
[INFO] [1761914316.020293162] [move_group_interface]: Planning request complete!
[INFO] [1761914316.020850177] [move_group_interface]: time taken to generate plan: 0.0454769 seconds
[INFO] [1761914316.020909848] [one_grasp]: Lift 5cm plan: OK
[INFO] [1761914316.027988700] [move_group_interface]: Execute request accepted
[INFO] [1761914319.023068180] [move_group_interface]: Execute request success!
[INFO] [1761914319.023430924] [one_grasp]: Lift 5cm exec: OK
[INFO] [1761914319.023528314] [one_grasp]: Grasp sequence: done.
```

![pozycja init](photos\zad11_12_1.png)
![pozycja nad stolem](photos\zad11_12_2.png)
![pre_grasp](photos\zad11_12_3.png)
![grasp](photos\zad11_12_4.png)
![pickup](photos\zad11_12_5.png)
