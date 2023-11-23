import os
from launch import LaunchDescription
from launch_ros.actions import ComposableNodeContainer
from launch_ros.descriptions import ComposableNode

try:
    from configparser import ConfigParser
except ImportError:
    from ConfigParser import ConfigParser

current_dir = os.path.dirname(os.path.realpath(__file__))

ini_file_path = os.path.join(current_dir, 'settings_for_launch_file', 'main_settings.ini')
    
config = ConfigParser()

config.read(ini_file_path)

tcp_ip_address = config.get('NETWORK_TCP_IP_SERVER', 'TcpIpAddress')
tcp_port = config.getint('NETWORK_TCP_IP_SERVER', 'TcpPort')


from launch import LaunchDescription
from launch_ros.actions import Node


def generate_test_description():
    launch_actions = []
    node_names = []
    node_names_real = [
    "cw_serv",
    "action_srv",
    "action_server",
    "logger",
    "action_client"]

    for i in range(6):
        launch_actions.append(
            launch_ros.actions.Node
            (
                executable='talker',
                package='demo_nodes_cpp',
                name='demo_node_' + str(i)
            )
        )
        node_names.append('demo_node_' + str(i))

    launch_actions.append(launch_testing.actions.ReadyToTest())
    return launch.LaunchDescription(launch_actions), {'node_list': node_names}
    
    

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='cw_serv',
            executable='cw_serv',
            name='cw_serv',
		parameters =
	       	[
		    {"server/ip": tcp_ip_address},
		    {"server/port_tcp": tcp_port}
		]
        )
    ])


# def generate_launch_description():
#     container = (ComposableNodeContainer
#     (
#         name='cw_serv',
#         namespace='',
#         package='cw_serv',
#         executable='cw_serv',
#         composable_node_descriptions=
#         [
#             ComposableNode(
#                 package='cw_serv',
#                 plugin='srv',
#                 name='srv_node',
#                 parameters =
#                 [
#                     {"server/ip": tcp_ip_address},
#                     {"server/port_tcp": tcp_port}
#                 ]
#             ),
#             ComposableNode(
#                 package='cw_serv',
#                 plugin='logger',
#                 name='logger_node'
#             ),
#             ComposableNode(
#                 package='cw_serv',
#                 plugin='action_srv',
#                 name='action_srv_node'
#             ),
#         ],
#         output='screen',
#     ))
#
#     return LaunchDescription([container])

#
# def generate_launch_description():
#     container = (ComposableNodeContainer
#     (
#         name='cw_serv',
#         namespace='',
#         package='cw_serv',
#         executable='cw_serv',
#         composable_node_descriptions=
#         [
#             ComposableNode(
#                 package='cw_serv',
#                 plugin='srv',
#                 name='srv_node',
#                 parameters =
#                 [
#                     {"server/ip": tcp_ip_address},
#                     {"server/port_tcp": tcp_port}
#                 ]
#             ),
#             ComposableNode(
#                 package='cw_serv',
#                 plugin='logger',
#                 name='logger_node'
#             ),
#         ],
#         output='screen',
#     ))
#
#     return LaunchDescription([container])
