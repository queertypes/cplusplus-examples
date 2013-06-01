#include <factorial.hpp>
#include <fast_factorial.hpp>
#include <slow_factorial.hpp>
#include <iostream>
using namespace std;

int main()
{
  Factorial<FastFactorialImplementation> fast_fac;
  Factorial<SlowFactorialImplementation> slow_fac;

  cout << fast_fac(10) << endl;
  cout << slow_fac(10) << endl;

  return 0;
}
