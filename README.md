# ROS2_IS
## Simulate the robot with Gazebo and Rviz
Run the commands below in seperate terminals : <br/>
``ros2 run gazebo_ros spawn_entity.py -topic robot_description -entity my_bot`` <br/>
``ros2 launch my_bot rsp.launch.py``
## Control the mobile robot on Gazebo with Keyboard
After running the robot run the command below : <br/>
``ros2 run teleop_twist_keyboard teleop_twist_keyboard``
## Make navigate the robot with NAV2
Run the command below to make the robot autonomous : <br/>
``ros2 launch nav2_bringup navigation_launch.py use_sim_time:=true``
 
