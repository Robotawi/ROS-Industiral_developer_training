/**
** Simple ROS Node
**/
#include "ros/ros.h"
#include "fake_ar_publisher/ARMarker.h"

class Localizer{
public:
    Localizer(ros::NodeHandle &nh){
        sub = nh.subscribe<fake_ar_publisher::ARMarker>("ar_pose_marker", 1, &Localizer::visionCallback, this);
    }
    void visionCallback(const fake_ar_publisher::ARMarker::ConstPtr& msg){
        ROS_INFO_STREAM("Received the detected pose no. " << msg->header.seq <<": \n"<< msg->pose.pose);
    }

    ros::Subscriber sub;
};
int main(int argc, char ** argv){

  //init to prepare RS-related functionality
  ros::init(argc, argv, "vision_node");
  ros::NodeHandle nh;
  Localizer woekcell_loc(nh);

  ROS_INFO("Vision node started!");

  ros::spin();
}
