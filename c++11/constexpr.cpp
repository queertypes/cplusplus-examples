#include <iostream>
#include <algorithm>
#include "config.hpp"
using namespace std;

constexpr size_t
imin(const size_t lhs, const size_t rhs)
{
  return (lhs < rhs) ? lhs : rhs;
}

constexpr size_t
memoryPartition()
{
  return MEM_SIZE_KBYTES / (1 << 16);
}

constexpr size_t
cpuFactor()
{
  return NUM_CPUS * CPU_SPEED_GHZ;
}

constexpr size_t
bufferSize()
{
  return imin(STACK_SIZE_BYTES/2, 
              cpuFactor() * memoryPartition());
}

// Someone else is welcome to provide the macro
// equivalent of this code! Also, a template meta-program
// would also work here.
int main()
{
  // using compile-time function to initialize buffer size
  // using regular functions would generate a compiler
  // error
  uint8_t arr[bufferSize()];

  cout << "arr[" << bufferSize() -1 << "] = " 
       << static_cast<size_t>(arr[bufferSize() - 1])
       << endl;

  return 0;
}
