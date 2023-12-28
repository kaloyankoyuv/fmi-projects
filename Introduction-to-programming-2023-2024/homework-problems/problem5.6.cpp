#include <iostream>

bool isInNumber(int n, int k) {

  if (n==0 && k!=0) {
    return false;
  }

  if (n==0 && k==0) {
    return true;
  }

  if(n%10==k) {
    return true;
  }

  return isInNumber(n/10, k);
  
}

int main() {

  std::cout << isInNumber(123, 1);

  return 0;
}
