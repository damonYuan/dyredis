#include <gtest/gtest.h>
#include <iostream>
#include "client.h"

// Demonstrate some basic assertions.
TEST(ClientTest, BasicAssertions) {
    // Expect two strings not to be equal.
//    dyr::Client client;
//    std::string name = client.getName();
//    std::cout << name << std::endl;
    EXPECT_STRNE("hello", "a");
}