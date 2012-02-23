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
#include <algorithm>
#include <iostream>
using namespace std;

template <class X>
void f(vector<X>& x)
{
	struct Less {
		bool operator() (const X& lhs, const X& rhs) {
			return lhs < rhs;
		}
	};

	sort(x.begin(), x.end(), Less());
}

int main()
{
	vector<int> x = {4,1,3,7,3,2};

	f(x);

	for (auto i : x) 
		cout << i << ",";
	cout << endl;
	
	return 0;
}
