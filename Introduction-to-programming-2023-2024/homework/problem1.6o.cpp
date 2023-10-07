#include <iostream>
using namespace std;

int main() {

  int m;
  cin >> m;

  cout << (m/100==(m/10)%10 || m/100==m%10 || (m/10)%10==m%10) << endl;

  return 0;
}
