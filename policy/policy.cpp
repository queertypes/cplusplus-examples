#include <iostream>
#include <cassert>

template <typename T>
struct NativeIncrementPolicy {
  T& increment(T& t) {
    return ++t;
  }
};

template <typename T>
struct AddingIncrementPolicy {
  T& increment(T& t) {
    return (t += 1);
  }
};

template <typename T>
struct NativeDecrementPolicy {
  T& decrement(T& t) {
    return --t;
  }
};

template <typename T>
struct SubtractingDecrementPolicy {
  T& decrement(T& t) {
    t -= 1;
    return t;
  }
};

template <typename T,
	  template <class> class IncrementPolicy = NativeIncrementPolicy,
	  template <class> class DecrementPolicy = NativeDecrementPolicy>
class MyInteger 
  : IncrementPolicy<T>, DecrementPolicy<T> {
public:
  explicit MyInteger(const T& t) : data(t) {}

  T& operator++() {
    return increment(this->data);
  };

  T& operator--() {
    return decrement(this->data);
  };

  const T& value() { return this->data; }

private:
  T data;
};

int main()
{
  MyInteger<int, NativeIncrementPolicy, NativeDecrementPolicy> x(5);
  ++x;
  --x;
  assert(x.value() == 5);

  MyInteger<int, AddingIncrementPolicy, NativeDecrementPolicy> xx(5);
  ++xx;
  --xx;
  assert(xx.value() == 5);

  MyInteger<int, NativeIncrementPolicy, SubtractingDecrementPolicy> xxx(5);
  ++xxx;
  --xxx;
  assert(xxx.value() == 5);


  MyInteger<int, AddingIncrementPolicy, SubtractingDecrementPolicy> xxxx(5);
  ++xxxx;
  --xxxx;
  assert(xxxx.value() == 5);

  return 0;
}
