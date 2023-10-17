#include <iostream>
using namespace std;

int main() {

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int x = i;
    while (x--) {
      cout << ' ';
    }
    for (int j = n; j > i; j--) {
      cout << '*';
    }
    cout << endl;
  }

  return 0;
}
