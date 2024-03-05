#ifndef DYR_SERVER_H
#define DYR_SERVER_H

#include <string>

namespace dyr {
    class Server {
    private:
        static const std::string TYPE;

        void msg(const char *msg);

        void die(const char *msg);

        void do_something(int connfd);

    public:
        std::string getName();

        int start();

        ~Server();
    };
}

#endif