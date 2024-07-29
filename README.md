# ROS2_IS
## Workspace preparation
``cd`` <br/>
``mkdir ros2_ws`` <br/>
``cd ros2_ws`` <br/>
``mkdir src`` <br/>
``cd src`` <br/>
``git clone https://github.com/BengIslam7/ROS2_IS.git`` <br/>
``mv ROS2_IS my_bot`` <br/>
``cd ..`` <br/>
``echo 'source ~/ros2_ws/install/setup.bash' >> ~/.bashrc ``  <br/>
``colcon build --symlink-install``
## Simulate the robot with Gazebo and Rviz
Run the commands below in seperate terminals : <br/>
``ros2 run gazebo_ros spawn_entity.py -topic robot_description -entity my_bot`` <br/>
``ros2 launch my_bot rsp.launch.py``
## Control the mobile robot on Gazebo with Keyboard
``ros2 run teleop_twist_keyboard teleop_twist_keyboard``
## Make the robot autonomous with NAV2
``ros2 launch nav2_bringup navigation_launch.py use_sim_time:=true``
## Run nodes
Run ``ros2 run my_bot camera_node`` to start camera node <br/>
Run ``ros2 run my_bot subscriber_node`` to start informations node 

 
