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
