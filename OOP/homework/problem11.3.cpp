#include <functional>
#include <iostream>

template <typename T> std::function<bool(T)> negate(std::function<bool(T)> p) {
  return [p](T x) -> bool { return !p(x); };
}

int main() {

  std::function<bool(int)> even =
      negate<int>([](int x) -> bool { return x % 2 != 0; });

  std::cout << even(2);

  return 0;
}
