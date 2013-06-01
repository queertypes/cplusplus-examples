#include <cstdio>

template <class T>
struct X {
};

int main()
{
	// can your compiler handle this parse?
	X<X<int>> *x{nullptr};

	// output for the sake of silencing compiler warnings
	printf("%p\n", static_cast<void *>(x));

	return 0;
}
