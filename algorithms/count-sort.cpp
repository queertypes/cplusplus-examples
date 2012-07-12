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
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <random>
#include <chrono>
#include <cassert>
using namespace std;

template <typename T, size_t limit=1<<20,
          class Gen=mt19937>
struct RandGen {
  T operator()() {
    return static_cast<T>(randgen() % limit);
  }

  Gen randgen;
};

template <class IIter>
struct SequencePrinter {
  void operator()(const IIter i, const IIter n) {
    typedef typename iterator_traits<IIter>::value_type T;
    cout << "[ "; 
    copy(i, n, ostream_iterator<T>(cout, " "));
    cout << "] \n";
  }
};

template <class T>
vector<T> count_sort(const vector<T>& in) {
  const size_t n = in.size();
  const T k = *(max_element(begin(in), end(in))) + 1;
  vector<size_t> out(n,0);
  vector<size_t> c(k,0);
  
  for (size_t i = 0; i < n; ++i) {
    c[in[i]] += 1;
  }

  for (size_t i = 1; i < k; ++i)
    c[i] += c[i-1];

  for (size_t i = n-1;; --i) {
    out[c[in[i]]-1] = in[i];
    c[in[i]] -= 1;
    if (i == 0) break;
  }

  return out;
}

int main()
{
  static const size_t n = 1<<25;
  vector<size_t> x(n);
  RandGen<size_t, n> randgen;
  chrono::time_point<chrono::system_clock> std_start, std_end, c_start, c_end;

  generate(begin(x), end(x), randgen);

  std_start = chrono::system_clock::now();
  sort(begin(x), end(x));
  std_end = chrono::system_clock::now();

  c_start = chrono::system_clock::now();
  vector<size_t> xx = std::move(count_sort(x));
  c_end = chrono::system_clock::now();
  assert(equal(begin(x), end(x), begin(xx)));

  size_t elapsed_sort_msec = 
    chrono::duration_cast<chrono::milliseconds>(std_end - std_start).count();
  size_t elapsed_csort_msec = 
    chrono::duration_cast<chrono::milliseconds>(c_end - c_start).count();
  
  cout << "standard sort millisec: " << elapsed_sort_msec << "\n"
       << "count sort millisec: " << elapsed_csort_msec << "\n";

  return 0;
}
