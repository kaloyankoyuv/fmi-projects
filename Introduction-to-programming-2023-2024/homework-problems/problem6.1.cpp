#include <iostream>

const size_t maxPower = 50;

struct Poly {
  double coefs[maxPower];
  size_t power;
};

Poly diff(Poly polynom) {

  for (int i = 0; i <= polynom.power; i++) {
    polynom.coefs[i] *= i;
  }

  return polynom;
}

void diff2(Poly &polynom) {

  for (int i = 0; i <= polynom.power; i++) {
    polynom.coefs[i] *= i;
  }
}

int main() {

  Poly polynom;

  std::cin >> polynom.power;

  for (int i = 0; i <= polynom.power; i++) {
    std::cin >> polynom.coefs[i];
  }

  std::cout << std::endl;

  std::cout << polynom.power << std::endl;

  for (int i = 0; i <= polynom.power; i++) {
    std::cout << polynom.coefs[i] << " ";
  }

  std::cout << std::endl;

  diff2(polynom);

  std::cout << polynom.power << std::endl;

  for (int i = 0; i <= polynom.power; i++) {
    std::cout << polynom.coefs[i] << " ";
  }

  return 0;
}
