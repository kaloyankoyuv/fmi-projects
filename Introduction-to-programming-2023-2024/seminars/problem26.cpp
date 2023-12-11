#include <iostream>

bool checkRow(int matrix[10][15], int n, int m, int i) {

  for (int x = 0; x < m-1; x++) {

    if (matrix[i][x] > matrix[i][x+1]) {
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

  int counter = 0;

  for(int i = 0; i<n; i++) {
    if(checkRow(matrix, n, m, i)){
      counter++;
    }
  }

  std::cout << counter;

  return 0;
}
