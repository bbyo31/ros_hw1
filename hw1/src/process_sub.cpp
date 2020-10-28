#include "ros/ros.h"
#include "std_msgs/String.h"
#include "hw1/input_msg.h"
#include "hw1/output_msg.h"

class subandpub
{
public:
  subandpub()
  {
    
    pub_ = n_.advertise<hw1::output_msg>("output_topic", 1000);

 
    sub_ = n_.subscribe("input_topic", 1000, &subandpub::callback, this);
  }
 
  void callback(const hw1::input_msg::ConstPtr& msg)
  {
    hw1::output_msg msg2;

		msg2.id = msg->id;
		msg2.BMI=msg->weight/((msg->hight)*(msg->hight));
		
		pub_.publish(msg2);
  }
 
private:
  ros::NodeHandle n_; 
  ros::Publisher pub_;
  ros::Subscriber sub_;
 
};


int main(int argc, char *argv[])
{
	
	ros::init(argc, argv, "process_sub");


  subandpub p;

	ros::spin();

	return 0;
}