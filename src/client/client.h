#pragma once
#include <string>

using namespace std;
namespace dyr {
    class Client {
        public:
            Client();

            [[nodiscard]] static const std::string &getName();
            [[nodiscard]] static const std::string &getType();

            static int send();

            ~Client();

        private:
            static const string TYPE;
            static const string NAME;

            static void die(const char *msg);
    };
}  // namespace dyr
