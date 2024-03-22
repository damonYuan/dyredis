#ifndef DYR_SERVER_H
#define DYR_SERVER_H

#include <string>

namespace dyr {
    class Server {
    public:
        Server();

        [[nodiscard]] static const std::string &getName();
        [[nodiscard]] static const std::string &getType();

        int start();

        ~Server();

    private:
        static const std::string TYPE;
        static const std::string NAME;

        static void msg(const char *msg);

        static void die(const char *msg);

        void doSomething(int connfd);
    };
}

#endif