#include <iostream>
using namespace std;

int main() {

  int x;
  cin >> x;

  cout << ((x/100<(x/10)%10 && (x/10)%10 < x%10) || (x/100>(x/10)%10 && (x/10)%10 > x%10)) << endl;

  return 0;
}
