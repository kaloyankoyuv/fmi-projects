#include <cmath>
#include <iostream>
using namespace std;

bool isSumDivisibleBy3(int n) {

  int sum = 0;
  while (n>0) {
    sum+=n%10;
    n/=10;
  }

  return sum%3==0;
}

int main() {

  int n;
  cin >> n;
  cout << isSumDivisibleBy3(n) << endl;

  return 0;
}
