#include <iostream>

bool isSedlovaTochka(int element, int i, int j, int matrix[20][30], int n,
                     int m) {

  bool isMin = true;
  for (int x = 0; x < m; x++) {
    if (element > matrix[i][x]) {
      isMin = false;
      break;
    }
  }

  bool isMax = true;
  for (int x = 0; x < n; x++) {
    if (element < matrix[x][j]) {
      isMax = false;
      break;
    }
  }

  return isMin && isMax;
}

int main() {

  int n, m;
  std::cin >> n >> m;

  int a[20][30];

  for (int i = 0; i < n; i++) {

    for (int j = 0; j < m; j++) {
      std::cin >> a[i][j];
    }
  }

  for (int i = 0; i < n; i++) {

    for (int j = 0; j < m; j++) {
      if (isSedlovaTochka(a[i][j], i, j, a, n, m)) {
        std::cout << a[i][j] << ' ';
      }
    }
  }

  return 0;
}
