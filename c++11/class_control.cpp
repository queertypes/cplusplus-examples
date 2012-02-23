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
#include <bits/move.h>

struct X {
  X() = default;
  ~X() = default;

  X(const X&) = delete;
  X& operator=(const X&) = delete;

  X(const X&&) = delete;
  X& operator=(const X&&)  = delete;
};

int main()
{
  X x;
  //X xx(x);
  X xy;

  //xy = x;

  // X xm(std::move(x));
  // X xmm;
  // xmm = std::move(x);

  return 0;
}
