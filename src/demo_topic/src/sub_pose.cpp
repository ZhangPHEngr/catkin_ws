//
// Created by zph on 10/2/22.
//
#include <ros/ros.h>
#include "turtlesim/Pose.h"

void poseCallback(const turtlesim::Pose::ConstPtr& msg){
    ROS_INFO("Turtle pose: x:%0.6f, y:%0.6f", msg->x, msg->y);
}


int main(int argc, char **argv){

    ros::init(argc, argv, "sub_pose");

    ros::NodeHandle n;

    ros::Subscriber subscriber = n.subscribe("/turtle1/pose", 10, poseCallback);

    ros::spin();

    return 0;
}




