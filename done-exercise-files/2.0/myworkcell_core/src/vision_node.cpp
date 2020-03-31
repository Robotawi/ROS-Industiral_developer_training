/**
** Simple ROS Node
**/
#include "ros/ros.h"
#include "fake_ar_publisher/ARMarker.h"
#include "myworkcell_core/LocalizePart.h"

class Localizer{
public:
    Localizer(ros::NodeHandle &nh){
        sub_ = nh.subscribe<fake_ar_publisher::ARMarker>("ar_pose_marker", 1, &Localizer::visionCallback, this);

        server_ = nh.advertiseService("localize_part", &Localizer::localizePart, this);
    }
    void visionCallback(const fake_ar_publisher::ARMarker::ConstPtr& msg){
        last_msg_ = msg;
//        ROS_INFO_STREAM("Received the detected pose no. " << last_msg_->header.seq <<": \n"<< last_msg_->pose.pose);
    }

    bool localizePart(myworkcell_core::LocalizePartRequest & req, myworkcell_core::LocalizePartResponse & res){
        fake_ar_publisher::ARMarker::ConstPtr p = last_msg_;
        if (!p) return false;
        res.pose = p->pose.pose;
        return true;
    }

    ros::Subscriber sub_;
    ros::ServiceServer server_;
    fake_ar_publisher::ARMarker::ConstPtr last_msg_;
};
int main(int argc, char ** argv){

  //init to prepare RS-related functionality
  ros::init(argc, argv, "vision_node");
  ros::NodeHandle nh;
  Localizer woekcell_loc(nh);

  ROS_INFO("Vision node started!");

  ros::spin();
}
