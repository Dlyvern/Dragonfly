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

        src/modules/ServerParts/PacketParser.cpp
        include/cw_serv/modules/ServerParts/PacketParser.hpp

        include/cw_serv/modules/Robot.hpp
        src/modules/Robot.cpp

        src/submodules/SubModule.cpp
        include/cw_serv/submodules/SubModule.hpp

        include/cw_serv/submodules/HardwareManager.hpp
        src/submodules/HardwareManager.cpp

        include/cw_serv/cw_structs/RunParameters.hpp
        src/cw_structs/RunParameter.cpp

        include/cw_serv/cw_structs/Tower.hpp
        src/cw_structs/Tower.cpp

        include/cw_serv/submodules/Recorder.hpp
        src/submodules/Recorder.cpp

        include/cw_serv/Base.hpp
        src/Base.cpp
        include/cw_serv/submodules/Copyist.hpp
        src/submodules/Copyist.cpp
        src/MainNode.cpp
        include/cw_serv/MainNode.hpp
        include/cw_serv/devices/RtspCamera.hpp
        src/devices/RtspCamera.cpp
        src/devices/Device.cpp
        include/cw_serv/devices/Device.hpp

)

include(additional_cmake_lists/CMakeConfix.cmake)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(rosbag2_cpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(action_interface REQUIRED)
find_package(Qt5 COMPONENTS Widgets Network REQUIRED)
find_package(OpenCV REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

ament_target_dependencies(${PROJECT_NAME}
        rclcpp
        std_msgs
        rclcpp_action
        rclcpp_components
        action_interface
        rosbag2_cpp
        sensor_msgs
)

target_link_libraries(${PROJECT_NAME}
        Qt5::Widgets
        Qt5::Network
        ${Boost_LIBRARIES}
        ${OpenCV_LIBS}
)

target_include_directories(${PROJECT_NAME} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/${INCLUDE_DIR}>
        $<INSTALL_INTERFACE:include>
        ${Boost_INCLUDE_DIRS}
        ${OpenCV_INCLUDE_DIRS})

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



#add_executable(action_client ${INCLUDE_DIR}/actions/ActionClient.hpp ${SRC_DIR}/actions/ActionClient.cpp)
#add_executable(action_server  ${INCLUDE_DIR}/actions/ActionServer.hpp ${SRC_DIR}/actions/ActionServer.cpp)
#add_executable(main ${SRC_DIR}/main.cpp)
#add_library(command  ${INCLUDE_DIR}/cw_structs/Command.hpp ${SRC_DIR}/cw_structs/Command.cpp)
#add_executable(logger  ${INCLUDE_DIR}/modules/Logger.hpp ${SRC_DIR}/modules/Logger.cpp)
#add_library(module  ${INCLUDE_DIR}/modules/Module.hpp ${SRC_DIR}/modules/Module.cpp)
#add_library(tcp_server   ${INCLUDE_DIR}/modules/TCPServer.hpp ${SRC_DIR}/modules/TCPServer.cpp)
#add_library(client_manager ${INCLUDE_DIR}/modules/ServerParts/ClientManager.hpp ${SRC_DIR}/modules/ServerParts/ClientManager.cpp)
#add_library(packet   ${INCLUDE_DIR}/modules/ServerParts/Packet.hpp ${SRC_DIR}/modules/ServerParts/Packet.cpp)
#add_library(tcp_client ${INCLUDE_DIR}/modules/ServerParts/TCPClient.hpp ${SRC_DIR}/modules/ServerParts/TCPClient.cpp)
#
#
#set(EXEC
#    main
#    action_client
#    action_server
#    command
#    logger
#    module
#    client_manager
#    tcp_server
#    packet
#    tcp_client
#)
#
#ament_target_dependencies(main rclcpp std_msgs rclcpp_action rclcpp_components action_interface)
#target_link_libraries(main Qt5::Widgets Qt5::Network ${Boost_LIBRARIES})
#target_include_directories(main PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/${INCLUDE_DIR}> $<INSTALL_INTERFACE:include> ${Boost_INCLUDE_DIRS})
#
#ament_target_dependencies(action_client rclcpp std_msgs rclcpp_action rclcpp_components action_interface)
#target_link_libraries(action_client Qt5::Widgets Qt5::Network ${Boost_LIBRARIES})
#target_include_directories(action_client PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/${INCLUDE_DIR}> $<INSTALL_INTERFACE:include> ${Boost_INCLUDE_DIRS})
#
#ament_target_dependencies(action_server rclcpp std_msgs rclcpp_action rclcpp_components action_interface)
#target_link_libraries(action_server Qt5::Widgets Qt5::Network ${Boost_LIBRARIES})
#target_include_directories(action_server PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/${INCLUDE_DIR}> $<INSTALL_INTERFACE:include> ${Boost_INCLUDE_DIRS})
#
#ament_target_dependencies(command rclcpp std_msgs rclcpp_action rclcpp_components action_interface)
#target_link_libraries(command Qt5::Widgets Qt5::Network ${Boost_LIBRARIES})
#target_include_directories(command PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/${INCLUDE_DIR}> $<INSTALL_INTERFACE:include> ${Boost_INCLUDE_DIRS})
#
#ament_target_dependencies(logger rclcpp std_msgs rclcpp_action rclcpp_components action_interface)
#target_link_libraries(logger Qt5::Widgets Qt5::Network ${Boost_LIBRARIES})
#target_include_directories(logger PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/${INCLUDE_DIR}> $<INSTALL_INTERFACE:include> ${Boost_INCLUDE_DIRS})
#
#ament_target_dependencies(module rclcpp std_msgs rclcpp_action rclcpp_components action_interface)
#target_link_libraries(module Qt5::Widgets Qt5::Network ${Boost_LIBRARIES})
#target_include_directories(module PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/${INCLUDE_DIR}> $<INSTALL_INTERFACE:include> ${Boost_INCLUDE_DIRS})
#
#ament_target_dependencies(client_manager rclcpp std_msgs rclcpp_action rclcpp_components action_interface)
#target_link_libraries(client_manager Qt5::Widgets Qt5::Network ${Boost_LIBRARIES})
#target_include_directories(client_manager PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/${INCLUDE_DIR}> $<INSTALL_INTERFACE:include> ${Boost_INCLUDE_DIRS})
#
#ament_target_dependencies(tcp_server rclcpp std_msgs rclcpp_action rclcpp_components action_interface)
#target_link_libraries(tcp_server Qt5::Widgets Qt5::Network ${Boost_LIBRARIES})
#target_include_directories(tcp_server PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/${INCLUDE_DIR}> $<INSTALL_INTERFACE:include> ${Boost_INCLUDE_DIRS})
#
#ament_target_dependencies(packet rclcpp std_msgs rclcpp_action rclcpp_components action_interface)
#target_link_libraries(packet Qt5::Widgets Qt5::Network ${Boost_LIBRARIES})
#target_include_directories(packet PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/${INCLUDE_DIR}> $<INSTALL_INTERFACE:include> ${Boost_INCLUDE_DIRS})
#
#ament_target_dependencies(tcp_client rclcpp std_msgs rclcpp_action rclcpp_components action_interface)
#target_link_libraries(tcp_client Qt5::Widgets Qt5::Network ${Boost_LIBRARIES})
#target_include_directories(tcp_client PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/${INCLUDE_DIR}> $<INSTALL_INTERFACE:include> ${Boost_INCLUDE_DIRS})


#add_library(action_server SHARED
#        ${INCLUDE_DIR}/actions/ActionServer.hpp
#        ${SRC_DIR}/actions/ActionServer.cpp)
#
#target_include_directories(action_server PRIVATE
#        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
#        $<INSTALL_INTERFACE:include>)
#
#target_compile_definitions(action_server
#        PRIVATE "COMPOSITION_BUILDING_DLL")
#
#ament_target_dependencies(action_server
#        action_interface
#        rclcpp
#        rclcpp_action
#        rclcpp_components)
#
#rclcpp_components_register_node(action_server PLUGIN "action_server_cmd::ActionServer" EXECUTABLE action_srv)
#
#set_property(SOURCE include/cw_serv/actions/ActionServer.hpp PROPERTY SKIP_AUTOGEN ON)
#
#install(TARGETS
#        action_server
#        ARCHIVE DESTINATION lib
#        LIBRARY DESTINATION lib
#        RUNTIME DESTINATION bin)
#install(TARGETS
#        ${PROJECT_NAME}
#        #        main
#        #        action_client
#        #        action_server
#        #        command
#        #        logger
#        #        module
#        #        client_manager
#        #        tcp_server
#        #        packet
#        #        tcp_client
#        DESTINATION lib/${PROJECT_NAME})