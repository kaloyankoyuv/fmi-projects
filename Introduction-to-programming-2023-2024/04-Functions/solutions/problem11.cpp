#include <iostream>
using namespace std;

int powerAB(int a, int b) {
  int result = a;
  for (int i = 0; i < b-1; i++) {
    result = result * a;
  }
  return result;
}

int main() {
  int a, b;
  cin >> a >> b;

  cout << powerAB(a, b) << endl;
  
  return 0; }
