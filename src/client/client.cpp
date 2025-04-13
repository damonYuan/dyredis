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
#include "common/common.h"

using namespace std;
namespace dyr {

    const std::string Client::TYPE = "CLIENT";
    const std::string Client::NAME = "DY_REDIS_CLIENT";

    Client::Client() = default;

    const string &Client::getName() { return NAME; }

    const string &Client::getType() { return TYPE; }

    int32_t Client::query(int fd, const char *text) {
        uint32_t len = (uint32_t)strlen(text);
        if (len > k_max_msg) {
            return -1;
        }
    
        char wbuf[4 + k_max_msg];
        memcpy(wbuf, &len, 4);  // assume little endian
        memcpy(&wbuf[4], text, len);
        if (int32_t err = write_all(fd, wbuf, 4 + len)) {
            return err;
        }
    
        // 4 bytes header
        char rbuf[4 + k_max_msg + 1];
        errno = 0;
        int32_t err = read_full(fd, rbuf, 4);
        if (err) {
            msg(errno == 0 ? "EOF" : "read() error");
            return err;
        }
    
        memcpy(&len, rbuf, 4);  // assume little endian
        if (len > k_max_msg) {
            msg("too long");
            return -1;
        }
    
        // reply body
        err = read_full(fd, &rbuf[4], len);
        if (err) {
            msg("read() error");
            return err;
        }
    
        // do something
        printf("server says: %.*s\n", len, &rbuf[4]);
        return 0;
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
