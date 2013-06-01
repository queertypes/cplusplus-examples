#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
using namespace std;

namespace FO {
  struct DefaultSort {
    bool operator()(const int a, const int b) { return a < b;}
  };
  
  struct AbsSort {
    bool operator()(const int a, const int b) { return abs(a) < abs(b);}
  };

  struct IsEven {
    bool operator()(const int a) { return (a % 2) == 0;}
  };
  
  struct AddFive {
    void operator()(int& x) { x += 5; } 
  };
}

int main()
{
  vector<int> x{5, -3, 4, -1, 2};

  // unsorted
  copy(begin(x), end(x), ostream_iterator<int>(cout, ","));
  cout << endl;

  // sort by abs
  sort(begin(x), end(x), [](int a, int b) {return abs(a) < abs(b);});
  copy(begin(x), end(x), ostream_iterator<int>(cout, ","));
  cout << endl;

  // default sort, lambda-style
  sort(begin(x), end(x), [](int a, int b) {return a < b;});
  copy(begin(x), end(x), ostream_iterator<int>(cout, ","));
  cout << endl;

  // return number of even values
  cout << "Even elements: " 
       << count_if(begin(x), end(x), 
                   [] (int i) {return (i % 2) == 0;}) 
       << endl;

  // add 5 to each element
  for_each(begin(x), end(x), [](int &i) {i += 5;});
  copy(begin(x), end(x), ostream_iterator<int>(cout, ","));
  cout << endl;

  // now again, c++98 style
  cout << endl;
  x = {5, -3, 4, -1, 2}; // reset

  // sort by abs
  sort(begin(x), end(x), FO::AbsSort());
  copy(begin(x), end(x), ostream_iterator<int>(cout, ","));
  cout << endl;

  // default sort, lambda-style
  sort(begin(x), end(x), FO::DefaultSort());
  copy(begin(x), end(x), ostream_iterator<int>(cout, ","));
  cout << endl;

  // return number of even values
  cout << "Even elements: " 
       << count_if(begin(x), end(x), 
                   FO::IsEven())
       << endl; 

  // add 5 to each element
  for_each(begin(x), end(x), FO::AddFive());
  copy(begin(x), end(x), ostream_iterator<int>(cout, ","));
  cout << endl;

  return 0;
}
