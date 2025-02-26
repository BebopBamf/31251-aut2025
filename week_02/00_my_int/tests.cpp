#include "my_int.hpp"
#include <gtest/gtest.h>

TEST(myInt, equalityWhenTrue) {
	dsa::int32_t a{3};
	dsa::int32_t b{3};
	EXPECT_TRUE(a == b);
}

TEST(myInt, equalityWhenFalse) {
	dsa::int32_t a{3};
	dsa::int32_t b{5};
	EXPECT_FALSE(a == b);
}

TEST(myInt, equalityWithAssignment) {
	dsa::int32_t a{3};
	dsa::int32_t b{5};
	a = b;
	EXPECT_TRUE(a == b);
}

TEST(myInt, lessThanTrueWhenSmaller) {
	dsa::int32_t a{3};
	dsa::int32_t b{5};
	EXPECT_TRUE(a < b);
}

TEST(myInt, lessThanFalseWhenBigger) {
	dsa::int32_t a{5};
	dsa::int32_t b{3};
	EXPECT_FALSE(a < b);
}
