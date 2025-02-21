#include <iostream>

// Write a function with two ints as
// parameters that returns their sum

int main() {
    // Prompt the user to enter an integer.
    // Prompt the user to enter another integer.
    // Use your add function to sum the integers.
    // Print out the result!
    int n1, n2;
    std::cout << "Read Int: ";
    std::cin >> n1;
    std::cout << std::endl;

    std::cout << "Read Int: ";
    std::cin >> n2;
    std::cout << std::endl;

    std::cout << "RESULT: " << n1 + n2;
    return 0;
}
