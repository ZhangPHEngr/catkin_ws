//
// Created by zph on 10/2/22.
//

#include <ros/ros.h>
#include "geometry_msgs/Twist.h"


int main(int argc, char **argv) {

    ros::init(argc, argv, "velocity_publisher");

    ros::NodeHandle n;

    ros::Publisher turtle_vel_publisher = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);

    ros::Rate loop_rate(10);//10Hz

    int cnt = 0;
    while (ros::ok()) {
        geometry_msgs::Twist vel_msg;
        vel_msg.linear.x = 0.5;
        vel_msg.angular.z = 0.2;

        turtle_vel_publisher.publish(vel_msg);
        ROS_INFO("Publsh turtle velocity command[%0.2f m/s, %0.2f rad/s]", vel_msg.linear.x, vel_msg.angular.z);

        loop_rate.sleep();
    }

    return 0;
}
