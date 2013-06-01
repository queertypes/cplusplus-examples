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
