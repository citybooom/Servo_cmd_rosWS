#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Int16.h"

#include <sstream>

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{

  ros::init(argc, argv, "servo2pub");

  ros::NodeHandle n;

  ros::Publisher servo2_pub = n.advertise<std_msgs::Int16>("Servo2Pos", 1);

  ros::Rate loop_rate(10);

int i = 0;
  while (ros::ok())
  {
    /**
     * This is a message object. You stuff it with data, and then publish it.
     */
	std_msgs::Int16 msg;


if (i < 1024)
{
i = i + 10;
msg.data = i;
}
else
{
i = 0;
}

    ROS_INFO("%d", msg.data);

    /**
     * The publish() function is how you send messages. The parameter
     * is the message object. The type of this object must agree with the type
     * given as a template parameter to the advertise<>() call, as was done
     * in the constructor above.
     */
    servo2_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    //++count;
  }


  return 0;
}

