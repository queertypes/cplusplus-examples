#include <iostream>
using namespace std;

struct X {
  X() = default;

  explicit X(const float a)
  {
    cout << "1 arg ctor\n";
    X(a, 0.0f, 0.0f);
  }

  X(const float a, const float b)
  {
    cout << "2 arg ctor\n";
    X(a,b,0.0f);
  }

  X(const float a,
    const float b,
    const float c) : x(a), y(b), z(c)
  {
    cout << "3 arg ctor\n";
  }

  float x, y, z;
};

int main()
{
  X x3{1.1, 2.2, 3.3};
  X x2{1.1, 2.2};
  X x1{1.1};

  return 0;
}
