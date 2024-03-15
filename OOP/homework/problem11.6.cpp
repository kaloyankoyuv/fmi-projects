#include <functional>
#include <iostream>

template <typename A, typename B> class my_switch {
private:
  int n;

public:
  my_switch() { this->n = 1; }

  std::function<B(A)> operator()(std::function<B(A)> f, std::function<B(A)> g,
                                 int _n) {
    if (this->n <= _n) {
      this->n++;
      return f;
    } else {
      return g;
    }
  }
};

int main() {

  my_switch<int, int> s;

  std::cout << s([](int x) -> int { return x * 2; },
                 [](int x) -> int { return x * 3; }, 3)(3);
  std::cout << s([](int x) -> int { return x * 2; },
                 [](int x) -> int { return x * 3; }, 3)(3);
  std::cout << s([](int x) -> int { return x * 2; },
                 [](int x) -> int { return x * 3; }, 3)(3);
  std::cout << s([](int x) -> int { return x * 2; },
                 [](int x) -> int { return x * 3; }, 3)(3);
  std::cout << s([](int x) -> int { return x * 2; },
                 [](int x) -> int { return x * 3; }, 3)(3);

  return 0;
}
