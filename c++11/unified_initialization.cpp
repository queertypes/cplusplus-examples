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
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

struct X {
	float x,y,z;
	int xi,yi,zi;
};

void print_X(const X& mix)
{
	cout << "My mix:\n"
			 << mix.x << " " << mix.y << " " << mix.z << "\n"
			 << mix.xi << " " << mix.yi << " " << mix.zi << "\n";
}

int main()
{
	// all initialization, no '=' to be seen!
	int x{1};
	int *p{nullptr};
	vector<int> v{1,2,3,4,5};
	float *f{new float[10]};
	X mix{1.0,2.0,3.0,1,2,3};

	// can even pass to functions, as long as structure of
	// argument matches structure of expected type
	print_X({1.1,2.2,3.3,1,2,3});	
	
	delete[] f;

	cout << p << x << mix.x << "\n";

	return 0;
}
