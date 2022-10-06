//
// Created by zph on 10/2/22.
//
#include <ros/ros.h>
#include "turtlesim/Spawn.h"


int main(int argc, char **argv){

    ros::init(argc, argv, "my_spawn");
    ros::NodeHandle n;

    ros::service::waitForService("/spawn");
    ros::ServiceClient sc = n.serviceClient<turtlesim::Spawn>("/spawn");

    turtlesim::Spawn srv;
    srv.request.x = 2.0;
    srv.request.y = 2.0;
    srv.request.name = "turtle2";

    ROS_INFO("Call service to spawn turtle[x:%0.6f, y:%0.6f, name:%s]", srv.request.x, srv.request.y, srv.request.name.c_str());
    sc.call(srv);//一直等到
    ROS_INFO("Spawn turtle successfully [name:%s]", srv.response.name.c_str());

    return 0;
}
