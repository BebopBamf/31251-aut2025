#include <iostream>

void memory_leak() {
	// example memory leak
	for (;;) {
		int* arr = new int[1024];
		for (std::size_t i = 0; i < 1024; i++) {
			arr[i] = i * 5;
		}
		std::cout << std::endl;
	}
}

void dangling_pointer() {
	// example dangling pointer
	int* arr = new int[5];
	delete[] arr;

	arr[3] = 10;
}

void dangling_pointer_null() {
	// example dangling pointer
	int* arr = new int[5];
	delete[] arr;
	arr = nullptr;

	arr[3] = 10;
}

int main() {
	// dangling_pointer();
	// dangling_pointer_null();
	memory_leak();
}
