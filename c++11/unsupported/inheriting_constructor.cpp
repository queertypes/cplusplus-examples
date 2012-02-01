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

struct Base {
  Base() {
    cout << "Base\n";
  }

  void f(const char x) {
    cout << "Base::f()\n";
  }
};

struct Derived : Base {
  Derived() {
    cout << "Derived\n";
  }
  
  using B::f;
  void f(const int x) {
    cout << "Derived::f\n";
  }
};

int main()
{
  Base b;
  Derived d;

  b.f(1);
  d.f(2);

  return 0;
}
