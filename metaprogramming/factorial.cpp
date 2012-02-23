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

template <size_t N>
struct Factorial {
	static const size_t val = N * Factorial<N-1>::val;
};

template <>
struct Factorial<0> {
	static const size_t val = 1;
};

int main()
{
	cout << "Factorial of 0: " << Factorial<0>::val << "\n"
			 << "Factorial of 1: " << Factorial<1>::val << "\n"
			 << "Factorial of 10: " << Factorial<10>::val << "\n"
			 << "Factorial of 14: " << Factorial<14>::val << "\n";

	return 0;
}
