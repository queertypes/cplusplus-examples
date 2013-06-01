struct NativeIncrementPolicy(T) {
  ref T increment(ref T t) {
    return ++t;
  }
};

struct AddingIncrementPolicy(T) {
  ref T increment(ref T t) {
    return (t += 1);
  }
};

struct NativeDecrementPolicy(T) {
  ref T decrement(ref T t) {
    return --t;
  }
};

struct SubtractingDecrementPolicy(T) {
  ref T decrement(ref T t) {
    t -= 1;
    return t;
  }
};

class MyInteger(T,
		alias IncrementPolicy = NativeIncrementPolicy!(T),
		alias DecrementPolicy = NativeDecrementPolicy!(T))
: IncrementPolicy!(T), DecrementPolicy!(T) {
public:
  explicit this(const ref T t) {
    data(t);
  }

  ref T opUnary++(const string s)() if (s == "++") {
    return increment(this->data);
  } else if (s == "--") {
    return decrement(this->data); 
  }

  const T& value() { return this->data; }

private:
  T data;
};

int main()
{
  MyInteger!(int, NativeIncrementPolicy, NativeDecrementPolicy) x(5);
  ++x;
  --x;
  assert(x.value() == 5);

  MyInteger!(int, AddingIncrementPolicy, NativeDecrementPolicy) xx(5);
  ++xx;
  --xx;
  assert(xx.value() == 5);

  MyInteger!(int, NativeIncrementPolicy, SubtractingDecrementPolicy) xxx(5);
  ++xxx;
  --xxx;
  assert(xxx.value() == 5);


  MyInteger!(int, AddingIncrementPolicy, SubtractingDecrementPolicy) xxxx(5);
  ++xxxx;
  --xxxx;
  assert(xxxx.value() == 5);

  return 0;
}
