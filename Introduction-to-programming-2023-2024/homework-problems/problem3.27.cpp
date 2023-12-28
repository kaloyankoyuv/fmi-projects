#include <iostream>

void bubbleSortRow(int a[30][30], int n, int m, int i) {

  for (int k = 0; k < m; k++) {
    for (int j = 0; j < m - 1; j++) {
      if (a[i][j] > a[i][j + 1]) {
        std::swap(a[i][j], a[i][j + 1]);
      }
    }
  }
}

void bubbleSortCol(int a[30][30], int n, int m, int j) {

  for (int i = 0; i < n; i++) {
    for (int k = 0; k < n - 1; k++) {
      if (a[k][j] > a[k + 1][j]) {
        std::swap(a[k][j], a[k + 1][j]);
      }
    }
  }
}

void sortRows(int a[30][30], int n, int m) {

  for (int i = 0; i < n; i++) {

    bubbleSortRow(a, n, m, i);
  }
}

void sortCols(int a[30][30], int n, int m) {

  for (int j = 0; j < n; j++) {

    bubbleSortCol(a, n, m, j);
  }
}

int main() {

  int n, m;
  std::cin >> n >> m;

  int a[30][30];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> a[i][j];
    }
  }

  sortRows(a, n, m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cout << a[i][j] << " ";
    }
    std::cout << std::endl;
  }

  std::cout << std::endl;
  
  sortCols(a, n, m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cout << a[i][j] << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
