#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include "rpn.hpp"

TEST(EvaluatePostfix, returnZeroOnEmptyString) {
  std::vector<Token> empty {};
  EXPECT_EQ(evalRPN(empty), 0);
}

TEST(EvaluatePostfix, addTwoNumbers) {
  std::vector<Token> add {{'n', 2}, {'n', 3}, {'+', 0}};
  EXPECT_EQ(evalRPN(add), 5);
}

TEST(EvaluatePostfix, subtractTwoNumbers) {
  std::vector<Token> tokens {{'n', 3}, {'n', 5}, {'-', 0}};
  EXPECT_EQ(evalRPN(tokens), -2);
}

TEST(EvaluatePostfix, multiplyTwoNumbers) {
  std::vector<Token> times {{'n', 2}, {'n', 3}, {'*', 0}};
  EXPECT_EQ(evalRPN(times), 6);
}

TEST(EvaluatePostfix, compoundTest) {
  std::vector<Token> compound {{'n', 2}, {'n', 3}, {'+', 0}, {'n', 3}, {'*', 0}};
  EXPECT_EQ(evalRPN(compound), 15);
}

TEST(EvaluatePostfix, infixRequiresParentheses) {
  std::vector<Token> tokens {{'n', 2}, {'n', 4}, {'n', 8}, {'+', 0}, {'*', 0}};
  EXPECT_EQ(evalRPN(tokens), 24);
}

TEST(EvaluatePostfix, withDiv) {
  std::vector<Token> tokens {{'n', 4}, {'n', 3}, {'n', 5}, {'/', 0}, {'+', 0}};
  EXPECT_EQ(evalRPN(tokens), 4);
}

TEST(EvaluatePostfix, longerExpression1) {
  std::vector<Token> tokens
    {{'n', 2}, {'n', 5}, {'*', 0}, {'n', 4}, {'+', 0}, {'n', 3}, {'n', 2}, {'*', 0}, {'n', 1}, {'+', 0}, {'/', 0}};
  EXPECT_EQ(evalRPN(tokens), 2);
}

TEST(EvaluatePostfix, longerExpression2) {
  std::vector<Token> tokens
    {{'n', 8}, {'n', 6}, {'n', 4}, {'n', 3}, {'-', 0}, {'n', 3}, {'*', 0}, {'/', 0}, {'*', 0}, {'n', 7}, {'+', 0}, {'n', 5}, {'+', 0}};
  EXPECT_EQ(evalRPN(tokens), 28);
}

TEST(EvaluatePostfix, ex1) {
  std::vector<Token> postfixVector = {{'n', 3}, {'n', 63}, {'n', 52}, {'+', 0}, {'+', 0}};
  int solution = 118;
  EXPECT_EQ(evalRPN(postfixVector), solution);
}

TEST(EvaluatePostfix, ex2) {
  std::vector<Token> postfixVector = {{'n', 20}, {'n', 86}, {'n', 84}, {'-', 0}, {'/', 0}};
  int solution = 10;
  EXPECT_EQ(evalRPN(postfixVector), solution);
}

TEST(EvaluatePostfix, ex3) {
  std::vector<Token> postfixVector = {{'n', 62}, {'n', 55}, {'+', 0}, {'n', 81}, {'/', 0}};
  int solution = 1;
  EXPECT_EQ(evalRPN(postfixVector), solution);
}

TEST(EvaluatePostfix, ex4) {
  std::vector<Token> postfixVector = {{'n', 25}, {'n', 80}, {'n', 87}, {'-', 0}, {'n', 88}, {'*', 0}, {'*', 0}, {'n', 100}, {'-', 0}};
  int solution = -15500;
  EXPECT_EQ(evalRPN(postfixVector), solution);
}

TEST(EvaluatePostfix, ex5) {
  std::vector<Token> postfixVector = {{'n', 68}, {'n', 6}, {'*', 0}, {'n', 80}, {'/', 0}, {'n', 44}, {'n', 79}, {'n', 64}, {'+', 0}, {'+', 0}, {'n', 27}, {'+', 0}, {'/', 0}};
  int solution = 0;
  EXPECT_EQ(evalRPN(postfixVector), solution);
}

TEST(EvaluatePostfix, ex6) {
  std::vector<Token> postfixVector = {{'n', 46}, {'n', 84}, {'*', 0}, {'n', 20}, {'n', 56}, {'*', 0}, {'/', 0}};
  int solution = 3;
  EXPECT_EQ(evalRPN(postfixVector), solution);
}

