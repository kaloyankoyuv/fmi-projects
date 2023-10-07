#include <iostream>
#include <cmath>
using namespace std;

int main() {

  int n;
  cin >> n;

  int result = 0;

  for (int i=1; i<=n; i++) {
    int num = pow(i, 3) + 13*i*n + pow(n, 3);
    if(num%5==0 || num%9==0) {
      result++;
    }
  }
  cout << result << endl;

  return 0;
}
