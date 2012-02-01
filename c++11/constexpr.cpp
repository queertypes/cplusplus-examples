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
#include <algorithm>
#include "config.hpp"
using namespace std;

constexpr size_t
imin(const size_t lhs, const size_t rhs)
{
  return (lhs < rhs) ? lhs : rhs;
}

constexpr size_t
memoryPartition()
{
  return MEM_SIZE_KBYTES / (1 << 16);
}

constexpr size_t
cpuFactor()
{
  return NUM_CPUS * CPU_SPEED_GHZ;
}

constexpr size_t
bufferSize()
{
  return imin(STACK_SIZE_BYTES/2, 
              cpuFactor() * memoryPartition());
}

// Someone else is welcome to provide the macro
// equivalent of this code! Also, a template meta-program
// would also work here.
int main()
{
  // using compile-time function to initialize buffer size
  // using regular functions would generate a compiler
  // error
  uint8_t arr[bufferSize()];

  cout << "arr[" << bufferSize() -1 << "] = " 
       << static_cast<size_t>(arr[bufferSize() - 1])
       << endl;

  return 0;
}
