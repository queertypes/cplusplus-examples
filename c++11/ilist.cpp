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
#include <memory>
#include <algorithm>
#include <iterator>
#include <initializer_list>
using namespace std;

template <typename T>
struct Sequence {
	typedef T value_type;
	typedef T& reference;
	typedef const T& const_reference;
	typedef T* iterator;
	typedef const T*const const_iterator;
	typedef size_t size_type;

	Sequence() : size(0), data(nullptr) {}
	explicit Sequence(const size_type n) 
		: size(n) {
		data = new T[n];
	}

	Sequence(const size_type n, const T init)
		: size(n) {
		data = new T[n];
		for (size_t i = 0; i < n; ++i)
			data[i] = init;
	}

	Sequence(const initializer_list<value_type>& ilist)
		: size(ilist.size())
	{
		data = new T[this->size];
		copy(ilist.begin(), ilist.end(), data);
	}

	iterator begin()
	{
		return data;		
	}

	iterator end()
	{
		return data + size;
	}

private:
	size_type size;
	T* data;
};

int main()
{
	// already supported by C++98
	int arr[] = {1,2,3,4,5};

	// support added in C++11
	vector<int> x = {1,2,3,4,5};

	// our version using C++11
	Sequence<int> s = {1,2,3,4,5};

	cout << "array [";
	copy(arr, arr+5, ostream_iterator<int>(cout, " "));
	cout << "]\n";

	cout << "vector [";
	copy(begin(x), end(x), ostream_iterator<int>(cout, " "));
	cout << "]\n";

	cout << "sequence [";
	copy(begin(s), end(s), ostream_iterator<int>(cout, " "));
	cout << "]\n";

	return 0;
}
