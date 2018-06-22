//
#include "include/Template.h"

#include <Eigen/Dense>
#include <boost/asio/io_service.hpp>
#include <boost/asio/steady_timer.hpp>

void sighandler(int sig)
{
    std::cout << "Signal " << sig << " caught..." << std::endl;

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

    double inputValue = atof(argv[1]);
    double outputValue = sqrt(inputValue);
    std::cout << "Square root of " << inputValue << " is " << outputValue << std::endl;


    
    boost::asio::io_service io_service;
    boost::asio::steady_timer timer1{io_service, std::chrono::seconds{2}};
    timer1.async_wait([](const boost::system::error_code &ec)
		    { std::cout << "2 seconds have passed\n"; });

    io_service.run();

    return 0;
}

