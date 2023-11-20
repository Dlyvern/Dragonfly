cmake_minimum_required(VERSION 3.8)
project(cw_serv)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(INCLUDE_DIR include/cw_serv)

set(SRC_DIR src)

set(SOURCE_FILES
        ${SRC_DIR}/main.cpp

        ${INCLUDE_DIR}/actions/ActionClient.hpp
        ${SRC_DIR}/actions/ActionClient.cpp

        ${INCLUDE_DIR}/actions/ActionServer.hpp
        ${SRC_DIR}/actions/ActionServer.cpp

        ${INCLUDE_DIR}/cw_structs/Command.hpp
        ${SRC_DIR}/cw_structs/Command.cpp

        ${INCLUDE_DIR}/modules/Logger.hpp
        ${SRC_DIR}/modules/Logger.cpp

        ${INCLUDE_DIR}/modules/Module.hpp
        ${SRC_DIR}/modules/Module.cpp

        ${INCLUDE_DIR}/modules/TCPServer.hpp
        ${SRC_DIR}/modules/TCPServer.cpp

        ${INCLUDE_DIR}/modules/ServerParts/ClientManager.hpp
        ${SRC_DIR}/modules/ServerParts/ClientManager.cpp

        ${INCLUDE_DIR}/modules/ServerParts/Packet.hpp
        ${SRC_DIR}/modules/ServerParts/Packet.cpp

        ${INCLUDE_DIR}/modules/ServerParts/TCPClient.hpp
        ${SRC_DIR}/modules/ServerParts/TCPClient.cpp
)

include(additional_cmake_lists/CMakeConfix.cmake)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(action_interface REQUIRED)
find_package(Qt5 COMPONENTS Widgets Network REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

ament_target_dependencies(${PROJECT_NAME}
        rclcpp
        std_msgs
        rclcpp_action
        rclcpp_components
        action_interface
)

target_link_libraries(${PROJECT_NAME}
        Qt5::Widgets
        Qt5::Network
        ${Boost_LIBRARIES}
)

target_include_directories(${PROJECT_NAME} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/${INCLUDE_DIR}>
        $<INSTALL_INTERFACE:include>
        ${Boost_INCLUDE_DIRS})

install(TARGETS
        ${PROJECT_NAME}
        DESTINATION lib/${PROJECT_NAME})

install(
        DIRECTORY launch
        DESTINATION share/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package(CONFIG_EXTRAS additional_cmake_lists/CMakeConfix.cmake)