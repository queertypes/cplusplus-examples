#include <iostream>
#include <functional>
#include <random>
using namespace std;

int main()
{
  vector<std::function<int()>> dice;
  random_device rd;
  for (auto i = 1; i < 20; ++i) {
    uniform_int_distribution<int> d(1, i+1);
    dice.push_back(bind(d, ref(rd)));
  }

  for (auto i = 0; i < 19; ++i) {
    cout << "d" << i + 2 << ": [";
    for (auto j = 0; j < 60; ++j) {
      cout << dice[i]() << " ";
    }
    cout << "]\n";
  }
}
