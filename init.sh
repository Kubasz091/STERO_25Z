killall -9 gzserver gzclient rosmaster
pkill -f ros2
pkill -f colcon
pkill -f python3

conda deactivate
export PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin

source /opt/ros/iron/setup.bash
source /opt/ai_lab/tiago/install/setup.bash
source install/setup.bash

# mkdir -p tiago/src
# cd tiago/
# vcs import --input https://raw.githubusercontent.com/RCPRG-ros-pkg/STERO2/refs/heads/iron/tiago_public_stero.repos src

# source /opt/ros/iron/setup.bash
# # colcon build --symlink-install # chyba nie potrzebne
# cd ..
# # source tiago/install/setup.bash # to też
# colcon build --symlink-install
# source install/setup.bash

# echo "source ~/stero/install/setup.bash" >> ~/.bashrc