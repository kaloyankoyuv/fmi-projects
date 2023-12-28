#include <iostream>
#include <cmath>
using namespace std;

int main() {

  double a, b;
  cin >> a >> b;
  
  cout << (a<0.0 && b<0.0 && sqrt(pow(a, 2.0) + pow(b, 2.0))==5.0) << endl;
  
  return 0;
}
