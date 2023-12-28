#include <iostream>
using namespace std;

int main() {

  int n;
  cin >> n;

  int num[n];
  for (int i = 0; i < n; i++) {
    cin >> num[i];
  }

  bool b = false;
  for (int i = 1; i < n; i++) {
    if (num[i] == num[i - 1]) {
      b = true;
      break;
    }
  }

  cout << b << endl;

  return 0;
}
