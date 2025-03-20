#ifndef STACK_HPP_
#define STACK_HPP_

#include <vector>

template <typename T>
class MyStack {
 private:
  std::vector<T> data {};

 public:
  // default constructor
  MyStack();

  // add an element to the top of stack
  void push(T val);

  // remove an element from the top of stack
  void pop();

  // get the element at the top of stack
  T& top();

  // return number of elements in the stack
  int size();

  // check if stack is empty
  bool empty();
};

#endif      // STACK_HPP_
