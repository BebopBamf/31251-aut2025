#include "array_product.hpp"
#include <functional>
#include <gtest/gtest.h>
#include <numeric>

TEST(ProductTest, vectorOfSizeTwo) {
	std::vector<int> vec{1, 2};
	std::vector<int> result{2, 1};
	EXPECT_EQ(product_except_self(vec), result);
}

TEST(ProductTest, vectorOfSizeThree) {
	std::vector<int> vec{1, 2, 3};
	std::vector<int> result{6, 3, 2};
	EXPECT_EQ(product_except_self(vec), result);
}

TEST(ProductTest, vectorOfSizeFour) {
	std::vector<int> vec{1, 2, 3, 4};
	std::vector<int> result{24, 12, 8, 6};
	EXPECT_EQ(product_except_self(vec), result);
}

TEST(ProductTest, allZerosSize2) {
	std::vector<int> vec{0, 0};
	std::vector<int> result{0, 0};
	EXPECT_EQ(product_except_self(vec), result);
}

TEST(ProductTest, oneZero) {
	std::vector<int> vec{1, 2, 0, 3, 4};
	std::vector<int> result(vec.size());
	result[2] = 24;
	EXPECT_EQ(product_except_self(vec), result);
}

TEST(ProductTest, twoZeros) {
	std::vector<int> vec{1, 2, 0, 3, 0, 4};
	std::vector<int> result(vec.size());
	EXPECT_EQ(product_except_self(vec), result);
}

TEST(ProductTest, allZerosSize6) {
	std::vector<int> vec(6);
	std::vector<int> result(vec.size());
	EXPECT_EQ(product_except_self(vec), result);
}

TEST(ProductTest, zeroComesAtEnd) {
	std::vector<int> vec{1, 2, 7, 3, 4, 0};
	std::vector<int> result(vec.size());
	result[5] = std::accumulate(vec.cbegin(), vec.cend() - 1, 1,
				    std::multiplies<int>());
	EXPECT_EQ(product_except_self(vec), result);
}
