#include <iostream>

int add(int a, int b) {

  if (b == 0) {
    return a;
  }

  a = a + 1;

  return add(a, b - 1);
}

int fib(int n) {
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }
  return fib(n - 1) + fib(n - 2);
}

void printFib(int n) {

  if (n < 0) {
    return;
  }
  std::cout << fib(n) << std::endl;
  return printFib(n - 1);
}

int main() {

  std::cout << add(2, 10) << std::endl;
  return 0;
}
