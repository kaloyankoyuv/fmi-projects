#include <iostream>

int main() {

  int n;
  std::cin >> n;

  int m[50][50];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> m[i][j];
    }
  }

  int sum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (m[i][j] % 2 != 0) {
        sum += m[i][j];
      }
    }
  }

  std::cout << sum;

  return 0;
}
