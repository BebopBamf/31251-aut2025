#include <iostream>

// here is an example of a dynamic array
int main() {
	// sizes of array needs to be known at compile time
	int arr[2] = {1, 2};

	std::cout << "Number 1: " << arr[0] << std::endl;
	std::cout << "Number 2: " << arr[1] << std::endl;

	// can change array contents
	arr[1] = 30;
	std::cout << "Number 1: " << arr[0] << std::endl;
	std::cout << "Number 2: " << arr[1] << std::endl;

	// at the end of the scope, the array will safely be popped from the
	// stack
}
