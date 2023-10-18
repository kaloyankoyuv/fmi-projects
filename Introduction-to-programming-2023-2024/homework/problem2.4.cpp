#include <iostream>
using namespace std;

bool isPerfect(int x) {

  int sum = 0;
  for (int i=1; i<x; i++){
    if(x%i==0) {
      sum+=i;
    }
  }
  
  return sum==x;
}

void printPerfectNumber(int n) {

  for(int i=2; i<=n; i++) {
    if (isPerfect(i)) {
      cout << i << endl;
    }
  }
  
}

int main() {

  int n;
  cin >> n;
  printPerfectNumber(n);

  return 0;
}
