#include "my_int.hpp"

namespace dsa {
int32_t::int32_t() : _value(0) {}

int32_t::int32_t(int value) : _value(value) {}

int32_t::int32_t(const int32_t& other) : _value(other._value) {}

int32_t& int32_t::operator=(const int32_t& other) {
	_value = other._value;
	return *this;
}

int32_t::~int32_t() {}

bool operator==(const int32_t& lhs, const int32_t& rhs) {
	return lhs._value == rhs._value;
}
} // namespace dsa
