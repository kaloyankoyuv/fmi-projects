#include <iostream>
#include <cmath>
using namespace std;

int main() {

  double a, b, c, d, f;
  cin >> a >> b >> c >> d >> f;

  cout << (sqrt(pow((a-c), 2.0) + pow((b-d), 2.0)) > f) << endl;
  
  return 0;
}
