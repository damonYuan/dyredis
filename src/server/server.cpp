#include "server.h"

namespace dyr {
    const std::string Server::TYPE = "SERVER";

    std::string Server::getName() {
        return "DY_REDIS_SERVER";
    }

    Server::~Server() {

    }
}

