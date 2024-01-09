#include <iostream>

float pow(float num, int power) {
  if (power == 0) {
    return 1;
  }

  if (power == 1) {
    return num;
  }

  return num * pow(num, power - 1);
}

int main() {

  float n;
  int power;
  
  std::cin >> n >> power;

  std::cout << pow(n, power) << std::endl;;

  return 0;
}
