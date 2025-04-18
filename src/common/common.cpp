#include "common.h"
#include <stdio.h>
#include <cassert>
#include <unistd.h>
#include <cerrno>
#include <stdlib.h>

namespace dyr {
    static int32_t read_full(int fd, char *buf, size_t n) {
        while (n > 0) {
            ssize_t rv = read(fd, buf, n);
            if (rv <= 0) {
                return -1;  // error, or unexpected EOF
            }
            assert((size_t)rv <= n);
            n -= (size_t)rv;
            buf += rv;
        }
        return 0;
    }
    
    static int32_t write_all(int fd, const char *buf, size_t n) {
        while (n > 0) {
            ssize_t rv = write(fd, buf, n);
            if (rv <= 0) {
                return -1;  // error
            }
            assert((size_t)rv <= n);
            n -= (size_t)rv;
            buf += rv;
        }
        return 0;
    }

    static void msg(const char *msg) {
        fprintf(stderr, "%s\n", msg);
    }

    static void die(const char *msg) {
        int err = errno;
        fprintf(stderr, "[%d] %s\n", err, msg);
        abort();
    }
    
    
}