#include <iostream>
using namespace std;

int main() {

  int n, m; // 2 4         2*2*2*2
  cin >> n >> m;

  int x = n;
  while (m>1) {
    n=n*x;
    m--;
  }

  cout << n << endl;

  return 0;
}
