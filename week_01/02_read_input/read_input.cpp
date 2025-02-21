#include <iostream>

// this time we will also use the string library
#include <string>

int main() {
    // We initialise an empty string userInput
    // The string class is provided by the standard
    // library and is in the std namespace so we
    // again access it with std:: using the
    // scope resolution operator
    std::string userInput{};

    std::cout << "INPUT: ";
    std::cin >> userInput;

    std::cout << "OUTPUT: " << userInput << "\n";

    // use cin to read keyboard input into userInput
    /***
    your code here
    ***/
    // Now check it by printing out userInput
    return 0;
}
