#include <iostream>
using namespace std;

int main() {

  int x0, y0, a, x, y;
  cin >> x0 >> y0 >> a >> x >> y;

  if (x <= x0 + a && x >= x0 && y <= y0 + a && y >= y0) {
    cout << 1 << endl;
  } else {
    cout << 0 << endl;
  }

  return 0;
}
