#include <iostream>
#include <cmath>
using namespace std;

int main() {

  int n;
  cin >> n;

  int x = n;

  int counter = 0;
  while (n>0) {
    n/=10;
    counter++;
  }

  for(int i=0; i<counter; i++) {
    cout << (x/(int(pow(10, i))))%10;
  }

  cout << endl;

  return 0;
}
