#include <cmath>
#include <iostream>
using namespace std;

int main() {


  
  int x, k;
  cin >> x >> k;
  
  // without while loop:
  x /= pow(10, k-1);
  cout << x%10 << endl;

  // with while loop:
  while (k>1) {
    x /= 10;
    k--;
  }

  cout << x%10 << endl;

  return 0;
}
