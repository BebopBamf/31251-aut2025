#ifndef MY_VECTOR_HPP
#define MY_VECTOR_HPP

#include <initializer_list>
#include <stdexcept>

namespace dsa {
class vector {
private:
	std::size_t m_size;
	std::size_t m_capacity;
	int* m_arr_ptr;

public:
	/**
	 * default constructor
	 */
	vector();

	/**
	 * Construct a vector of size n where all entries are 0
	 */
	explicit vector(const std::size_t& n);

	/**
	 * Construct a vector from an initializer list
	 */
	vector(const std::initializer_list<int>& vals);

	/**
	 * Destructor
	 */
	~vector();

	/**
	 * vector push_back function
	 */
	void push_back(const int&);
	void pop_back();
	int back();

	bool empty();

	std::size_t size() const;
	std::size_t capacity() const;
	int& operator[](const std::size_t&);
};
} // namespace dsa

#endif // MY_VECTOR_HPP
