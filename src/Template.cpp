//
#include "include/Template.h"

#include <Eigen/Dense>
#include <boost/asio/io_service.hpp>
#include <boost/asio/steady_timer.hpp>



Template::Template()
{
 
  
}

Template::~Template()
{

}

bool Template::run()
{
    boost::asio::io_service io_service;
    boost::asio::steady_timer timer1{io_service, std::chrono::seconds{2}};
    timer1.async_wait([](const boost::system::error_code &ec)
		    { std::cout << "2 seconds have passed\n"; });

    io_service.run();

    return true;
}

double Template::calculate_sqrt(double value)
{
    return sqrt(value);
}

