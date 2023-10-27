#include <iostream>

bool isPrime(int a) {

  if(a<2) {
    return false;
  }

  if(a==2) {
    return true;
  }

  for (int i=2; i<a; i++){
    if(a%i==0) {
      return false;
    }
  }
  return true;
}

int numOfPrimes(int a, int b) {
  int result = 0;

  for(int i = a; i<=b; i++) {
    if(isPrime(i)) {
      result++;
    }
  }
  return result;
  
}

int main() {

  int a, b;
  std::cin >> a >> b;

  std::cout << numOfPrimes(a, b) << std::endl;

  return 0;
}
