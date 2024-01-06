#include <iostream>

const size_t maxPower = 50;

struct Poly {
  double coefs[maxPower];
  size_t power;
};

Poly prod(Poly polynom1, Poly polynom2) {

  Poly result;

  result.power = polynom1.power * polynom2.power - 1;

  for (int i = 0; i <= result.power; i++) {
    result.coefs[i] = 0;
  }

  for (int i = 0; i <= polynom1.power; i++) {
    for (int j = 0; j <= polynom2.power; j++) {
      result.coefs[i + j] += polynom1.coefs[i] * polynom2.coefs[j];
    }
  }

  return result;
}

int main() {

  Poly polynom1, polynom2;

  std::cin >> polynom1.power;

  for (int i = 0; i <= polynom1.power; i++) {
    std::cin >> polynom1.coefs[i];
  }

  std::cin >> polynom2.power;

  for (int i = 0; i <= polynom2.power; i++) {
    std::cin >> polynom2.coefs[i];
  }

  Poly polynom = prod(polynom1, polynom2);

  std::cout << polynom.power << std::endl;

  for (int i = 0; i <= polynom.power; i++) {
    std::cout << polynom.coefs[i] << " ";
  }

  return 0;
}
