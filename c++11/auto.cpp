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
using namespace std;

// compile-time factorial
template <size_t N>
struct Factorial {
	static const size_t val = N * Factorial<N-1>::val;
};

template <>
struct Factorial<0> {
	static const size_t val = 1;
};

int main() {
	// vector initialization using initializer lists
	vector<int> v = {Factorial<5>::val,
									 Factorial<7>::val,
									 Factorial<8>::val,
									 Factorial<3>::val,
									 Factorial<4>::val};

	// old-style iterator use
	cout << "[";
	for (vector<int>::const_iterator iter = v.begin(),
				 iend = v.end(); iter != iend; ++iter)
		cout << *iter << " ";
	cout << "]\n";

	// simplified new-style using type inference and
	// free functions begin() and end()
	cout << "[";
	for (auto iter = begin(v), iend = end(v); iter != iend; ++iter)
		cout << *iter << " ";
	cout << "]\n";

	// using range-for with auto
	cout << "[";
	for (const auto elem : v)
		cout << elem << " ";
	cout << "]\n";

	return 0;
}
