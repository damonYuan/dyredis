#ifndef DYR_CLIENT_H
#define DYR_CLIENT_H

#include <string>

namespace dyr {
    class Client {
    private:
        static const std::string TYPE;
        void die(const char *msg);
    public:
        std::string getName();
        int send();
        ~Client();
    };
}

#endif