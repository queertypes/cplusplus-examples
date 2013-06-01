#include <iostream>
using namespace std;

template <size_t Base, size_t Exponent>
struct Power {
	static const size_t val = Base * Power<Base, Exponent-1>::val;
};

template <size_t Base>
struct Power<Base, 0> {
	static const size_t val = 1;
};

int main()
{
	cout << "3**6 = " << Power<3,6>::val << "\n"
			 << "10**5 = " << Power<10,5>::val << "\n"
			 << "2**10 = " << Power<2,10>::val << "\n";

	return 0;
}
