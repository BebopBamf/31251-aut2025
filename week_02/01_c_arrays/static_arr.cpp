#include <iostream>

// here is an example of a dynamic array
int main() {
	// sizes of array needs to be known at compile time
	int arr[2] = {1, 2};

	std::cout << "Number 1: " << arr[0] << std::endl;
	std::cout << "Number 2: " << arr[1] << std::endl;

	// can change array contents
	std::cout << "Enter a number: ";
	std::cin >> arr[0];

	std::cout << "Enter another number: ";
	std::cin >> arr[1];

	std::cout << "Number 1: " << arr[0] << std::endl;
	std::cout << "Number 2: " << arr[1] << std::endl;

	std::cout << "Sum: " << arr[0] + arr[1] << std::endl;

	// Example where we find number at runtime
	// std::size_t n;
	// std::cout << "Enter array size: ";
	// std::cin >> n;

	// int dyn_arr[n];
	//  for (std::size_t i = 0; i < n; i++) {
	//  	dyn_arr[i] = i;
	//  	std::cout << dyn_arr[i] << " ";
	//  }
	//  std::cout << std::endl;

	// at the end of the scope, the array will safely be popped from the
	// stack
}
