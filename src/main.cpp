#include <iostream>
#include <signal.h>

#include "include/Template.h"


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

    Template tmpl;
    double inputValue = atof(argv[1]);
    double outputValue = tmpl.calculate_sqrt(inputValue);
    std::cout << "Square root of " << inputValue << " is " << outputValue << std::endl;

 return 0;
}

