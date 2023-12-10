#include <iostream>

double sum(size_t n) {

  if (n == 0) {
    return 0;
  }

  int num;
  std::cin >> num;

  return num + sum(n - 1);
}

int main() {

  std::cout << sum(5);
  
  return 0;
}
