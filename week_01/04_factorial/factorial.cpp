#include "factorial.hpp"

// definition of the factorial function
// fill this in to correctly return the
// factorial of the input and pass the test cases

// n!
// 0! = 1
// 1! = 1
// n! = n(n-1)!

int factorial(int n) {
    if (n < 2)
        return 1;

    return n * factorial(n - 1);
}
