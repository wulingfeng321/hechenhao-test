发布者
======
    
    #include <ros/ros.h>  // 包含ROS的核心头文件
    #include "send_pkg/xyz.h"  // 包含自定义消息类型xyz的头文件

    int main(int argc, char *argv[])
    {
       ros::init(argc, argv, "send_pkg");  // 初始化ROS节点，节点名为"send_pkg"
        ros::NodeHandle nh;  // 创建一个ROS节点句柄
        ros::Publisher pub = nh.advertise<send_pkg::xyz>("number", 10);  // 创建一个发布者，发布 话题名为"number"，消息类型为send_pkg::xyz，队列大小为10
        send_pkg::xyz msg;  // 创建一个xyz消息实例
        msg.x = 1;  // 设置消息的x字段为1
        msg.y = 2;  // 设置消息的y字段为2
        msg.z = 3;  // 设置消息的z字段为3

        // 发送坐标
        sleep(1);  // 休眠1秒
        pub.publish(msg);  // 发布消息
        ROS_INFO("Send coordinate: %ld, %ld, %ld", msg.x, msg.y, msg.z);  // 输出日志信息，显示发送的坐标

        ros::spinOnce();  // 处理所有待处理的消息回调
        return 0;  // 返回0，表示程序正常结束
    }


订阅者
======
    #include <ros/ros.h>  // 包含ROS的核心头文件
    #include "send_pkg/xyz.h"  // 包含自定义消息类型xyz的头文件

    void chatterCallback(const send_pkg::xyz::ConstPtr& msg)
    {
        printf("X: %ld Y: %ld Z: %ld\n", msg->x, msg->y, msg->z);  // 打印接收到的消息内容，显示x, y, z的值
    }

    int main(int argc, char **argv)
    {
        ros::init(argc, argv, "accept_node");  // 初始化ROS节点，节点名为"accept_node"
        ros::NodeHandle nh;  // 创建一个ROS节点句柄
        ros::Subscriber sub = nh.subscribe("number", 10, chatterCallback);  // 创建一个订阅者，订阅话题名为"number"，消息类型为send_pkg::xyz，队列大小为10，回调函数为chatterCallback
        while (ros::ok())  // 当ROS节点正常运行时
        {
            ros::spin();  // 进入一个循环，处理所有待处理的消息回调
        }
        return 0;  // 返回0，表示程序正常结束
    }


launch文件
========
    <launch>
        <node pkg="send_pkg" type="send_node" name="send_node" output="screen">
        </node>
        <node pkg="accept_pkg" type="accept_node" name="accept_node" output="screen">
        </node>
    </launch>
包含发布者与订阅者节点，规定其输出位置为屏幕

自定义消息类型
============
    int64 x
    int64 y
    int64 z

消息类型名称为xyz，包含三个int64/long int类型的数据成员x, y, z