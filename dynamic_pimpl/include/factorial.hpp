#ifndef FACTORIAL_HPP
#define FACTORIAL_HPP

#include <memory>
#include <factorial_impl.hpp>

enum class FImplType {
  FAST,
  SLOW
};

struct Factorial {
  Factorial(const FImplType i = FImplType::FAST);
  int operator()(const int n);

  std::unique_ptr<FactorialImplementation> _i;
};
#endif
