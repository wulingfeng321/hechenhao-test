#include <ros/ros.h>
#include "send_pkg/xyz.h"

void chatterCallback(const send_pkg::xyz::ConstPtr& msg)
{
    printf("X: %ld Y: %ld Z: %ld\n",msg->x,msg->y,msg->z);
}
int main(int argc, char **argv)
{
  ros::init(argc, argv, "accept_node");
  ros::NodeHandle nh;
  ros::Subscriber sub = nh.subscribe("number", 10, chatterCallback);
  while(ros::ok())
  {
    ros::spin();
  }
  return 0;
}
