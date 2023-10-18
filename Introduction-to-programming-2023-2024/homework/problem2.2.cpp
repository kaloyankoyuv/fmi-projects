#include <iostream>
#include <cmath>
using namespace std;

void printNumber(int n, int k) {

  int x = n;
  int counter = 0;
  while (x>0) {
    x/=k;
    counter++;
  }

  int digits[counter];

  int i = 0;
  while (n>0) {
    digits[i] = n%k;
    n/=k;
    i++;
  }

  for (int i = counter-1; i>=0; i--) {
    cout << digits[i];
  }
  
}

int main() {

  printNumber(123, 2);

  return 0;
}
