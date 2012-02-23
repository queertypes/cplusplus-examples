template <class Impl>
struct Factorial {
  int operator()(const int n) {
    Impl i;
    
    return i(n);
  };
};
