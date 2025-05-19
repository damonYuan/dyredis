#if defined(_WIN32)
#  if defined(EXPORTING_DYREDIS)
#    define DECLSPEC __declspec(dllexport)
#  else
#    define DECLSPEC __declspec(dllimport)
#  endif
#else // non windows
#  define DECLSPEC
#endif

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

            void read_write_blocking(int connfd);
    };
}  // namespace dyr
