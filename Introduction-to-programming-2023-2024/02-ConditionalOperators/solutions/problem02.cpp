#include <iostream>
using namespace std;

int main() {

  int a, b, c;
  cin >> a >> b >> c;

  int x, y, z;

  if (a<=b && a <=c) {

    x = a;
    if (b>=c) {
      y = c;
      z = b;
    } else {
      y = b;
      z = c;
    }
    
  } else if (b<=a && b<=c) {
    x = b;
    if (a>=c) {
      y = c;
      z = a;
    } else {
      y = a;
      z = c;
    }
  } else {
    x = c;
    if (a>=b) {
      y = b;
      z = a;
    } else {
      y = a;
      z = b;
    }
  }
}
