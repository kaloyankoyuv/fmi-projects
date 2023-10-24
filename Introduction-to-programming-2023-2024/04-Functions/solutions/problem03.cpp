#include <iostream>
using namespace std;

double calcP(double r) {
  return 2*3.14*r;
}

double calcS(double r) {
  return 3.14*r*r;  
}


int main() {
  
  double r;
  cin >> r;

  cout << calcP(r) << endl << calcS(r) << endl;
  
  return 0;
}
