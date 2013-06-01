#include <iostream>
using namespace std;

namespace c11 {

  // old version
  namespace v01 {
    int f(int x) { return x + 1; }
  }

  // default version
  inline namespace v02 {
    int f(int x) { return x + 2; }
  }

}

int main()
{
  cout << c11::f(1) << endl;
  cout << c11::v01::f(1) << endl;
  cout << c11::v02::f(1) << endl;

  return 0;
}
