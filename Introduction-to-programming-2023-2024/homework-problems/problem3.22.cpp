#include <iostream>

int matrix_mult(int a[20][30], int b[30][20], int n, int m, int i, int j) {

  int result = 0;
  for (int k = 0; k < m; k++) {
    result += a[i][k] * b[k][j];
  }
  return result;
}

int main() {

  int n, m;
  std::cin >> n >> m;

  int a[20][30];
  int b[30][20];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> a[i][j];
    }
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> b[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << matrix_mult(a, b, n, m, i, j) << ' ';

    }
    std::cout << std::endl;
  }

  return 0;
}
