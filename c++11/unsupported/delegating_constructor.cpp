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

struct X {
  X() = default;

  explicit X(const float a)
  {
    cout << "1 arg ctor\n";
    X(a, 0.0f, 0.0f);
  }

  X(const float a, const float b)
  {
    cout << "2 arg ctor\n";
    X(a,b,0.0f);
  }

  X(const float a,
    const float b,
    const float c) : x(a), y(b), z(c)
  {
    cout << "3 arg ctor\n";
  }

  float x, y, z;
};

int main()
{
  X x3{1.1, 2.2, 3.3};
  X x2{1.1, 2.2};
  X x1{1.1};

  return 0;
}
