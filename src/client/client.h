#pragma once
#include <string>

using namespace std;
namespace dyr {
    class Client {
        public:
            Client();

            [[nodiscard]] static const std::string &getName();
            [[nodiscard]] static const std::string &getType();

            int send();

            ~Client();

        private:
            static const string TYPE;
            static const string NAME;

            int32_t query(int fd, const char *text);
    };
}  // namespace dyr
