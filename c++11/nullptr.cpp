#include <iostream>
using namespace std;

void f(void *x)
{
  if (x == nullptr) {
    cout << "error: null argument\n";
    return;
  }

  cout << "That's a good argument you make there...\n";
}

int main()
{
  int* p1 = nullptr;
  int* p2 = 0;
  int* x = new int;
  
  if (p1 == p2)
    cout << "nullptr is equivalent to 0\n";

  if (p1 == p1)
    cout << "nullptr is equivalent to nullptr\n";
  
  f(nullptr);
  f(0);
  f(x);
  
  delete x;

  return 0;
}
