#include <iostream>

int H(int x, int n) {
  if (n==0) {
    return 1;
  }

  if (n == 1) {
    return 2*x;
  }

  return 2*x*H(x,n-1)+2*(n-1)*H(x, n-2);
  
  
}

int main() {

  std::cout << H(5, 4);

  return 0;
}
