#include <iostream>
using namespace std;

int main() {

  char p[10];
  for (int i = 0; i < 10; i++) {
    cin >> p[i];
  }

  bool b = true;
  for (int i = 0; i < 10; i++) {
    if (!((p[i] >= '0' && p[i] <= '9') || (p[i] >= 'a' && p[i] <= 'z') ||
          (p[i] >= 'A' && p[i] <= 'Z'))) {
      b = false;
      break;
    }
  }

  cout << b << endl;

  return 0;
}
