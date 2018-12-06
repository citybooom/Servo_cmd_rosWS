#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Int16.h"
#include "std_msgs/Int16MultiArray.h"

#include <sstream>

int servo0 = 512;
int servo1 = 512;
int servo2 = 512;
int servo3 = 512;

void servo0Cb(const std_msgs::Int16 msg)
{
    servo0 = msg.data;
}
void servo1Cb(const std_msgs::Int16 msg)
{
    servo1 = msg.data;
}
void servo2Cb(const std_msgs::Int16 msg)
{
    servo2 = msg.data;
}
void servo3Cb(const std_msgs::Int16 msg)
{
    servo3 = msg.data;
}

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{

    ros::init(argc, argv, "servo_pub_serial");

    ros::NodeHandle n;

    ros::Publisher servo_pub_serial = n.advertise<std_msgs::Int16MultiArray>("ServoPoseSerial", 1);

    ros::Subscriber servo_0_sub = n.subscribe<std_msgs::Int16>("m0", 1, servo0Cb);
    ros::Subscriber servo_1_sub = n.subscribe<std_msgs::Int16>("m1", 1, servo1Cb);
    ros::Subscriber servo_2_sub = n.subscribe<std_msgs::Int16>("m2", 1, servo2Cb);
    ros::Subscriber servo_3_sub = n.subscribe<std_msgs::Int16>("m3", 1, servo3Cb);

    
    ros::Rate loop_rate(10);

    int i = 0;
    while (ros::ok())
    {
        /**
         * This is a message object. You stuff it with data, and then publish it.
         */
        std_msgs::Int16MultiArray msg;

        msg.data.resize(4);
        
        i = 512;
        msg.data[0] = servo0;
        msg.data[1] = servo1;
        msg.data[2] = servo2;
        msg.data[3] = servo3;


        //ROS_INFO("%d", msg.data);

        /**
         * The publish() function is how you send messages. The parameter
         * is the message object. The type of this object must agree with the type
         * given as a template parameter to the advertise<>() call, as was done
         * in the constructor above.
         */
        servo_pub_serial.publish(msg);

        ros::spinOnce();

        loop_rate.sleep();
        //++count;
    }


    return 0;
}

