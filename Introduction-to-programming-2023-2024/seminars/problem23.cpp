#include <iostream>

int main() {

  int matrix[10][15];

  int n, m;
  std::cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> matrix[i][j];
    }
  }

  int sums[15];
  int sum;
  for (int j = 0; j < m; j++) {
    sum = 0;
    for (int i = 0; i < n; i++) {
      sum += matrix[i][j];
    }
    sums[j] = sum;
  }

  for (int i = 0; i < m; i++) {
    for (int j = i + 1; j < m; j++) {
      if (sums[i] == sums[j]) {
        std::cout << "Yes";
        return 0;
      }
    }
  }

  std::cout << "No";

  return 0;
}
