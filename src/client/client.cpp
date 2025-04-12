#include "client.h"

#include <arpa/inet.h>
#include <errno.h>
#include <netinet/ip.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

using namespace std;
namespace dyr {

    const std::string Client::TYPE = "CLIENT";
    const std::string Client::NAME = "DY_REDIS_CLIENT";

    Client::Client() = default;

    const string &Client::getName() { return NAME; }

    const string &Client::getType() { return TYPE; }

    void Client::die(const char *msg) {
        int err = errno;
        fprintf(stderr, "[%d] %s\n", err, msg);
        abort();
    }

    int Client::send() {
        int fd = socket(AF_INET, SOCK_STREAM, 0);
        if (fd < 0) {
            die("socket()");
        }

        struct sockaddr_in addr = {};
        addr.sin_family = AF_INET;
        addr.sin_port = ntohs(1234);
        addr.sin_addr.s_addr = ntohl(INADDR_LOOPBACK);  // 127.0.0.1
        // bind() can also be used on the client socket before connect() to specify the source address. 
        // Without this, the OS will automatically select a source address. 
        // This is useful for selecting a particular source address if multiple ones are available. 
        // If the port in bind() is zero, the OS will automatically pick a port.
        int rv = connect(fd, (const struct sockaddr *)&addr, sizeof(addr));
        if (rv) {
            die("connect");
        }

        char msg[] = "hello";
        write(fd, msg, strlen(msg));

        char rbuf[64] = {};
        ssize_t n = read(fd, rbuf, sizeof(rbuf) - 1);
        if (n < 0) {
            die("read");
        }
        printf("server says: %s\n", rbuf);
        close(fd);
        return 0;
    }

    Client::~Client() {}
}  // namespace dyr
