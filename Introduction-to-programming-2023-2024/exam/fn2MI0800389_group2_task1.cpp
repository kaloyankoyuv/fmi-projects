#include <iostream>

bool checkRow(float matrix[5][10], int n, int m, int i, int k) {

  if (i == k) {
    return false;
  }

  float l = matrix[i][0] / matrix[k][0];
  for (int x = 1; x < m; x++) {
    if (matrix[i][x] / matrix[k][x] != l) {
      return false;
    }
  }

  return true;
}

int main() {

  float matrix[5][10];
  int n = 2;
  int m = 3;

  for (int i = 0; i < n; i++) {

    for (int j = 0; j < m; j++) {

      std::cin >> matrix[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int k = 0; k < n; k++)
      if (checkRow(matrix, n, m, i, k)) {
        std::cout << "yes" << std::endl;
        return 0;
      }
  }

  std::cout << "no" << std::endl;

  return 0;
}
