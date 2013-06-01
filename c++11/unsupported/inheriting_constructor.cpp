#include <iostream>
using namespace std;

struct Base {
  Base() {
    cout << "Base\n";
  }

  void f(const char x) {
    cout << "Base::f()\n";
  }
};

struct Derived : Base {
  Derived() {
    cout << "Derived\n";
  }
  
  using Base::f;
  void f(const int x) {
    cout << "Derived::f\n";
  }
};

int main()
{
  Base b;
  Derived d;

  b.f(1);
  d.f(2);

  return 0;
}
