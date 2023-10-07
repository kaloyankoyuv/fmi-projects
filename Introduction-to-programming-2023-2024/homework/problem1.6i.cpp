#include <iostream>
#include <cmath>
using namespace std;

int main() {

  int x, a, b, c;
  cin >> x >> a >> b >> c;

  cout << (x!=(max(max(a, b), c))) << endl;

  return 0;
}
