#include "array_product.hpp"

std::vector<int> product_except_self(const std::vector<int>& vec) {
	// Naive Solution
	// std::vector<int> prodArr(vec.size(), 1);
	// for (std::size_t i = 0; i < vec.size(); i++) {
	// 	for (std::size_t j = 0; j < vec.size(); j++) {
	// 		prodArr.at(i) *= i == j ? 1 : vec.at(j);
	// 	}
	// }

	// Left-Right Products Example
	// std::vector<int> prodArr(vec.size()), leftProd(vec.size(), 1),
	// 	rightProd(vec.size(), 1);
	// for (std::size_t i = 1; i < vec.size(); i++) {
	// 	leftProd.at(i) = leftProd.at(i - 1) * vec.at(i - 1);
	// 	rightProd.at(i) = rightProd.at(i - 1) * vec.at(vec.size() - i);
	// }

	// for (std::size_t i = 0; i < vec.size(); i++) {
	// 	prodArr.at(i) =
	// 		leftProd.at(i) * rightProd.at(vec.size() - i - 1);
	// }

	// Fast Solution
	int prod = 1;
	bool hasZero = false;
	for (const int& n : vec) {
		if (n == 0) {
			if (hasZero == true) {
				return std::vector<int>(vec.size());
			}
			hasZero = true;
		} else {
			prod *= n;
		}
	}

	std::vector<int> prodArr(vec.size());
	for (std::size_t i = 0; i < vec.size(); i++) {
		if (hasZero) {
			if (vec.at(i) == 0)
				prodArr.at(i) = prod;
		} else {
			prodArr.at(i) = prod / vec.at(i);
		}
	}

	return prodArr;
}
