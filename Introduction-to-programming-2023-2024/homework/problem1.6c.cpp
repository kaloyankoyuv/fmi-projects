#include <iostream>
#include <cmath>
using namespace std;

int main() {

  double a, b;
  cin >> a >> b;

  double R = 5.0;
  double Ox=0.0, Oy=1.0;

  cout << (sqrt((a-Ox)*(a-Ox)+(b-Oy)*(b-Oy)) < R) << endl;
  
  return 0;
}
