#include "server.h"

#include <arpa/inet.h>
#include <errno.h>
#include <netinet/ip.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

namespace dyr {

    const std::string Server::TYPE = "SERVER";
    const std::string Server::NAME = "DY_REDIS_SERVER";

    Server::Server() = default;

    const std::string &Server::getName() { return NAME; }

    const std::string &Server::getType() { return TYPE; }

    void Server::msg(const char *msg) { fprintf(stderr, "%s\n", msg); }

    void Server::die(const char *msg) {
        int err = errno;
        fprintf(stderr, "[%d] %s\n", err, msg);
        abort();
    }

    void Server::doSomething(int connfd) {
        char rbuf[64] = {};
        ssize_t n = read(connfd, rbuf, sizeof(rbuf) - 1);
        if (n < 0) {
            msg("read() error");
            return;
        }
        printf("client says: %s\n", rbuf);

        char wbuf[] = "world";
        write(connfd, wbuf, strlen(wbuf));
    }

    int Server::start() {
        // get a socket for server
        int fd = socket(AF_INET, SOCK_STREAM, 0);
        if (fd < 0) {
            die("socket()");
        }
        // this is needed for most server applications
        int val = 1;
        setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
        // bind
        struct sockaddr_in addr = {};
        addr.sin_family = AF_INET;
        addr.sin_port = ntohs(1234);
        addr.sin_addr.s_addr = ntohl(0);  // wildcard address 0.0.0.0
        int rv = bind(fd, (const sockaddr *)&addr, sizeof(addr));
        if (rv) {
            die("bind()");
        }

        // listen
        rv = listen(fd, SOMAXCONN);
        if (rv) {
            die("listen()");
        }

        while (true) {
            // accept
            struct sockaddr_in client_addr = {};
            socklen_t socklen = sizeof(client_addr);
            int connfd = accept(fd, (struct sockaddr *)&client_addr, &socklen);
            if (connfd < 0) {
                continue;  // error
            }

            doSomething(connfd);
            close(connfd);
        }

        return 0;
    }

    Server::~Server() {}
}  // namespace dyr
