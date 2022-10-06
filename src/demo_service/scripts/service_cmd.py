#!/usr/bin/env python
# -*- coding: utf-8 -*-

import rospy
import thread, time
from geometry_msgs.msg import Twist
from std_srvs.srv import Trigger, TriggerResponse

pubCommand = False
turtle_vel_pub = rospy.Publisher('/turtle1/cmd_vel', Twist, queue_size=10)


def pubFunc():
    while True:
        if pubCommand:
            vel_msg = Twist()
            vel_msg.linear.x = 0.5
            vel_msg.angular.z = 0.2
            turtle_vel_pub.publish(vel_msg)

        time.sleep(0.1)


def cmdCallback():
    global pubCommand
    pubCommand = bool(1 - pubCommand)

    # 显示请求数据
    rospy.loginfo("Publish turtle velocity command![%d]", pubCommand)

    # 反馈数据
    return TriggerResponse(1, "Change turtle command state!")


def my_service():
    rospy.init_node("my_service")

    rospy.Service("/my_service", Trigger, cmdCallback)

    print "Ready to receive turtle command."

    thread.start_new_thread(pubFunc, ())
    rospy.spin()


if __name__ == '__main__':
    my_service()
