#include <iostream>
#include <vector>
using namespace std;

// Allow exceptions here if vector::operator[] is also noexcept
void check(const vector<int>& v) noexcept(noexcept(v[0]))
{
  if (v[0]) {
    cout << "Pass\n";
  }
}

// Allow exceptions here if vector::push_back(T) is also noexcept
void add(vector<int>& v, const int elem) noexcept(noexcept(v.push_back(elem)))
{
  v.push_back(elem);
}

// Do not allow exceptions here, at all
void greet() noexcept
{
  cout << "Hi!\n";
}

int main()
{
  vector<int> v{1,2,3};

  greet();
  check(v);
  add(v,4);

  return 0;
}
