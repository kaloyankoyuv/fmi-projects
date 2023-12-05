#include <iostream>

int numOfDigits(int n) { // 1000

  if(n >= 0 && n <= 9) {
    return 1;
  }

  return 1+numOfDigits(n/10);
	      
	      

}

int main() {

  std::cout << numOfDigits(1000000000);

  return 0;
}
