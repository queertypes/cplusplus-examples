#include <cstdio>

struct Seconds {
	float s;
};

struct Distance {
	float d;
};

struct Velocity {
	float v;
};

namespace Physics {
	constexpr Seconds operator"" s(const long double i)
	{
		return Seconds{i};
	}

	constexpr Distance operator"" m(const long double i)
	{
		return Distance{i};
	}

	constexpr Velocity operator"" mps(const long double i)
	{
		return Velocity{i};
	}
};

Distance operator*(const Velocity& v, const Seconds& s)
{
	return Distance{v.v * s.s};
}

Distance operator*( const Seconds& s, const Velocity& v)
{
	return Distance{v.v * s.s};
}

int main()
{
	Distance x = 12.5mps * 25.1s;

	return 0;
}
