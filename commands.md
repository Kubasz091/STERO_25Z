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
```