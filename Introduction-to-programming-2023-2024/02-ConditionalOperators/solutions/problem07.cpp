#include <iostream>
using namespace std;

int main() {
  int k, x, y;
  cin >> x >> y;

  if (x > 0 && y > 0) {
    k = 1;
  } else if (x < 0 && y > 0) {
    k = 2;
  } else if (x < 0 && y < 0) {
    k = 3;
  } else if (x > 0 && y < 0) {
    k = 4;
  }

  cout << k << endl;

  return 0;
}
