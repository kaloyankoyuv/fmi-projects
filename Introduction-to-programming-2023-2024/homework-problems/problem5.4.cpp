#include <iostream>

int multToN(int n, int k) {

  if(n<=1) {
    return 1;
  }

  return n*multToN(n-k, k);
  
}

int main() {

  std::cout << multToN(6,2);

  return 0;
}
