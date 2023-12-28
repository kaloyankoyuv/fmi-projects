#include <iostream>
using namespace std;

int main() {

  int x, y;
  cin >> x >> y;

  cout << ((x/10)%10==(y/10)%10 && x/100==y%10 && x%10==y/100) << endl;

  return 0;
}
