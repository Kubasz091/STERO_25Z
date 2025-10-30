from launch import LaunchDescription
from launch_pal.include_utils import include_scoped_launch_py_description
from launch_ros.actions import Node
from launch.actions import TimerAction


def generate_launch_description():
    ld = LaunchDescription()

    gazebo = include_scoped_launch_py_description(
        pkg_name='tiago_gazebo',
        paths=['launch', 'tiago_gazebo.launch.py'],
        launch_arguments={
            'navigation': 'True',
            'moveit': "True",
            'is_public_sim': "True",
            'use_grasp_fix_plugin': "True"
        })

    ld.add_action(gazebo)

    vis = Node(package='hello_moveit_vis',
                executable='hello_moveit',
                parameters=[{'use_sim_time': True}],
                output='screen')

    delayed_vis = TimerAction(
        period=30.0,
        actions=[vis]
    )

    ld.add_action(delayed_vis)
    return ld
