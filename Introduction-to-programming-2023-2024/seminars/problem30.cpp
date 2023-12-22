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

bool checkForRowWinPlayerNumberX(int **matrix, int n, int m, int i,
                                 int playerNumber) {
  for (int j = 0; j < m; j++) {
    if (matrix[i][j] != playerNumber) {
      return false;
    }
  }

  return true;
}

bool checkForColWinPlayerNumberX(int **matrix, int n, int m, int i,
                                 int playerNumber) {
  for (int j = 0; j < m; j++) {
    if (matrix[j][i] != playerNumber) {
      return false;
    }
  }

  return true;
}

bool checkForLeftDiagonalWinPlayerNumberX(int **matrix, int n, int m,
                                          int playerNumber) {
  for (int i = 0; i < n; i++) {
    if (matrix[i][i] != playerNumber) {
      return false;
    }
  }
  return true;
}

bool checkForRightDiagonalWinPlayerNumberX(int **matrix, int n, int m,
                                           int playerNumber) {
  for (int i = 0; i < n; i++) {
    if (matrix[i][m - i - 1] != playerNumber) {
      return false;
    }
  }
  return true;
}

int checkForWinPlayerNumberX(int **matrix, int n, int m, int playerNumber) {

  for (int i = 0; i < n; i++) {
    if (checkForRowWinPlayerNumberX(matrix, n, m, i, playerNumber)) {
      return playerNumber;
    }
  }

  for (int i = 0; i < n; i++) {
    if (checkForColWinPlayerNumberX(matrix, n, m, i, playerNumber)) {
      return playerNumber;
    }
  }

  if (checkForLeftDiagonalWinPlayerNumberX(matrix, n, m, playerNumber)) {
    return playerNumber;
  }

  if (checkForRightDiagonalWinPlayerNumberX(matrix, n, m, playerNumber)) {
    return playerNumber;
  }

  return 0;
}

bool checkForDraw(int **matrix, int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (matrix[i][j] == 0) {
        return false;
      }
    }
  }

  return true;
}

void TicTacToe(int **matrix, int n, int m) {

  printMatrix(matrix, n, m);

  while (true) {

    if (checkForDraw(matrix, n, m)) {
      std::cout << "Draw" << std::endl;
      return;
    }

    int x, y;

    std::cin >> x >> y;
    matrix[x][y] = 1;

    printMatrix(matrix, n, m);

    std::cin >> x >> y;
    matrix[x][y] = 2;

    printMatrix(matrix, n, m);

    if (checkForWinPlayerNumberX(matrix, n, m, 1) == 1) {
      std::cout << "Player 1 has won" << std::endl;
      return;
    }

    if (checkForWinPlayerNumberX(matrix, n, m, 2) == 2) {
      std::cout << "Player 2 has won" << std::endl;
      return;
    }
  }
}

int main() {

  int n, m;
  std::cin >> n >> m;

  int **matrix = createMatrix(n, m);
  TicTacToe(matrix, n, m);

  deleteMatrix(matrix, n);

  return 0;
}
