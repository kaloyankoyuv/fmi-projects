#include <iostream>

int fac2(int n, int a) {
  if (n == 1) {
    return 1;
  }
  return fac2(n-1, n*a);
}

int fac(int n) {


  return fac2(n, 1);
}



int main() {

  int n;
  std::cin >> n;

  std::cout << fac(n) << std::endl;

  return 0;
}
