#include <iostream>
using namespace std;

template <class T, bool InPlace = false>
struct F {
  T operator()(const T& x) {
    T xx = x;
    ++xx;
    return xx;
  }
};

template <class T>
struct F<T, true> {
  void operator()(T& x) {
    ++x;
    return x;
  }
};

int main()
{
  int a = 1, b = 1;
  F<int> f;
  F<int, false> f_inplace;

  int c = f(a);
  f_inplace(b);

  cout << a << " " << b << " " << c << "\n";

  return 0;
}
