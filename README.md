# ROS2_IS
## Workspace preparation
``mkdir ros2_ws`` <br/>
``cd ros2_ws`` <br/>
``mkdir src`` <br/>
``cd src`` <br/>
``git clone https://github.com/BengIslam7/ROS2_IS.git`` <br/>
``mv ROS2_IS my_bot`` <br/>
``cd ..`` <br/>
``colcon build --symlink-install`` <br/>
``gedit ~/.bashrc`` and at the end of file add ``source /workspace_path/install/setup.bash`` 
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
## Run nodes
Run ``ros2 run my_bot camera_node`` to start camera node <br/>

 
