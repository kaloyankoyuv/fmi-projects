#include <iostream>
#include <cmath>
using namespace std;

int main() {

  double x, y;
  cin >> x;
  if (x >= 1) {
    y = log10(x) + 1.82;
  } else {
    y = x*x + 7*x + 8.82;
  }

  cout << y << endl;

  return 0;
}
