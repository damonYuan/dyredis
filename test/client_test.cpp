#include "client.h"

#include <gtest/gtest.h>

#include <iostream>

// Demonstrate some basic assertions.
TEST(ClientTest, BasicAssertions) {
    // Expect two strings not to be equal.
    dyr::Client client{};
    std::string actual = client.getName();
    std::string expected = "DY_REDIS_CLIENT";
    ASSERT_STREQ(expected.c_str(), actual.c_str());
    ASSERT_TRUE(expected == actual);
}