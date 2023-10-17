#include <iostream>
using namespace std;

int main() {

  int n;
  cin >> n;

  int result = 1;

  if (n == 0) {
    cout << result << endl;
    return 0;
  } else {
    while (n != 1) {
      result *= n;
      n--;
    }
  }

  cout << result << endl;

  return 0;
}
