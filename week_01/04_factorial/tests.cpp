#include <gtest/gtest.h>
#include "factorial.hpp"

TEST(factorialTest, tautology) {
  EXPECT_EQ(factorial(3), 6);
}
