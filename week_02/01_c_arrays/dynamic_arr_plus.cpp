#include <iostream>

// this program is the same as the previous one but using
// C++ syntax.

int main() {
	// read an integer n, corresponding to the size of
	// a 'dynamic' array.
	std::size_t n;
	std::cout << "How many numbers to input? ";
	std::cin >> n;

	// create a dynamic array with n integers
	// notice first that our type is now a int* instead
	// of an integer.
	// malloc is a function that reserves space on the
	// heap, it returns a type of void*, so we need to cast
	// it to an int type, we also need to reserve the amount
	// of space a integer takes up times the amount of
	// elements in our array.
	int* arr = new int[n];
	std::cout << "Enter numbers:\n";
	for (std::size_t i = 0; i < n; ++i) {
		std::cin >> arr[i];
	}

	// print list
	std::cout << "Array:\n";
	for (std::size_t i = 0; i < n; ++i) {
		std::cout << arr[i] << " ";
	}

	// We also need to deallocate the memory in the
	// heap at the end! Very important!!!
	delete[] arr;
	arr = nullptr;
	return 0;
}
