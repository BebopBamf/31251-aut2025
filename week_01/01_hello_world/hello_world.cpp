// We include the iostream library.
// This library contains the declaration of
// the cout object.
#include <iostream>

int main() {
    // Standard library objects are put in a "namespace" called std.
    // This is to avoid name collisions with names we define.
    // To refer to objects in the std namespace we use the scope resolution
    // operator ::, as in std::cout
    std::cout << "Hello World\n";
    return 0;
}
