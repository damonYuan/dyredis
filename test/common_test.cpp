#include "common.h"

#include <gtest/gtest.h>

#include <iostream>

// Demonstrate some basic assertions.
TEST(CommonTest, BasicAssertions) {
    // Expect two strings not to be equal.
    EXPECT_STRNE("hello", "world");
}