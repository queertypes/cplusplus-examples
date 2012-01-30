#include <vector>
#include <iostream>
using namespace std;

int main() {  
  vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  for(auto iter = begin(v), iend = end(v); iter != iend; ++iter)
    cout << *iter << endl;

  return 0;
}  
