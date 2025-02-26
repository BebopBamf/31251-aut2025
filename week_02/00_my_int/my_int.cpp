#include "my_int.hpp"

namespace dsa {
int32_t::int32_t() : value(0) {}

int32_t::int32_t(int value) : value(value) {}

int32_t::int32_t(const int32_t& other) : value(other.value) {}

int32_t& int32_t::operator=(const int32_t& other) {
	value = other.value;
	return *this;
}

int32_t::~int32_t() {}

bool operator==(const int32_t& lhs, const int32_t& rhs) {
	return lhs.value == rhs.value;
}

bool operator<(const int32_t& lhs, const int32_t& rhs) {
	return lhs.value < rhs.value;
}
} // namespace dsa
