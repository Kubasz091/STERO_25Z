# setup lokalny
``` bash
export ROS_AUTOMATIC_DISCOVERY_RANGE=LOCALHOST
```

# Sourcowanie
``` bash
source /opt/ros/iron/setup.bash
source ~/tiago/install/setup.bash
```

# Build
``` bash
colcon build --symlink-install --packages-select
```

# tworzenie package
``` bash
ros2 pkg create --build-type ament_cmake --dependencies <dependencies> --node-name <node_name> <package_name>
```

# runowanie
``` bash
ros2 run hello_moveit hello_moveit --ros-args -p use_sim_time:=true
ros2 launch <package_name> <launch_file>

ros2 launch hello_moveit  tiago_gazebo.launch.py navigation:=True moveit:=True is_public_sim:=True use_grasp_fix_plugin:=True world_name:=stero
```

# ubijanie gazebo
``` bash
ps-A | grep gz

kill-9 <id_procesu>
```

# komendy Rosowe
``` bash
ros2 topic list
ros2 topic hz <topic_name>
ros2 topic echo <topic_name> --once
ros2 node info <node_name>
ros2 topic type <topic_name>
ros2 service type <service_name>
ros2 interface show <topic/service_name>
```