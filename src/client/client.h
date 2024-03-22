#ifndef DYR_CLIENT_H
#define DYR_CLIENT_H

#include <string>

using namespace std;
namespace dyr {
    class Client {
    public:
        Client();

        [[nodiscard]] static const std::string &getName();

        static int send();

        ~Client();

    private:
        static const string TYPE;
        static const string NAME;

        static void die(const char *msg);
    };
}

#endif