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
#include <type_traits>
#include <iostream>
#include <algorithm>
#include <initializer_list>
using namespace std;

enum class RoundingMode {
  ROUND_EVEN,
  ROUND_ODD,
  IEEE
};

// simple compile-time point class
template <typename T, size_t N,
          RoundingMode Round = RoundingMode::IEEE>
struct Point {

  static_assert(N > 0, 
                "error: point dimension must be greater than 0.");
  static_assert(N < 4096, 
                "error: point dimension must be less than stack size.");
  static_assert(is_floating_point<T>::value == true,
                "error: only floating point types are allowed.");
  static_assert(Round != RoundingMode::ROUND_EVEN, 
                "error: unsupported rounding mode.");

  Point() = default;
  
  T p[N];
};

int main()
{
  Point<float, 10> point10;
  // Point<float, 0> point0; // error
  // Point<float, 4096> point4096; // error
  // Point<int, 10> point_i10; // error
  // Point<float, 3, RoundingMode::ROUND_EVEN> point; // error

  cout << point10.p[0] << endl;

  return 0;
}
