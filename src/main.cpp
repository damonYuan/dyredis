#include <iostream>
#include "Config.h"
#include "server/server.h"
#include "client/client.h"

using namespace dyr;

int main(int argc, char* argv[])
{
    std::cout << " Version "
              << DYR_VERSION_MAJOR
              << "."
              << DYR_VERSION_MINOR
              << std::endl;
    std::cout << "Hello World" << std::endl;
}