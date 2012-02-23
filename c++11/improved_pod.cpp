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
#include <cstring>
#include <type_traits>

struct MyPOD {
	MyPOD() = default;
	MyPOD& operator=(const MyPOD&) = default;
	MyPOD(const MyPOD&) = default;
	~MyPOD() = default;

	MyPOD(const float x, 
				const float y, 
				const float z) : _x{x} , _y{y}, _z{z} {} 



	// uncomment these lines and suddenly this is 
	// no longer a POD
  //private:
  //	float *data;
  //public:

	float _x, _y, _z;
};

int main()
{
	MyPOD pod{1.2, 2.3, 4.5};
	MyPOD pod2;

	if (std::is_pod<MyPOD>::value == true)
		printf("MyPOD is a POD\n");
	else
		printf("MyPOD is NOT a POD\n");
	
	printf("pod x=%.1f, y=%.1f, z=%.1f\n", pod._x, pod._y, pod._z);
	printf("pod2 x=%.1f, y=%.1f, z=%.1f\n", pod2._x, pod2._y, pod2._z);

	memcpy(&pod2, &pod, sizeof(pod));
	memset(&pod, 0, sizeof(pod));

	printf("pod x=%.1f, y=%.1f, z=%.1f\n", pod._x, pod._y, pod._z);
	printf("pod2 x=%.1f, y=%.1f, z=%.1f\n", pod2._x, pod2._y, pod2._z);

	return 0;
}