TEST(EvaluatePostfix, ex7) {
  std::vector<Token> postfixVector = {{'n', 67}, {'n', 10}, {'n', 69}, {'n', 84}, {'n', 76}, {'n', 70}, {'*', 0}, {'-', 0}, {'+', 0}, {'-', 0}, {'/', 0}};
  int solution = 0;
  EXPECT_EQ(evalRPN(postfixVector), solution);
}

TEST(EvaluatePostfix, ex8) {
  std::vector<Token> postfixVector = {{'n', -5}, {'n', -17}, {'n', 14}, {'-', 0}, {'n', -2}, {'n', -13}, {'*', 0}, {'-', 0}, {'*', 0}};
  int solution = 285;
  EXPECT_EQ(evalRPN(postfixVector), solution);
}

TEST(EvaluatePostfix, ex9) {
  std::vector<Token> postfixVector = {{'n', -16}, {'n', 14}, {'/', 0}, {'n', -20}, {'+', 0}};
  int solution = -21;
  EXPECT_EQ(evalRPN(postfixVector), solution);
}

TEST(EvaluatePostfix, ex10) {
  std::vector<Token> postfixVector = {{'n', 13}, {'n', 2}, {'+', 0}, {'n', -9}, {'n', 11}, {'-', 0}, {'-', 0}, {'n', -5}, {'n', -6}, {'+', 0}, {'-', 0}};
  int solution = 46;
  EXPECT_EQ(evalRPN(postfixVector), solution);
}

TEST(EvaluatePostfix, ex11) {
  std::vector<Token> postfixVector = {{'n', 2}, {'n', 17}, {'+', 0}, {'n', 19}, {'+', 0}};
  int solution = 38;
  EXPECT_EQ(evalRPN(postfixVector), solution);
}

TEST(EvaluatePostfix, ex12) {
  std::vector<Token> postfixVector = {{'n', 16}, {'n', -20}, {'n', -11}, {'*', 0}, {'/', 0}};
  int solution = 0;
  EXPECT_EQ(evalRPN(postfixVector), solution);
}

TEST(EvaluatePostfix, ex13) {
  std::vector<Token> postfixVector = {{'n', -8}, {'n', 13}, {'n', -6}, {'*', 0}, {'*', 0}};
  int solution = 624;
  EXPECT_EQ(evalRPN(postfixVector), solution);
}

TEST(EvaluatePostfix, ex14) {
  std::vector<Token> postfixVector = {{'n', 16}, {'n', -19}, {'n', -9}, {'n', 3}, {'n', 1}, {'/', 0}, {'/', 0}, {'n', 7}, {'+', 0}, {'-', 0}, {'n', -7}, {'n', 17}, {'+', 0}, {'+', 0}, {'n', 16}, {'+', 0}, {'-', 0}, {'n', -14}, {'/', 0}};
  int solution = 0;
  EXPECT_EQ(evalRPN(postfixVector), solution);
}

TEST(EvaluatePostfix, ex15) {
  std::vector<Token> postfixVector = {{'n', -16}, {'n', -16}, {'n', -12}, {'*', 0}, {'*', 0}};
  int solution = -3072;
  EXPECT_EQ(evalRPN(postfixVector), solution);
}

TEST(EvaluatePostfix, ex16) {
  std::vector<Token> postfixVector = {{'n', -12}, {'n', -5}, {'-', 0}, {'n', 3}, {'*', 0}};
  int solution = -21;
  EXPECT_EQ(evalRPN(postfixVector), solution);
}

TEST(EvaluatePostfix, ex17) {
  std::vector<Token> postfixVector = {{'n', -8}, {'n', 20}, {'n', 11}, {'+', 0}, {'n', 0}, {'n', 11}, {'/', 0}, {'n', 5}, {'/', 0}, {'n', -13}, {'-', 0}, {'n', 8}, {'+', 0}, {'*', 0}, {'-', 0}};
  int solution = -659;
  EXPECT_EQ(evalRPN(postfixVector), solution);
}

TEST(EvaluatePostfix, ex18) {
  std::vector<Token> postfixVector = {{'n', -14}, {'n', -14}, {'-', 0}};
  int solution = 0;
  EXPECT_EQ(evalRPN(postfixVector), solution);
}

TEST(EvaluatePostfix, ex19) {
  std::vector<Token> postfixVector = {{'n', -12}, {'n', 11}, {'/', 0}};
  int solution = -1;
  EXPECT_EQ(evalRPN(postfixVector), solution);
}

