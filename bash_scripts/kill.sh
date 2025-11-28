#!/bin/bash

echo "🧹 Rozpoczynam czyszczenie procesów ROS 2 i Gazebo..."

# 1. Ubicie symulatora Gazebo (najważniejsze)
# gzserver - silnik fizyki, gzclient - okno graficzne
echo "🔪 Ubijam Gazebo..."
killall -9 gzserver gzclient 2>/dev/null

# 2. Ubicie narzędzi wizualizacji
echo "🔪 Ubijam RViz..."
killall -9 rviz2 2>/dev/null

# 3. Ubicie węzłów C++ (MoveIt, Nav2, Kontrolery)
echo "🔪 Ubijam węzły C++..."
killall -9 move_group 2>/dev/null
killall -9 robot_state_publisher 2>/dev/null
killall -9 controller_server 2>/dev/null
killall -9 planner_server 2>/dev/null
killall -9 behavior_server 2>/dev/null
killall -9 bt_navigator 2>/dev/null
killall -9 waypoint_follower 2>/dev/null
killall -9 lifecycle_manager 2>/dev/null
killall -9 map_server 2>/dev/null
killall -9 amcl 2>/dev/null
killall -9 velocity_smoother 2>/dev/null
killall -9 component_container 2>/dev/null
killall -9 component_container_isolated 2>/dev/null

# 4. Ubicie procesów Pythona związanych z ROS (Launch, Spawners)
# Używamy pkill -f, żeby szukać w pełnej nazwie komendy
echo "🔪 Ubijam skrypty Pythonowe (launch, spawner, tiago)..."
pkill -9 -f "ros2 launch"
pkill -9 -f "spawn_entity.py"
pkill -9 -f "spawner"
pkill -9 -f "tiago_gazebo"
pkill -9 -f "play_motion2"
pkill -9 -f "twist_mux"
pkill -9 -f "robot_state_publisher"

# 5. Zatrzymanie Daemona ROS 2 (często trzyma stare parametry)
echo "🛑 Zatrzymuję ROS 2 Daemon..."
ros2 daemon stop

echo "✅ Czyszczenie zakończone. System jest gotowy do ponownego uruchomienia."
echo "💡 Pamiętaj: Uruchom 'source' w terminalu przed startem nowej symulacji."