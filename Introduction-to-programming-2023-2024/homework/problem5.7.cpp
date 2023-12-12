#include <iostream>

bool isFibNumber(int number, int a = 0, int b = 1) { // 0 1 1 2 3 5 8 13 21

  if (b>number) {
    return false;
  }

  if(number==a || number==b) {
    return true;
  }

  return isFibNumber(number, b, a+b);
  
}

int main() {

  int number;
  std::cin >> number;

  std::cout << isFibNumber(number);

  return 0;
}
