#include <iostream>
using namespace std;

int main() {

  int n;
  cin >> n;
  int num[n];

  for (int i = 0; i < n; i++) {
    cin >> num[i];
  }

  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (num[i] % 2 == 0 && (num[i] / 2) % 2 != 0) {
      sum += num[i];
    }
  }

  cout << sum << endl;

  return 0;
}
