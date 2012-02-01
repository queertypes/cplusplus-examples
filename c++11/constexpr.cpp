/** @file constexpr.cpp
 *
 **/
/** @file constexpr.cpp
 *
 **/
#include <cstdint>

constexpr uintmax_t
returnFive()
{
   return 5;
}

int main()
{
  uintmax_t arr[5 + returnFive()];

  return 0;
}
