#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include "two_sum.hpp"

TEST(TwoSumTest, firstExample) {
  std::vector<int> vec {1, 2, 4, 8};
  int target {5};
  auto [a, b] = twoSum(vec, target); 
  EXPECT_EQ(std::min({a,b}), 0);
  EXPECT_EQ(std::max({a,b}), 2);
}

TEST(TwoSumTest, secondExample) {
  std::vector<int> vec {1, 3, 9, 27};
  int target {30};
  auto [a, b] = twoSum(vec, target); 
  EXPECT_EQ(std::min({a,b}), 1);
  EXPECT_EQ(std::max({a,b}), 3);
}

TEST(TwoSumTest, leetCodeExample1) {
  std::vector<int> vec {2, 7, 11, 15};
  int target {9};
  auto [a, b] = twoSum(vec, target); 
  EXPECT_EQ(std::min({a,b}), 0);
  EXPECT_EQ(std::max({a,b}), 1);
}

TEST(TwoSumTest, dontUseSameIndexTwice) {
  std::vector<int> vec {5, 5};
  int target {10};
  auto [a, b] = twoSum(vec, target); 
  EXPECT_EQ(std::min({a,b}), 0);
  EXPECT_EQ(std::max({a,b}), 1);
}

TEST(TwoSumTest, nearestExitMayBeBehindYou) {
  std::vector<int> vec {-1, 36, -10, 18};
  int target {26};
  auto [a, b] = twoSum(vec, target); 
  EXPECT_EQ(std::min({a,b}), 1);
  EXPECT_EQ(std::max({a,b}), 2);
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
