#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(MyHelloTest, BasicStringAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
}
