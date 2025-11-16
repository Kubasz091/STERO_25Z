mkdir -p tiago/src
cd tiago/
vcs import --input https://raw.githubusercontent.com/RCPRG-ros-pkg/STERO2/refs/heads/iron/tiago_public_stero.repos src

source /opt/ros/iron/setup.bash
# colcon build --symlink-install # chyba nie potrzebne
cd ..
# source tiago/install/setup.bash # to też
colcon build --symlink-install
source install/setup.bash

echo "source ~/stero/install/setup.bash" >> ~/.bashrc