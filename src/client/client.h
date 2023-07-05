#ifndef DYR_CLIENT_H
#define DYR_CLIENT_H

#include <string>

namespace dyr {
    class Client {
    private:
        static const std::string TYPE;
    public:
        std::string getName();
        ~Client();
    };
}

#endif