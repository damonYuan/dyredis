#include "server.h"

#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(ServerTest, BasicAssertions) {
    // Expect two strings not to be equal.
    EXPECT_STRNE("hello", "world");
}