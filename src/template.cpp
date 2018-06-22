//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <signal.h>

#include <Eigen/Dense>


bool forevervar = true;

void sighandler(int sig)
{
    std::cout << "Signal " << sig << " caught..." << std::endl;
    forevervar = false;

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


    return 0;
}

