#include <iostream>
#include <vector>

int main() {
	std::vector<int> vec = {1, 2, 3, 4, 5};

	// Print array with regular for loop
	// Notice we use the type std::size_t instead of
	// int
	std::cout << "Normal for loop\n";
	for (std::size_t i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << " ";
	}
	std::cout << "\n\n";

	// Print array with range based for loop
	std::cout << "Range based for loop\n";
	for (const int& data : vec) {
		std::cout << data << " ";
	}
	std::cout << "\n\n";

	// Print array with iterators
	std::cout << "Iterators method\n";
	for (auto it = vec.begin(); it < vec.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << "\n\n";

	auto it = vec.begin();

	// size and capacity
	std::cout << "Original size and capacity\n";
	std::cout << "it*: " << *it << "\n";
	std::cout << "Size: " << vec.size() << "\n";
	std::cout << "Capacity: " << vec.capacity() << "\n\n";

	// size and capacity after push
	vec.push_back(6);
	std::cout << "Size and capacity after push\n";
	std::cout << "it*: " << *it << "\n";
	std::cout << "Size: " << vec.size() << "\n";
	std::cout << "Capacity: " << vec.capacity() << "\n\n";

	std::vector<int> empty;
	std::cout << "Empty size and capacity\n";
	std::cout << "Size: " << empty.size() << "\n";
	std::cout << "Capacity: " << empty.capacity() << "\n\n";

	empty.pop_back();
	std::cout << "Empty size and capacity after pop_back\n";
	std::cout << "Size: " << empty.size() << "\n";
	std::cout << "Capacity: " << empty.capacity() << "\n\n";

	// Vector out of bounds demo
	std::cout << "Vector out of bounds (10) index\n";
	std::cout << "vec[10]: " << vec[10] << "\n";
	std::cout << "vec.at(10): " << vec.at(10) << "\n";
	std::cout << "empty[empty.size() - 1]: " << empty[empty.size() - 1];

	return 0;
}
