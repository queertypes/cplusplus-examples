#include <factorial.hpp>
#include <iostream>
using namespace std;

int main()
{
  Factorial fast_fac{FImplType::FAST};
  Factorial slow_fac{FImplType::SLOW};

  cout << fast_fac(10) << endl;
  cout << slow_fac(10) << endl;

  return 0;
}
