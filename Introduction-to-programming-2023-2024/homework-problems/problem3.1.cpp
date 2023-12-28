#include <iostream>
using namespace std;

int main() {

  int n;
  cin >> n;
  int numbers[n];
  cin >> numbers[0];

  int min = numbers[0];
  for (int i = 1; i < n; i++) {
    cin >> numbers[i];
    if (numbers[i] < min)
      min = numbers[i];
  }

  cout << min << endl;

  return 0;
}
