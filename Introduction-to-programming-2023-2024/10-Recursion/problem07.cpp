#include <iostream>

int pow(int x, int y) {

  if (y == 0) {
    return 1;
  }

  return x*pow(x, y-1);
}

int main() {

  std::cout << pow(2,10);

  return 0;
}
