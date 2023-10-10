#include <iostream>
using namespace std;

int main() {

  double a, b, c;
  cin >> a >> b >> c;

  if (a > b + c) {
    cout << 0;
  } else if (b > a + c) {
    cout << 0;
  } else if (c > a + b) {
    cout << 0;
  } else {
    if (a == b && a == c && b == c) {
      cout << 3 << endl;
    } else if (a !=b && a !=c && b != c) {
      cout << 1 << endl;
    } else {
      cout << 2 << endl;
    }
  }

  return 0;
}
