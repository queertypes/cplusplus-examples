/**
 *   C++ Examples - a collection of C++ examples intended to serve as a tutorial
 *   Copyright (C) 2011-2012 Alejandro Cabrera
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>. 
 **/
#include <vector>
#include <iostream>
using namespace std;

/**
 * user-defined type satisfying enough c++11 standard
 * container-type requirements to be traversed using
 * range-for.
 */
struct MySequence {
  typedef int value_type;
  typedef int reference;
  typedef const int const_reference;
  typedef int* iterator;
  typedef const int *const const_iterator;
  typedef size_t difference_type;
  typedef size_t size_type;

  MySequence(const size_type n)
    : size(n)
  {
    data = new int[n];
  }

  MySequence(const size_type n, 
             const value_type val)
    : size(n)
  {
    data = new int[n];
    for (size_type i = 0; i < size; ++i)
      data[i] = val;
  }

  ~MySequence()
  {
    delete[] data;
  }

  iterator begin() const
  {
    return data;
  }

  iterator end() const
  {
    return data + size;
  }

private:
  size_type size;
  int* data;
};

int main()
{
  vector<int> arr = {1,2,3,4,5};
  MySequence seq(3, 4);
  
  // modifying elements with range-for
  for(int& x : arr){
    x *= 2;
  }

  // output elements
  cout << "vector [";
  for (const int x : arr) {
    std::cout << x << " ";
  }
  cout << "]\n";

  // modifying user-defined elements with range-for
  for(int& x : seq){
    x *= 2;
  }

  // output user-defined elements
  cout << "MySeq [";
  for (const int x : seq) {
    std::cout << x << " ";
  }
  cout << "]\n";

  return 0;
}
