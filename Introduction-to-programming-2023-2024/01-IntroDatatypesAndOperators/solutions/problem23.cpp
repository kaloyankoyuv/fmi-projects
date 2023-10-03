#include <iostream>
using namespace std;

int main() {
  double a, b;
  cin >> a >> b;
  b/=100;
  int i = a;

  double x = a + a*b;
  a = x;
  double y = a + a*b;
  a = y;
  double z = a + a*b;
  a = z;

  cout << a - i<< endl;
}
