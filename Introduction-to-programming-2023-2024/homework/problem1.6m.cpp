#include <iostream>
#include <cmath>
using namespace std;

int main() {

  int p;
  cin >> p;

  cout << (p/100 == 7 || p%10 == 7 || (p/10)%10 == 7) << endl;

  return 0;
}
