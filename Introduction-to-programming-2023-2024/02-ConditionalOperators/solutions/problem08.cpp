#include <iostream>
#include <cmath>
using namespace std;

int main() {

  int x, y, option;
  cin >> x >> option;

  switch (option) {
  case 1:
    y = x - 5;
    break;
  case 2:
    y = sin(x);
    break;
  case 3:
    y = cos(x);
    break;
  case 4:
    y = exp(x);
    break;
  }

  cout << y << endl;

  return 0;
}
