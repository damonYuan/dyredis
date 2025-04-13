#pragma once
#include <stdio.h>
#include <cstdint>

namespace dyr {
    static const size_t k_max_msg = 4096;

    static int32_t read_full(int fd, char *buf, size_t n);
    static int32_t write_all(int fd, const char *buf, size_t n);
    static void msg(const char *msg);
    static void die(const char *msg);
}