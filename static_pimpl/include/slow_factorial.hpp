struct SlowFactorialImplementation {
  int fac(const int n) {
    if (n == 0) return 1;
    else return n * fac(n-1);
  }

  int operator()(const int n) {
    return fac(n);
  }
};
