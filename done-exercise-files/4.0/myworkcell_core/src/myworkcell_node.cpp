#include <ros/ros.h>
#include <myworkcell_core/LocalizePart.h>
//#include "tf/tf.h" //1
#include "moveit/move_group_interface/move_group_interface.h" //3

class ScanNPlan
{
public:
  ScanNPlan(ros::NodeHandle& nh)
  {
    vision_client_ = nh.serviceClient<myworkcell_core::LocalizePart>("localize_part");
  }

  void start(const std::string& base_frame)
  {
    ROS_INFO("Attempting to localize part");
    // Localize the part
    myworkcell_core::LocalizePart srv;
    srv.request.base_frame = base_frame;
    ROS_INFO_STREAM("Requesting pose in base frame: " << base_frame);

    if (!vision_client_.call(srv))
    {
      ROS_ERROR("Could not localize part");
      return;
    }
    ROS_INFO_STREAM("part localized: " << srv.response);

    geometry_msgs::Pose move_target = srv.response.pose; //2
    moveit::planning_interface::MoveGroupInterface move_group("manipulator");//4
    move_group.setPoseReferenceFrame(base_frame); //5
    move_group.setPoseTarget(move_target);//5
    move_group.move();//5

//    moveit_visual_tools::MoveItVisualTools visual_tools("manipulator_world");
//    visual_tools.trigger();
  }

private:
  // Planning components
  ros::ServiceClient vision_client_;
};

int main(int argc, char **argv)
{
  ros::init(argc, argv, "myworkcell_node");
  ros::NodeHandle nh;
  ros::NodeHandle private_node_handle("~");

  ros::AsyncSpinner async_spinner(1);
  async_spinner.start();

  ROS_INFO("ScanNPlan node has been initialized");

  std::string base_frame;
  private_node_handle.param<std::string>("base_frame", base_frame, "world"); // parameter name, string object reference, default value

  ScanNPlan app(nh);

  ros::Duration(.5).sleep();  // wait for the class to initialize
  app.start(base_frame);

//  ros::spin();
  ros::waitForShutdown();
}
