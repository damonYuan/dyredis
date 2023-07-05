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

    if (strcmp(argv[1], "-s") == 0) {
        std::cout << "Starting the server..." << std::endl;
        Server server;
        return server.start();
    } else if (strcmp(argv[1], "-c") == 0) {
        std::cout << "Starting the client..." << std::endl;
        Client client;
        return client.send();
    } else {
        std::cout << "Unknown options" << std::endl;
        return 1;
    }
}