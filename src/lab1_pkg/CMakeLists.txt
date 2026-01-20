cmake_minimum_required(VERSION 3.8)
project(lab1_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(nav2_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "action/NavigateToWaypoints.action"
  DEPENDENCIES geometry_msgs
)

add_executable(hexagon_mover src/hexagon_mover.cpp)
target_include_directories(hexagon_mover PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_compile_features(hexagon_mover PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17
ament_target_dependencies(
  hexagon_mover
  "rclcpp"
  "geometry_msgs"
  "nav_msgs"
)

install(TARGETS hexagon_mover
  DESTINATION lib/${PROJECT_NAME})

add_executable(square_mover src/square_mover.cpp)
target_include_directories(square_mover PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_compile_features(square_mover PUBLIC c_std_99 cxx_std_17)
ament_target_dependencies(
  square_mover
  "rclcpp"
  "geometry_msgs"
  "nav_msgs"
  "tf2"
  "tf2_geometry_msgs"
)

install(TARGETS square_mover
  DESTINATION lib/${PROJECT_NAME})

install(PROGRAMS
  scripts/plot_results.py
  scripts/lab2_p2_node.py
  scripts/test_p2_client.py
  DESTINATION lib/${PROJECT_NAME})


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

# Define place_navigator executable
add_executable(place_navigator src/place_navigator.cpp)
target_include_directories(place_navigator PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_compile_features(place_navigator PUBLIC c_std_99 cxx_std_17)
ament_target_dependencies(
  place_navigator
  "rclcpp"
  "rclcpp_action"
  "nav2_msgs"
  "geometry_msgs"
)

install(TARGETS place_navigator
  DESTINATION lib/${PROJECT_NAME})



install(DIRECTORY
  config
  launch
  worlds
  maps
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
