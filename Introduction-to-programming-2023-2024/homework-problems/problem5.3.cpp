#include <iostream>

int gcd(int a, int b) {

  if (b==0) {
    return a;
  }

  return gcd(b, a%b);
  
}

int main() {

  std::cout << gcd(5, 25);

  return 0;
}
