#include <ros/ros.h>
#include <std_msgs/Int64.h>

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "send_pkg");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<std_msgs::Int64>("number", 10);
    std_msgs::Int64 msg;

    ros::Rate loop_rate(1); 

    int64_t number1 = 256; 
    int64_t number2 = 512; 
    int64_t number3 = 1024;

    // 发送数字
    sleep(1);
    msg.data = number1;
    pub.publish(msg);
    //ROS_INFO("Send number1: %ld", number1);

    sleep(1);
    msg.data = number2;
    pub.publish(msg);
    //ROS_INFO("Send number2: %ld", number2);

    sleep(1);
    msg.data = number3;
    pub.publish(msg);
    //ROS_INFO("Send number3: %ld", number3);
    ros::spinOnce(); 
    return 0;
}
