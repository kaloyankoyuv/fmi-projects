#include <iostream>

int factorial(int number) {

  int result = 1;
  for (int i = 1; i <= number; i++) {
    result *= i;
  }
  return result;
}

int pow(int number, int exponent) {
  int result = 1;
  for (int i = 0; i < exponent; i++) {
    result *= number;
  }
  return result;
}

int calculate(int x, int n) {
  int result = 0;

  for (int i = 0; i <= n; i++) {
    result += pow(-1, n) * pow(x, 2 * i + 1) / factorial(2 * i + 1);
  }

  return result;
}

int main() {

  float x;
  std::cin >> x;

  std::cout << calculate(x, 6) << std::endl;

  return 0;
}
