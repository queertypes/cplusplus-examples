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
#include <cstdint>
using namespace std;

enum class ShadingMode : uint8_t
{
  FLAT,
  SMOOTH,
  DEFAULT = SMOOTH
};

enum class LightingMode : char
{
  PHONG = 2,
  REALISTIC,
  DEFAULT = PHONG
};

/**
 * These ostream functions are needed to tell the compiler
 * how to print the enum classes.
 **/
ostream& operator<<(ostream& os, const LightingMode lm)
{
  os << static_cast<int>(lm);
  return os;
}

ostream& operator<<(ostream& os, const ShadingMode sm)
{
  os << static_cast<int>(sm);
  return os;
}

int main()
{
  int x = 5;
  ShadingMode currentShadingMode = ShadingMode::FLAT;
  LightingMode currentLightingMode = LightingMode::DEFAULT;

  // x = ShadingMode::FLAT; /* error: cannot convert */
  // currentShadingMode = currentLightingMode; /* error: cannot convert */

  x = static_cast<int>(ShadingMode::SMOOTH); // explicit conversion okay
  
  cout << "some variable: " << x << "\n"
       << "shading mode: " << currentShadingMode << "\n"
       << "lighting mode: " << currentLightingMode << endl;

  return 0;
}
