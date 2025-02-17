cmake_minimum_required(VERSION 3.8)
project(joy_listener_cpp)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)

add_executable(joy_listener src/joy_listener.cpp)

ament_target_dependencies(joy_listener
  rclcpp
  sensor_msgs
  geometry_msgs
)

install(TARGETS
  joy_listener
  DESTINATION lib/${PROJECT_NAME}
)
install(
  DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}/
)

ament_package()
