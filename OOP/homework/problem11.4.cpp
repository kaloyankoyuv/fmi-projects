#include <functional>
#include <iostream>

template <typename T>
std::function<T(T)> repeated(int k, std::function<T(T)> f) {
  return [k, f](T x) -> T {
    for (int i = 0; i < k; i++) {
      x = f(x);
    }
    return x;
  };
}

int main() {

  std::cout << repeated<int>(2, [](int x) -> int { return x * x; })(2);

  return 0;
}
