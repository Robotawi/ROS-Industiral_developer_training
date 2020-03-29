/**
** Simple ROS Node
**/
#include "ros/ros.h"

int main(int argc, char ** argv){

  //init to prepare RS-related functionality
  ros::init(argc, argv, "vision_node");

  ros::NodeHandle hn;

  ROS_INFO("Hello to ROS-I world, Mohamed Raessa :)");

  ros::spin();
}
