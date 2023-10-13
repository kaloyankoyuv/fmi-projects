#include <iostream>
using namespace std;

int main() {

  int n;
  cin >> n;

  int n1;
  cin >> n1;
  int min = n1;
  int max = n1;
  double sum = n1;
  int x;
  for (int i = 0; i < n - 1; i++) {
    cin >> x;
    sum += x;
    if (x > max) {
      max = x;
    }
    if (x < min) {
      min = x;
    }
  }

  cout << "Avg: " << sum / n << endl;
  cout << "Min: " << min << endl;
  cout << "Max: " << max << endl;

  return 0;
}
