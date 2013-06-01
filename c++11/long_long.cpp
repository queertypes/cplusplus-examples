#include <cstdio>

template <unsigned Base, unsigned Exp>
struct Power {
	static const long long val = Base * Power<Base, Exp-1>::val;
};

template <unsigned Base>
struct Power<Base, 0>
{
	static const long long val = 1;
};

int main()
{
	long long x = Power<2,60>::val; // 2 raised to the 60th power
	unsigned long long y = 9223372036854775808ULL;

	printf("%lld %llu\n", x, y);

	return 0;
}
