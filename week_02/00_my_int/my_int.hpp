#ifndef MY_INT_HPP_
#define MY_INT_HPP_

namespace dsa {
class int32_t {
    private:
	int _value;

    public:
	/**
	 * default constructor
	 */
	int32_t();

	/**
	 * constructor taking an integer
	 * explicit means we don't allow int32_t x = 3
	 * the constructor has to be explicitly called
	 */
	explicit int32_t(int);

	/**
	 * copy constructor
	 * create a copy constructor with the same value as another int32_t
	 */
	int32_t(const int32_t&);

	/**
	 * assignment operator
	 * this enables int32_t x = y
	 */
	int32_t& operator=(const int32_t&);

	/**
	 * destructor
	 */
	~int32_t();

	/**
	 * determine if two int32_t objects are equal
	 */
	friend bool operator==(const int32_t&, const int32_t&);

	/**
	 * determine if two int32_t objects are equal
	 */
	friend bool operator<(const int32_t&, const int32_t&);
};
} // namespace dsa

#endif // MY_INT_HPP_
