#include "my_vector.hpp"

namespace dsa {
vector::vector() : m_size(0), m_capacity(0), m_arr_ptr(nullptr) {}

vector::vector(const std::size_t& n)
	: m_size(n), m_capacity(n), m_arr_ptr(new int[n]) {
	for (std::size_t i = 0; i < m_size; i++) {
		m_arr_ptr[i] = 0;
	}
}

vector::vector(const std::initializer_list<int>& vals)
	: m_size(vals.size()), m_capacity(vals.size()),
	  m_arr_ptr(new int[vals.size()]) {
	std::size_t i = 0;
	for (const int& n : vals) {
		m_arr_ptr[i++] = n;
	}
}

vector::~vector() {
	delete[] m_arr_ptr;
	m_arr_ptr = nullptr;
}

void vector::push_back(const int& val) {
	if (m_size >= m_capacity) {
		m_capacity *= 2;
		int* temp = new int[m_capacity];
		for (std::size_t i = 0; i < m_size; i++) {
			temp[i] = m_arr_ptr[i];
		}
		delete[] m_arr_ptr;
		m_arr_ptr = temp;
	}

	++m_size;
	m_arr_ptr[m_size - 1] = val;
}

void vector::pop_back() { --m_size; }

int vector::back() { return m_arr_ptr[m_size - 1]; }

std::size_t vector::size() const { return m_size; }

std::size_t vector::capacity() const { return m_capacity; }

int& vector::operator[](const std::size_t& idx) {
	if (idx >= m_size) {
		throw std::out_of_range("Index out of bounds.");
	}
	return m_arr_ptr[idx];
}
} // namespace dsa
