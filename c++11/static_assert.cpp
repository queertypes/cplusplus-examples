#include <type_traits>
#include <iostream>
#include <algorithm>
#include <initializer_list>
using namespace std;

enum class RoundingMode {
  ROUND_EVEN,
  ROUND_ODD,
  IEEE
};

// simple compile-time point class
template <typename T, size_t N,
          RoundingMode Round = RoundingMode::IEEE>
struct Point {

  static_assert(N > 0, 
                "error: point dimension must be greater than 0.");
  static_assert(N < 4096, 
                "error: point dimension must be less than stack size.");
  static_assert(is_floating_point<T>::value == true,
                "error: only floating point types are allowed.");
  static_assert(Round != RoundingMode::ROUND_EVEN, 
                "error: unsupported rounding mode.");

  Point() = default;
  
  T p[N];
};

int main()
{
  Point<float, 10> point10;
  // Point<float, 0> point0; // error
  // Point<float, 4096> point4096; // error
  // Point<int, 10> point_i10; // error
  // Point<float, 3, RoundingMode::ROUND_EVEN> point; // error

  cout << point10.p[0] << endl;

  return 0;
}
