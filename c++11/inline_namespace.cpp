/**
 *   C++ Examples - a collection of C++ examples intended to serve as a tutorial
 *   Copyright (C) 2011 Alejandro Cabrera
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
