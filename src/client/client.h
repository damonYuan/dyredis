#ifndef DYR_CLIENT_H
#define DYR_CLIENT_H

#include <string>

using namespace std;
namespace dyr {
    class Client {
    private:
        static const string TYPE;

        void die(const char *msg);

    public:
        string getName();

        int send();

        ~Client();
    };
}

#endif