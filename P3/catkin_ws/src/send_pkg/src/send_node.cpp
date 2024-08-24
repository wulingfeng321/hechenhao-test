#include <ros/ros.h>
#include "send_pkg/xyz.h"

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "send_pkg");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<send_pkg::xyz>("number", 10);
    send_pkg::xyz msg;
    msg.x = 1;
    msg.y = 2;
    msg.z = 3;

    // 发送坐标
    sleep(1);
    pub.publish(msg);
    ROS_INFO("Send coordinate: %ld, %ld, %ld", msg.x, msg.y, msg.z);

    ros::spinOnce(); 
    return 0;
}
