#include <iostream>
using namespace std;

int main() {

  int n;
  cin >> n;

  int result = 0;
  for (int i=2; i<=n; i+=3) {
    result+=i;
  }

  cout << result << endl;

  return 0;
}
