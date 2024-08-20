#include <ros/ros.h>
#include <std_msgs/Int64.h>

int num=0;
void chatterCallback(const std_msgs::Int64::ConstPtr& msg)
{
    //ROS_WARN("I heard: [%ld]", msg->data);
    switch(num%3)
    {
        case 0:
            printf("X: %ld   ", msg->data);
            break;
        case 1:
            printf("Y: %ld   ", msg->data);
            break;
        case 2:
            printf("Z: %ld   ", msg->data);
            break;
        default:
            break;
    }
    num++;
    fflush(stdout);
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
