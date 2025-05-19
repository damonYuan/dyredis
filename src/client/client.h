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

using namespace std;
namespace dyr {
    class Client {
        public:
            Client();

            [[nodiscard]] static const std::string &getName();
            [[nodiscard]] static const std::string &getType();

            int send(int argc, char **argv);

            ~Client();

        private:
            static const string TYPE;
            static const string NAME;

            int32_t query(int fd, const char *text);
    };
}  // namespace dyr
