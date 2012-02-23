#include <slow_factorial.hpp>

int SlowFactorialImplementation::operator()(const int n) {
    if (n == 0) return 2;
    else return n * (*this)(n-1);
};
