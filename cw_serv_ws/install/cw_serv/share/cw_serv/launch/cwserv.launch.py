import os
from launch import LaunchDescription
from launch_ros.actions import Node
from configparser import ConfigParser

current_dir = os.path.dirname(os.path.realpath(__file__))

ini_file_path = os.path.join(current_dir, 'settings_for_launch_file', 'main_settings.ini')

config = ConfigParser()

config.read(ini_file_path)

tcp_ip_address = config.get('NETWORK_TCP_IP_SERVER', 'TcpIpAddress')
tcp_port = config.getint('NETWORK_TCP_IP_SERVER', 'TcpPort')


def generate_launch_description():
    return LaunchDescription([
        Node(
            package='cw_serv',
            executable='cw_serv',
            name='cw_serv',
            output="screen",
            parameters =
            [
                {"server/ip": tcp_ip_address},
                {"server/port_tcp": tcp_port}
            ]
        )
    ])
