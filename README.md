# ROS2_IS
## Run urdf.xacro file on gazebo 
Run the commands below in seperate terminals : <br/>
``ros2 run gazebo_ros spawn_entity.py -topic robot_description -entity my_bot`` <br/>
``ros2 launch my_bot rsp.launch.py``
## Control the mobile robot on Gazebo
After running the urdf.xacro file on gazebo run the command below : <br/>
``ros2 run teleop_twist_keyboard teleop_twist_keyboard``
 
