cd /opt/ai_lab/stero
rm -rf build install log

cb #-> colcon build --symlink-install
source install/setup.bash