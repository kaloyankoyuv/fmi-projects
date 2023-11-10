#include <iostream>

int fib(int n) { // 1 1 2 3 5 8 13 21

  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }
  return fib(n - 2) + fib(n - 1);
}

int main() {

  int N;
  std::cin >> N;

  for (int i = 0; i < N; i++) {

    std::cout << fib(i) << std::endl;
    
  }

  return 0;
}
