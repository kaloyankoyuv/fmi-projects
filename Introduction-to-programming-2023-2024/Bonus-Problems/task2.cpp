#include <iostream>

bool isPrime(int number) {

  if (number < 2) {
    return false;
  }

  for (int i = 2; i < number; i++) {
    if (number % i == 0) {
      return false;
    }
  }
  return true;
}

int numberOfDivisors(int number) {
  int counter = 0;
  for (int i = 2; i < number; i++) {
    if (number % i == 0) {
      counter++;
    }
  }
  return counter;
}

int solve(int a, int b) {

  int result = 0;

  for (int i = a; i <= b; i++) {
    if (isPrime(numberOfDivisors(i))) {
      result++;
    }
  }

  return result;
}

int main() {

  int a, b;

  std::cin >> a >> b;

  std::cout << solve(a, b) << std::endl;

  return 0;
}
