#include <iostream>
using namespace std;

int main() {

  int x1, y1, a;
  int x2, y2, b;

  cin >> x1 >> y1 >> a >> x2 >> y2 >> b;

  int v1x = x2, v1y = y2;
  int v2x = x2 + b, v2y = y2;
  int v3x = x2, v3y = y2 + b;
  int v4x = x2 + b, v4y = y2 + b;

  int count = 0;
  if (v1x >= x1 && v1x <= x1 + a && v1y >= y1 && v1y <= y1 + a)
    count++;
  if (v2x >= x1 && v2x <= x1 + a && v2y >= y1 && v2y <= y1 + a)
    count++;
  if (v3x >= x1 && v3x <= x1 + a && v3y >= y1 && v3y <= y1 + a)
    count++;
  if (v4x >= x1 && v4x <= x1 + a && v4y >= y1 && v4y <= y1 + a)
    count++;

  if (count > 0) {
    cout << 1 << endl;
  } else {
    cout << 0 << endl;
  }
  return 0;
}
