#include <factorial.hpp>
#include <fast_factorial.hpp>
#include <slow_factorial.hpp>

Factorial::Factorial(const FImplType i) 
{
	switch (i) {
	case FImplType::FAST:
		_i.reset(new FastFactorialImplementation());
		break;
	case FImplType::SLOW:
		_i.reset(new SlowFactorialImplementation());
		break;
	default:
		_i.reset(new FastFactorialImplementation());
	}
}

int Factorial::operator()(const int n) {
	return (*_i)(n);
}
