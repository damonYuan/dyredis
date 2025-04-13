#include "server.h"

#include <assert.h>
#include <arpa/inet.h>
#include <errno.h>
#include <netinet/ip.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include "common/common.h"

namespace dyr {

    const std::string Server::TYPE = "SERVER";
    const std::string Server::NAME = "DY_REDIS_SERVER";

    Server::Server() = default;

    const std::string &Server::getName() { return NAME; }

    const std::string &Server::getType() { return TYPE; }

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
        addr.sin_port = htons(1234); // Host to Network Short,  “Host” means the CPU endian. “Network” means big-endian. 
        addr.sin_addr.s_addr = htonl(0);  // Host to Network Long, wildcard address 0.0.0.0
        int rv = bind(fd, (const sockaddr *)&addr, sizeof(addr)); // struct sockaddr_in and struct sockaddr_in6 have different sizes, so the struct size (addrlen) is needed.
        if (rv) {
            die("bind()");
        }

        // listen
        rv = listen(fd, SOMAXCONN); // the size of the queue. SOMAXCONN is 4096 on Linux. 
        // The socket is actually created after listen(). The OS will automatically handle TCP handshakes and place established connections in a queue. The application can then retrieve them via accept().
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
