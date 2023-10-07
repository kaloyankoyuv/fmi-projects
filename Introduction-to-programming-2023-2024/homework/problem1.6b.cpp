#include <iostream>
using namespace std;

int main() {

  double a, b, c;
  cin >> a >> b >> c;

  cout << ((b*b - 4.0*a*c) < 0.0) << endl;
  
  return 0;
}
