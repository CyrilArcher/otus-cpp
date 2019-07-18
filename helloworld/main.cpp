#include <iostream>
#include "version.h"

int main (int, char **)
{
    std::cout << "Hello, World! Version: " << PROJECT_VERSION << std::endl;

    return 0;
}
