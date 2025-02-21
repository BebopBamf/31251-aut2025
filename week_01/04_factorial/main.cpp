// We will use the googletest library to
// write test cases to check your code.
// The next line includes this library
#include <gtest/gtest.h>
// in order to use the factorial function
// we need to include the header file with
// its declaration.  Local files are included
// using double quotes instead of the angle brackets.
#include "factorial.hpp"

// The syntax for googletest is pretty easy.
// TEST has two parameters: the first is the
// name of the test "family".  We can group
// tests together that test similar things.
// Here we put all tests into the same family.
// The second is the name of the individual test.
// It should be descriptive of what is being tested.
// Each test needs a unique individual name.

// We include all the tests that will be checked
// when you press "Mark".
TEST(factorialTest, factorialOf0is1) {
  EXPECT_EQ(factorial(0), 1);
}

TEST(factorialTest, factorialOf1is1) {
  EXPECT_EQ(factorial(1), 1);
}

TEST(factorialTest, factorialOf2is2) {
  EXPECT_EQ(factorial(2), 2);
}

TEST(factorialTest, factorialOf3is6) {
  EXPECT_EQ(factorial(3), 6);
}

TEST(factorialTest, factorialOf4is24) {
  EXPECT_EQ(factorial(4), 24);
}

TEST(factorialTest, factorialOf5is120) {
  EXPECT_EQ(factorial(5), 120);
}

TEST(factorialTest, factorialOf6is720) {
  EXPECT_EQ(factorial(6), 720);
}

TEST(factorialTest, factorialOf7is5040) {
  EXPECT_EQ(factorial(7), 5040);
}

// Try to add your own test here!

int main(int argc, char* argv[]) {
    // the next line is necessary to initialise googletest
    ::testing::InitGoogleTest(&argc, argv);

    /***
    you can add things to main if you want
    ***/

    // the next line runs all the tests given above.
    // you can comment this line out if you don't want
    // to do something else and not run the tests
    return RUN_ALL_TESTS();
}

