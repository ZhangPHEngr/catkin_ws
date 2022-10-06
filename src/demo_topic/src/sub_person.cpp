//
// Created by zph on 10/2/22.
//
#include <ros/ros.h>
#include "demo_topic/Person.h"

void personCallback(const demo_topic::Person::ConstPtr &msg) {
    ROS_INFO("Receive Person Info [%s, %d, %d]", msg->name.c_str(), msg->age, msg->sex);
}


int main(int argc, char **argv) {

    ros::init(argc, argv, "person_sub");

    ros::NodeHandle n;

    ros::Subscriber subscriber = n.subscribe("/my_demo_topic", 10, personCallback);

    ros::spin();

    return 0;
}




