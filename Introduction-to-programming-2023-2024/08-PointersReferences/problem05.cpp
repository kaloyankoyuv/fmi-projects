#include <iostream>

void modifyValue(int **ptr) {

  int *Pptr = *ptr;
  (*Pptr)++;
}

void modifyValue2(int **ptr) { (*(*ptr))++; }

int main() {

  int a;
  std::cin >> a;

  int *Pa = &a;
  int **PPa = &Pa;

  modifyValue(PPa);

  std::cout << a << std::endl;
  modifyValue2(PPa);

  std::cout << a << std::endl;

  return 0;
}
