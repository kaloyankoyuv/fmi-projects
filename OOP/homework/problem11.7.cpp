#include <functional>
#include <iostream>

template <typename A, typename B> class before {
private:
  int n;
  B last_value=1000;

public:
  before() { this->n = 0; }

  std::function<B(A)> operator()(int _n, std::function<B(A)> f) {
    this->n++;
    if (this->n <= _n) {
      return f;
    } else {
      return [this](A x)->B{return this->last_value;};
    }
  }
};

int main() {

  before<int, int> b;
  std::cout << b(3, [](int x) -> int { return x * 2; })(10);
  std::cout << b(3, [](int x) -> int { return x * 2; })(20);
  std::cout << b(3, [](int x) -> int { return x * 2; })(30);
  std::cout << b(3, [](int x) -> int { return x * 2; })(40);
  std::cout << b(3, [](int x) -> int { return x * 2; })(50);
  

  return 0;
}
