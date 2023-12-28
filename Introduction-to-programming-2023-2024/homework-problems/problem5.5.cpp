#include <iostream>

int sumOfBaseK(int n, int k) {

  if(n==0) {
    return 0;
  }

  return n%k+sumOfBaseK(n/k, k);
  
}

int main() {

  std::cout << sumOfBaseK(64, 2);

  return 0;
}
