mkdir -p tiago/src
cd tiago/
vcs import --input https://raw.githubusercontent.com/RCPRG-ros-pkg/STERO2/refs/heads/iron/tiago_public_stero.repos src

source /opt/ros/iron/setup.bash
# colcon build --symlink-install # chyba nie potrzebne
cd ..
# source tiago/install/setup.bash # to też
colcon build --symlink-install

echo "source /opt/ros/iron/setup.bash" >> ~/.bashrc
echo "source ~/stero/install/setup.bash" >> ~/.bashrc
echo "export ROS_AUTOMATIC_DISCOVERY_RANGE=LOCALHOST" >> ~/.bashrc
echo "source ~/tiago/install/setup.bash" >> ~/.bashrc
echo "alias cb='colcon build --symlink-install'" >> ~/.bashrc
echo "alias cbp='colcon build --symlink-install --packages-select'" >> ~/.bashrc
echo "alias sb='source install/setup.bash'" >> ~/.bashrc

source install/setup.bash


