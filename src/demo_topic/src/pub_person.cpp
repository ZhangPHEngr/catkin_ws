//
// Created by zph on 10/2/22.
//

#include <ros/ros.h>
#include "demo_topic/Person.h"


int main(int argc, char **argv) {

    ros::init(argc, argv, "person_pub");

    ros::NodeHandle n;

    ros::Publisher turtle_vel_publisher = n.advertise<demo_topic::Person>("/my_demo_topic", 10);

    ros::Rate loop_rate(10);//10Hz

    int cnt = 0;
    while (ros::ok()) {
        demo_topic::Person msg;
        msg.name = "zhangsan";
        msg.age = 2;
        msg.sex = demo_topic::Person::female;

        turtle_vel_publisher.publish(msg);
        ROS_INFO("Publish Person Info [%s, %d, %d]", msg.name.c_str(), msg.age, msg.sex);

        loop_rate.sleep();
    }

    return 0;
}
