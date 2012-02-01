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

/** 
 * Warning: Requires G++ 4.7
 */
#include <cstdio>

struct Seconds {
	float s;
};

struct Distance {
	float d;
};

struct Velocity {
	float v;
};

namespace Physics {
	constexpr Seconds operator"" s(long double i)
	{
		return Seconds{i};
	}

	constexpr Distance operator"" m(long double i)
	{
		return Distance{i};
	}

	constexpr Velocity operator"" mps(long double i)
	{
		return Velocity{i};
	}
};

Distance operator*(const Velocity& v, const Seconds& s)
{
	return Distance{v.v * s.s};
}

Distance operator*( const Seconds& s, const Velocity& v)
{
	return Distance{v.v * s.s};
}

int main()
{
	Distance x = 12.5mps * 25.1s;

	return 0;
}
