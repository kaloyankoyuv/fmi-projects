#include <iostream>

int main() {

  int a = 3, b = 4;

  int *c, *d;

  c = &a;
  d = new int(5);

  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << c << std::endl;
  std::cout << d << std::endl;

  std::cout << &a << std::endl;
  std::cout << &b << std::endl;

  std::cout << *c << std::endl;
  std::cout << *d << std::endl;
  
  return 0;
}
