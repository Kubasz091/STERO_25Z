ros2 run rqt_tf_tree rqt_tf_tree --force-discover

## Tematy i sensory

Sprawdzone tematy:

1. **Sterowanie**
   - `/cmd_vel` (lub `/mobile_base_controller/cmd_vel_unstamped`)
   - Typ: `geometry_msgs/msg/Twist`
   - Do jazdy.
   - Status: brak danych (robot stoi).

2. **Odometria**
   - `/mobile_base_controller/odom`
   - Typ: `nav_msgs/msg/Odometry`
   - Pozycja z kół.
   - Status: działa.

3. **LiDAR**
   - `/scan_raw` (uwaga: `/scan` nie działa)
   - Typ: `sensor_msgs/msg/LaserScan`
   - Laser 2D.
   - Status: działa.

4. **Kamera**
   - RGB: `/head_front_camera/rgb/image_raw`
     - Typ: `sensor_msgs/msg/Image`
     - Działa
   - Chmura punktów: `/head_front_camera/depth_registered/points`
     - Typ: `sensor_msgs/msg/PointCloud2`
     - Działa

#### TF
Drzewo transformacji w pliku `tf_tree.pdf`.


sysml verify