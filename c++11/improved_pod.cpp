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
