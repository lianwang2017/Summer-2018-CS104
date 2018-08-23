#include "stackint.h"
#include <iostream>
#include <cstdlib>
#include <stdexcept>

 StackInt::StackInt()
 {}

 StackInt::~StackInt()
 {}

 /**
  * Returns true if the stack is empty, false otherwise
  */
 bool StackInt::empty() const
 {
     return list_.empty();
 }

 /**
  * Pushes a new value, val, onto the top of the stack
  */
 void StackInt::push(const int& val)
 {
     list_.insert(0, val);
 }

 /**
  * Returns the top value on the stack
  */
 int const &  StackInt::top() const
 {
     list_.get(0);
 }

 /**
  * Removes the top element on the stack
  */
 void StackInt::pop()
 {
     list_.remove(0);
 }