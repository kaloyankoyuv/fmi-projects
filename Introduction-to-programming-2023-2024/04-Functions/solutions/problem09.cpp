#include <iostream>
using namespace std;

bool isPrime(int a) {

  if (a == 2) {
    return true;
  }

  for (int i = 2; i < a; i++) {
    if (a % i == 0) {
      return false;
    }
  }
  return true;
}

void printPrimeM(int n) {
  for (int i = 2; i <= n; i++) {
    if (n % i == 0 && isPrime(i)) {
      cout << i << endl;
    }
  }
}

int main() {

  int n;
  cin >> n;

  printPrimeM(n);

  return 0;
}
