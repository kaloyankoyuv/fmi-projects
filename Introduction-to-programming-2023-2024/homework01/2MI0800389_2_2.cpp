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

int findErrorIndexCol(int **matrix, int n, int m) {

  int result = 0;
  for(int i = 1; i<n; i+=2) {
    
  }
}

int findErrorIndexRow(int **matrix, int n, int m) {
  
}

int main() {

  int n;
  std::cin >> n;

  int **matrix = createMatrix(n / 16, 16);
  cinMatrix(matrix, n / 16, 16);

  std::cout << findErrorIndexRow(matrix, n/16, 16) << " " << findErrorIndexCol(matrix, n/16, 16);

  return 0;
}
