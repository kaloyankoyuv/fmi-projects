#include <iostream>

bool checkRows(int matrix[10][15], int n, int m, int i, int k) {

  if (i == k) {
    return false;
  }

  for (int x = 0; x < m; x++) {

    if (matrix[i][x] <= matrix[k][x]) {
      return false;
    }
  }
  return true;
}

int main() {

  int matrix[10][15];

  int n, m;
  std::cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> matrix[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int k = 0; k < n; k++) {
      if (checkRows(matrix, n, m, i, k)) {
        std::cout << "Yes";
        return 0;
      }
    }
  }

  std::cout << "No";

  return 0;
}
