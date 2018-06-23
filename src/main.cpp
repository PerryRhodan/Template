#include <iostream>
#include <signal.h>

#include "include/Template.h"
#include "ros/ros.h"
#include "std_msgs/String.h"



void sighandler(int sig)
{
    std::cout << "Signal " << sig << " caught..." << std::endl;

}

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main (int argc, char *argv[])
{
    signal(SIGABRT, &sighandler);
    signal(SIGTERM, &sighandler);
    signal(SIGINT, &sighandler);

    fprintf(stdout, "%s Version v%d.%d.%d\n\n", argv[0], VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH);


    if (argc < 2)
    {
        std::cout << "Usage: ./template NUMBER (double) to calculate the square root. " << std::endl;
        return 1;
    }

    Template tmpl;
    double inputValue = atof(argv[1]);
    double outputValue = tmpl.calculate_sqrt(inputValue);
    std::cout << "Square root of " << inputValue << " is " << outputValue << std::endl;

    // ros setup
    //ros::init(argc, argv, "rostemplate");
    //ros::NodeHandle nd;	
    
    /*
    ros::Subscriber sub = nd.subscribe("chatter", 10, chatterCallback);
    ros::spin(); 
	
    ros::Publisher pub = nd.advertise<std_msgs::String>("chatter", 10);
    ros::Rate loop_rate(10);
    while(ros::ok())
    {
	std_msgs::String msg;
	msg.data = "hello";
	pub.publish(msg);
	ros::spinOnce();
	loop_rate.sleep();
    }
    */

    return 0;
}

