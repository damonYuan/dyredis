#include <string.h>

#include <iostream>

#include "config.h"
#include "client/client.h"
#include "server/server.h"

using namespace dyr;

int main(int argc, char* argv[]) {
    std::cout << " Version " << dyr_VERSION_MAJOR << "." << dyr_VERSION_MINOR
              << std::endl;

    if (argc != 2) {
        std::cout << "Please specify an option: -c for client or -s for server"
                  << std::endl;
        return 1;
    }

    if (argc == 2 && strcmp(argv[1], "-s") == 0) {
        std::cout << "Starting the server..." << std::endl;
        Server server;
        return server.start();
    } else if (argc == 2 && strcmp(argv[1], "-c") == 0) {
        std::cout << "Starting the client..." << std::endl;
        Client client;
        return client.send();
    } else {
        std::cout << "Unknown options" << std::endl;
        return 1;
    }
}