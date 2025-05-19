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
#include <stdio.h>
#include <cstdint>
#include <vector>

namespace dyr {
    static const size_t k_max_msg = 32 << 20;
    static const size_t k_max_args = 200 * 1000;

    int32_t read_full(int fd, char *buf, size_t n);
    int32_t write_all(int fd, const char *buf, size_t n);
    void msg(const char *msg);
    void msg_errno(const char *msg);
    void die(const char *msg);
    void buf_append(std::vector<uint8_t> &buf, const uint8_t *data, size_t len);
}