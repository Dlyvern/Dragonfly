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


def generate_launch_description():
    container = (ComposableNodeContainer
    (
        name='cw_serv',
        namespace='',
        package='cw_serv',
        executable='cw_serv',
        composable_node_descriptions=
        [
            ComposableNode(
                package='cw_serv',
                plugin='srv',
                name='srv_node',
                parameters =
                [
                    {"server/ip": tcp_ip_address},
                    {"server/port_tcp": tcp_port}
                ]
            ),
            ComposableNode(
                package='cw_serv',
                plugin='logger',
                name='logger_node'
            ),
        ],
        output='screen',
    ))

    return LaunchDescription([container])

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
