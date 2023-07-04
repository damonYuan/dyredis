#ifndef DYR_SERVER_H
#define DYR_SERVER_H

#include <string>

namespace dyr {
    class Server {
    private:
        static const std::string TYPE;
    public:
        std::string getName();
        ~Server();
    };
}

#endif