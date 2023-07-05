#include "client.h"

namespace dyr {
    const std::string Client::TYPE = "CLIENT";

    std::string Client::getName() {
        return "DY_REDIS_CLIENT";
    }

    Client::~Client() {}
}