TEST(EvaluatePostfix, ex20) {
  std::vector<Token> postfixVector = {{'n', 2}, {'n', 20}, {'n', 6}, {'n', -8}, {'-', 0}, {'n', -3}, {'n', 14}, {'n', 14}, {'n', 4}, {'*', 0}, {'n', 8}, {'n', 1}, {'/', 0}, {'n', 7}, {'*', 0}, {'n', -19}, {'n', -10}, {'+', 0}, {'n', 9}, {'/', 0}, {'+', 0}, {'n', 6}, {'*', 0}, {'n', -18}, {'/', 0}, {'n', 0}, {'n', 20}, {'+', 0}, {'/', 0}, {'n', 2}, {'/', 0}, {'-', 0}, {'-', 0}, {'n', -3}, {'+', 0}, {'/', 0}, {'n', -6}, {'+', 0}, {'n', -13}, {'+', 0}, {'-', 0}, {'+', 0}, {'n', -11}, {'*', 0}, {'n', -20}, {'-', 0}, {'+', 0}};
  int solution = -561;
  EXPECT_EQ(evalRPN(postfixVector), solution);
}

TEST(EvaluatePostfix, ex21) {
  std::vector<Token> postfixVector = {{'n', -18}, {'n', 20}, {'n', 20}, {'+', 0}, {'n', -14}, {'n', -9}, {'*', 0}, {'-', 0}, {'-', 0}};
  int solution = 68;
  EXPECT_EQ(evalRPN(postfixVector), solution);
}

TEST(EvaluatePostfix, ex22) {
  std::vector<Token> postfixVector = {{'n', 3}, {'n', -9}, {'*', 0}};
  int solution = -27;
  EXPECT_EQ(evalRPN(postfixVector), solution);
}

TEST(EvaluatePostfix, ex23) {
  std::vector<Token> postfixVector = {{'n', -12}, {'n', -10}, {'/', 0}, {'n', -2}, {'n', 18}, {'-', 0}, {'-', 0}, {'n', -8}, {'*', 0}};
  int solution = -168;
  EXPECT_EQ(evalRPN(postfixVector), solution);
}

TEST(EvaluatePostfix, ex24) {
  std::vector<Token> postfixVector = {{'n', 18}, {'n', -2}, {'n', 5}, {'n', 11}, {'-', 0}, {'/', 0}, {'-', 0}};
  int solution = 18;
  EXPECT_EQ(evalRPN(postfixVector), solution);
}

TEST(EvaluatePostfix, ex25) {
  std::vector<Token> postfixVector = {{'n', 18}, {'n', 9}, {'n', 10}, {'+', 0}, {'*', 0}, {'n', 20}, {'-', 0}, {'n', -13}, {'+', 0}, {'n', 17}, {'/', 0}};
  int solution = 18;
  EXPECT_EQ(evalRPN(postfixVector), solution);
}

TEST(EvaluatePostfix, ex26) {
  std::vector<Token> postfixVector = {{'n', -4}, {'n', -12}, {'n', -19}, {'-', 0}, {'/', 0}};
  int solution = 0;
  EXPECT_EQ(evalRPN(postfixVector), solution);
}

TEST(EvaluatePostfix, ex27) {
  std::vector<Token> postfixVector = {{'n', 4}, {'n', -5}, {'n', -9}, {'/', 0}, {'n', 11}, {'n', 9}, {'/', 0}, {'-', 0}, {'/', 0}};
  int solution = -4;
  EXPECT_EQ(evalRPN(postfixVector), solution);
}

TEST(EvaluatePostfix, ex28) {
  std::vector<Token> postfixVector = {{'n', -10}, {'n', -16}, {'n', -13}, {'*', 0}, {'*', 0}, {'n', -20}, {'n', 20}, {'n', 20}, {'-', 0}, {'n', 20}, {'n', 14}, {'-', 0}, {'n', 18}, {'-', 0}, {'+', 0}, {'/', 0}, {'n', -5}, {'n', 12}, {'*', 0}, {'/', 0}, {'n', 6}, {'n', -15}, {'*', 0}, {'n', 2}, {'*', 0}, {'*', 0}, {'+', 0}, {'n', -7}, {'n', -8}, {'*', 0}, {'-', 0}};
  int solution = -2136;
  EXPECT_EQ(evalRPN(postfixVector), solution);
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
