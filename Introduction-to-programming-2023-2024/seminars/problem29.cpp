#include <iostream>

int **createMatrix(int n, int m) {

  int **matrix = new int *[n];

  for (int i = 0; i < n; i++) {
    matrix[i] = new int[m];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      matrix[i][j] = 0;
    }
  }

  return matrix;
}

void deleteMatrix(int **matrix, int n) {

  for (int i = 0; i < n; i++) {
    delete[] matrix[i];
  }

  delete[] matrix;
}

void printMatrix(int **matrix, int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cout << matrix[i][j] << ' ';
    }
    std::cout << std::endl;
  }
}

void cinMatrix(int **matrix, int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> matrix[i][j];
    }
  }
}

int **enlargeMatrix(int **matrix, int &n, int &m) {

  int oldN = n;

  n = (n * 2) + 1;
  m = (m * 2) + 1;

  int **newMatrix = createMatrix(n, m);

  for (int i = 1; i < n; i += 2) {
    for (int j = 1; j < m; j += 2) {
      newMatrix[i][j] = matrix[i / 2][j / 2];
    }
  }

  deleteMatrix(matrix, oldN);

  return newMatrix;
}

int **zoomMatrix(int **matrix, int &n, int &m, int iter) {

  while (iter--) {

    matrix = enlargeMatrix(matrix, n, m);

    for (int i = 1; i < n; i += 2) {
      for (int j = 1; j < m; j += 2) {

        matrix[i][j - 1] += matrix[i][j] / 2;
        matrix[i][j + 1] += matrix[i][j] / 2;
        matrix[i - 1][j] += matrix[i][j] / 2;
        matrix[i + 1][j] += matrix[i][j] / 2;
      }
    }
  }

  return matrix;
}

int main() {

  int n, m;
  std::cin >> n >> m;

  int **matrix = createMatrix(n, m);

  cinMatrix(matrix, n, m);

  std::cout << std::endl;

  int k;
  std::cin >> k;
  std::cout << std::endl;

  matrix = zoomMatrix(matrix, n, m, k);

  printMatrix(matrix, n, m);

  deleteMatrix(matrix, n);

  return 0;
}
