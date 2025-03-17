#include "my_vector.hpp"
#include <gtest/gtest.h>
#include <initializer_list>

TEST(Vector, defaultConstructSizeZero) {
	dsa::vector vec{};
	EXPECT_EQ(vec.size(), 0u);
}

TEST(Vector, constructZeroVector) {
	std::size_t n = 3;
	dsa::vector vec(n);
	EXPECT_EQ(vec.size(), n);
	for (std::size_t i = 0; i < n; ++i) {
		EXPECT_EQ(vec[i], 0);
	}
}

TEST(Vector, getAndSet) {
	int n = 3;
	dsa::vector vec(n);
	vec[1] = 2;
	EXPECT_EQ(vec[1], 2);
}

TEST(Vector, arrayDoubling) {
	dsa::vector vec(2);
	vec.push_back(3);
	EXPECT_EQ(vec[2], 3);
	EXPECT_EQ(vec.size(), 3u);
	EXPECT_EQ(vec.capacity(), 4u);
}
