#include "ros/ros.h"
#include "std_msgs/String.h"
#include "hw1/output_msg.h"

/**
 * This tutorial demonstrates simple receipt of messages over the ROS system.
 */
void chatterCallback(const hw1::output_msg::ConstPtr& msg)
{
	ROS_INFO("The id :[%d]", msg->id);
	ROS_INFO("BMI: [%f]", msg->BMI);
}

int main(int argc, char *argv[])
{
	ros::init(argc, argv, "output_sub");

	
	ros::NodeHandle n;

	
	ros::Subscriber sub = n.subscribe("output_topic", 1000, chatterCallback);

	
	ros::spin();

	return 0;
}