#ifndef MY_INT_HPP_
#define MY_INT_HPP_

namespace dsa {
  class int32_t {
  private:
    int value;

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
     *
     */

  };
}


#endif // MY_INT_HPP_
