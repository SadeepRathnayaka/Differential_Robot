cmake_minimum_required(VERSION 3.8)
project(twist_to_twist_stamped)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)

add_executable(twist_to_twist_stamped src/twist_to_twist_stamped.cpp)
add_executable(twist_to_twist_stamped_robot src/twist_to_twist_stamped_robot.cpp)

target_include_directories(twist_to_twist_stamped PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_compile_features(twist_to_twist_stamped PUBLIC cxx_std_14)
ament_target_dependencies(
  twist_to_twist_stamped
  "rclcpp" 
  "geometry_msgs"
  )

  target_include_directories(twist_to_twist_stamped_robot PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_compile_features(twist_to_twist_stamped_robot PUBLIC cxx_std_14)
ament_target_dependencies(
  twist_to_twist_stamped_robot
  "rclcpp" 
  "geometry_msgs"
  )

install(TARGETS 
  twist_to_twist_stamped
  twist_to_twist_stamped_robot
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

ament_package()
