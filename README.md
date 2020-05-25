# ros-industiral_developer_training

### Ex 1.3 
The goal is to become familiar with ROS package and node concepts.
1. Create a myworkcell_core package.
2. Add a simple node to it, and editing the package's CMakeLists accordingly.
3. Write the node code to print "Hello to ROS-I" message.

### Ex 1.4 
The goal is to become familiar with ROS topic and msg concepts.
1. Clone fake_ar_publisher package and use it as a source of AR markers poses.
2. Write a subscriber node that subscribes to the above topic.

### Ex 2.0 
The goal is to learn how to build custom service files and utilize them in a request/response communication scheme.
1. Create srv files, and server and client for it.
2. Edit the package CMakeLists to allow the C++ code generation for the created srv.
3. Add more functionality (service server) to the above mentioned node in (Ex 1.4) to be able to respond to requests about the last detected pose.
4. Write a service client that requests the pose information from the server in 3 and print it.

### Ex 2.2
Creating launch files for starting different nodes.
1. Get used to the idea behind support packages to contain launch files.
2. Create a launch file that starts two nodes from different packages at once.
 
 
### Ex 2.3
The goal is to become familiar with ROS parameters
1. Understand [private names](http://wiki.ros.org/Names#Graph) and loading parameters within [nodes](http://wiki.ros.org/roscpp_tutorials/Tutorials/AccessingPrivateNamesWithNodeHandle).
2. Setting the request part of (Ex 2.0) according to the loaded parameter.
3. Setting the parameter that belongs to a specific node from the launch file. 


### Ex 3.0
Introducing Universal Robot Description Format (URDF) to describe robot kinematics and perform collision detection.
1. Make a urdf file for the robot workcell and insert virtual links (without geometry) for the world and camera frames.
2. Insert basic visual and collision geometries and set joints between them and the world frame.
3. Visualize the setting described in the workcell urdf file through rviz.

Not: It is better to clarify that ROS packages for robot_state_publisher and joint_state_publisher are needed with rviz for the visualization. It would be more interesting for the beginners to know that to visualize robots rviz needs transformation frames.
The flow is that the joint_state_publlisher publishes the joint states and robot_state_publisher subscribes to it and publishes the calculated transformation frames (TF) given the urdf file and the joint_states (angles). Rviz subscribes to the (TF) topic and visualizes it along with the model of the robot.    
 