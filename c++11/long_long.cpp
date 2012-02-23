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
#include <cstdio>

template <unsigned Base, unsigned Exp>
struct Power {
	static const long long val = Base * Power<Base, Exp-1>::val;
};

template <unsigned Base>
struct Power<Base, 0>
{
	static const long long val = 1;
};

int main()
{
	long long x = Power<2,60>::val; // 2 raised to the 60th power
	unsigned long long y = 9223372036854775808ULL;

	printf("%lld %llu\n", x, y);

	return 0;
}
