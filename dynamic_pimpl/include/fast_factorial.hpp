#ifndef FAST_FACTORIAL_HPP
#define FAST_FACTORIAL_HPP

#include <factorial_impl.hpp>

struct FastFactorialImplementation : FactorialImplementation {
  int operator()(const int n);
};
#endif
