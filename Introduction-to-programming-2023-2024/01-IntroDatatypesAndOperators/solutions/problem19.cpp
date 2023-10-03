#include <cmath>
#include <iostream>
using namespace std;

int main() {
  double a, b, c;
  cin >> a >> b >> c;

  cout << a + b + c << endl; // obikolka
  int p = (a + b + c)/2;
  cout << sqrt(p*(p-a)*(p-b)*(p-c)); // lice
  
}
