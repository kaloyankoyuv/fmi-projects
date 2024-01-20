#include <iostream>

void fillColor(int x, int y, int newColor, int startColor, int **matrix, int n,
               int m) {

  if (x < 0 || x >= n || y < 0 || y >= m) {
    return;
  }

  if (matrix[x][y] != startColor) {
    return;
  }

  matrix[x][y] = newColor;
  fillColor(x + 1, y, newColor, startColor, matrix, n, m);
  fillColor(x - 1, y, newColor, startColor, matrix, n, m);
  fillColor(x, y + 1, newColor, startColor, matrix, n, m);
  fillColor(x, y - 1, newColor, startColor, matrix, n, m);
}

int main() {

  int x, y;
  std::cin >> x >> y;
  int color;
  std::cin >> color;

  int n, m;
  std::cin >> n >> m;

  int **matrix = new int *[n];
  for (int i = 0; i < n; i++) {
    matrix[i] = new int[m];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> matrix[i][j];
    }
  }

  int startColor = matrix[x][y];

  fillColor(x, y, color, startColor, matrix, n, m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }

  for (int i = 0; i < n; i++) {
    delete[] matrix[i];
  }
  delete[] matrix;

  return 0;
}
