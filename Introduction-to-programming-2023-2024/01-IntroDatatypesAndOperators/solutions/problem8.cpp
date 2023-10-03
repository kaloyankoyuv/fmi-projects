#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >>  x2 >>  y2;

  cout << sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
  // or cout << (pow(x1 - x2, 2) + pow(y1 - y2, 2));
}
