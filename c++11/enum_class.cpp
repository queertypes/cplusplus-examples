#include <iostream>
#include <cstdint>
using namespace std;

enum class ShadingMode : uint8_t
{
  FLAT,
	SMOOTH,
	DEFAULT = SMOOTH
};

enum class LightingMode : char
{
	PHONG = 2,
	REALISTIC,
	DEFAULT = PHONG
};

/**
 * These ostream functions are needed to tell the compiler
 * how to print the enum classes.
 **/
ostream& operator<<(ostream& os, const LightingMode lm)
{
	os << static_cast<int>(lm);
	return os;
}

ostream& operator<<(ostream& os, const ShadingMode sm)
{
	os << static_cast<int>(sm);
	return os;
}

int main()
{
	int x = 5;
	ShadingMode currentShadingMode = ShadingMode::FLAT;
	LightingMode currentLightingMode = LightingMode::DEFAULT;

	// x = ShadingMode::FLAT; /* error: cannot convert */
	// currentShadingMode = currentLightingMode; /* error: cannot convert */

	x = static_cast<int>(ShadingMode::SMOOTH); // explicit conversion okay
	
	cout << "some variable: " << x << "\n"
			 << "shading mode: " << currentShadingMode << "\n"
			 << "lighting mode: " << currentLightingMode << endl;

  return 0;
}
