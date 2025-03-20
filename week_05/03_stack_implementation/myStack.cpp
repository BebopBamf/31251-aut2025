#include <vector>
#include <string>
#include "myStack.hpp"

// default constructor (nothing to do here)
template <typename T>
MyStack<T>::MyStack() {}

// add an element to the top of stack
template <typename T>
void MyStack<T>::push(T val) {
  data.push_back(val);
}

// remove an element from the top of stack
template <typename T>
void MyStack<T>::pop() {
  data.pop_back();
}

// get the element at the top of stack
template <typename T>
T& MyStack<T>::top() {
  return data.at(size() - 1);
}

// return number of elements in the stack
template <typename T>
int MyStack<T>::size() {
  return data.size();
}

// check if stack is empty
template <typename T>
bool MyStack<T>::empty() {
  return data.empty();
}

template class MyStack<int>;
template class MyStack<char>;
template class MyStack<std::string>;
