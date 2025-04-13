#pragma once
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

            void doSomething(int connfd);
    };
}  // namespace dyr
