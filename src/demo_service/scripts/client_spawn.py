#!/usr/bin/env python
# -*- coding: utf-8 -*-

import rospy
from turtlesim.srv import Spawn


def turtle_spawn():
    rospy.init_node("my_spawn")

    rospy.wait_for_service("/spawn")

    try:
        sc = rospy.ServiceProxy('/spawn', Spawn)
        res = sc(2.0, 5.0, 0.0, "turtle4")
        print "Spwan turtle successfully [name:%s]" % res.name
    except rospy.ServiceException, e:
        print "Service call failed: %s" % e


if __name__ == '__main__':
    turtle_spawn()
