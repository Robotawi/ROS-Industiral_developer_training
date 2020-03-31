//
// Created by zozo on 3/31/20.
//

#include "ros/ros.h"
#include "myworkcell_core/LocalizePart.h"

class ScanNPlan{
public:
    ScanNPlan(ros::NodeHandle& nh){
        //create the service client, it will ask the server that is collecting the vision data for the pose info
        vision_client_ = nh.serviceClient<myworkcell_core::LocalizePart>("localize_part");
    }
    void start(){
        myworkcell_core::LocalizePart srv;
        if(!vision_client_.call(srv)){
            ROS_ERROR("Could not localize part!");
            return;
        }
        ROS_INFO_STREAM("Got part localized, pose data is "<< srv.response);
    }

private:
    ros::ServiceClient vision_client_;
};

int main(int argc, char* argv[]){
    ros::init(argc, argv, "myworkscell_node");
    ros::NodeHandle nh;

    ScanNPlan app(nh);

    app.start();

    ros::spin();
    return 0;
}