//
// Created by zph on 10/2/22.
//
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <std_srvs/Trigger.h>

ros::Publisher turtle_pub;
bool pubCommand = false;

bool cmdCallback(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res){
    pubCommand = !pubCommand;

    // 显示请求数据
    ROS_INFO("Publish turtle velocity command [%s]", pubCommand==true?"Yes":"No");

    // 设置反馈数据
    res.success = true;
    res.message = "Change turtle command state!";

    return true;
}


int main(int argc, char **argv){

    ros::init(argc, argv, "my_service");
    ros::NodeHandle n;

    ros::ServiceServer ss = n.advertiseService("/my_service", cmdCallback);
    turtle_pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);

    ros::Rate loop_rate(10);

    while (ros::ok()){
        // 查看一次回调函数队列
        ros::spinOnce();

        // 如果标志为true，则发布速度指令
        if (pubCommand){
            geometry_msgs::Twist msg;
            msg.linear.x = 0.5;
            msg.angular.z = 0.2;
            turtle_pub.publish(msg);
        }

        //按照循环频率延时
        loop_rate.sleep();
    }

    return 0;
}
