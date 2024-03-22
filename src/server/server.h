#ifndef DYR_SERVER_H
#define DYR_SERVER_H

#include <string>

namespace dyr {
    class Server {
    public:
        Server();

        const std::string getName() const;

        int start();

        ~Server();
    private:
        static const std::string TYPE;

        void msg(const char *msg);

        void die(const char *msg);

        void doSomething(int connfd);
    };
}

#endif