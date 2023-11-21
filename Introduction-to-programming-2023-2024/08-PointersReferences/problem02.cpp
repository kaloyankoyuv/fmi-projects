#include <iostream>

void increment(int &num) {

  num++;
  
}

int main() {

  int a;
  std::cin >> a;
  increment(a);

  std::cout << a;

  return 0;
}
