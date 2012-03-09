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
using namespace std;

template <class T, bool InPlace = false>
struct F {
  T operator()(const T& x) {
    T xx = x;
    ++xx;
    return xx;
  }
};

template <class T>
struct F<T, true> {
  void operator()(T& x) {
    ++x;
    return x;
  }
};

int main()
{
  int a = 1, b = 1;
  F<int> f;
  F<int, false> f_inplace;

  int c = f(a);
  f_inplace(b);

  cout << a << " " << b << " " << c << "\n";

  return 0;
}
