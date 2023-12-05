#include <iostream>

void printN(int n) {
  if(n==0) {
    return;
  }

  printN(n-1);

  std::cout << n << ' ';
}

int main() {

  printN(10);

  return 0;
}
