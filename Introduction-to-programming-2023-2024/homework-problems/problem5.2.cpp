#include <iostream>

int mult(int m, int n) {

  if (n==1) {
    return m;
  }

  return m+mult(m,n-1);
  
}

int main() {

  std::cout << mult(6, 5);

  return 0;
}
