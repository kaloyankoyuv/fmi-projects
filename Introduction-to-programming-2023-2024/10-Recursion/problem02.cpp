#include <iostream>

int fac(int n) {
  if(n == 0) {
    return 1;
  }

  return n*fac(n-1);
}

int main() {

  std::cout << fac(6);
  

  return 0;
}
