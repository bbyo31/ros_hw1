#include "ros/ros.h"
#include "std_msgs/String.h"
#include "hw1/input_msg.h"
#include <sstream>

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char *argv[])
{
	
	ros::init(argc, argv, "input_pub");

	
	ros::NodeHandle n;
	
	
	ros::Publisher chatter_pub = n.advertise<hw1::input_msg>("input_topic", 1000);

	ros::Rate loop_rate(0.1);

	
	int count = 0;
	while (ros::ok())
	{
		/**
		 * This is a message object. You stuff it with data, and then publish it.
		 */
		hw1::input_msg msg;
		int id_;
		float hig_;
		float wei_;
		n.getParam("idd", id_);
		n.getParam("hig", hig_);
		n.getParam("wei", wei_);
		msg.id=id_;
		msg.hight=hig_;
 		msg.weight=wei_;	
		chatter_pub.publish(msg);

		ros::spinOnce();

		loop_rate.sleep();
		++count;
	}

	return 0;
}