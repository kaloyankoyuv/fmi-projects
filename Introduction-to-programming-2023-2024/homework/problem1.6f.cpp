#include <iostream>
#include <cmath>
using namespace std;

int main() {

  double a, b;
  cin >> a >> b;

  cout << (sqrt(pow(a, 2.0) + pow(b, 2.0)) > 5.0 && sqrt(pow(a, 2.0) + pow(b, 2.0)) < 10.0) << endl;

  
  return 0;
}
