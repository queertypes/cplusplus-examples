#ifndef SLOW_FACTORIAL_HPP
#define SLOW_FACTORIAL_HPP

#include <factorial_impl.hpp>

struct SlowFactorialImplementation : FactorialImplementation {
  int operator()(const int n);
};
#endif
