#include <bits/move.h>

struct X {
  X() = default;
  ~X() = default;

  X(const X&) = delete;
  X& operator=(const X&) = delete;

  X(const X&&) = delete;
  X& operator=(const X&&)  = delete;
};

int main()
{
  X x;
  //X xx(x);
  X xy;

  //xy = x;

  // X xm(std::move(x));
  // X xmm;
  // xmm = std::move(x);

  return 0;
}
