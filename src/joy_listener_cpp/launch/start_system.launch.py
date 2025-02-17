from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        # Joy node başlatma
        Node(
            package='joy',
            executable='joy_node',
            name='joy_node',
            output='screen'
        ),


        Node(
            package='joy_listener_cpp',
            executable='joy_listener',
            name='joy_listener',
            output='screen'
        ),
    ])
