#include <vector>
#include <iostream>
using namespace std;

// compile-time factorial
template <size_t N>
struct Factorial {
  static const size_t val = N * Factorial<N-1>::val;
};

template <>
struct Factorial<0> {
  static const size_t val = 1;
};

int main() {  
  // vector initialization using initializer lists
  vector<int> v = {Factorial<5>::val, 
                   Factorial<7>::val, 
                   Factorial<8>::val, 
                   Factorial<3>::val, 
                   Factorial<4>::val};

  // old-style iterator use
  cout << "[";
  for (vector<int>::const_iterator iter = v.begin(),
         iend = v.end(); iter != iend; ++iter)
    cout << *iter << " ";
  cout << "]\n";
    
  // simplified new-style using type inference and
  // free functions begin() and end()
  cout << "[";
  for (auto iter = begin(v), iend = end(v); iter != iend; ++iter)
    cout << *iter << " ";
  cout << "]\n";

  // using range-for with auto
  cout << "[";
  for (const auto elem : v)
    cout << elem << " ";
  cout << "]\n";

  return 0;
}  
