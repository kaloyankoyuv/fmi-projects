#include <iostream>

int main() {

  int r1, c1, r2, c2;
  std::cin >> r1 >> c1 >> r2 >> c2;

  int **m1 = new int *[r1];

  for (int i = 0; i < r1; i++) {
    m1[i] = new int[c1];
    for (int j = 0; j < c1; j++) {
      std::cin >> m1[i][j];
    }
  }

  int **m2 = new int *[r1];

  for (int i = 0; i < r2; i++) {
    m2[i] = new int[c2];
    for (int j = 0; j < c2; j++) {
      std::cin >> m2[i][j];
    }
  }

  for (int i = 0; i < r1; i++) {
    for (int j = 0; j < c1; j++) {
      std::cout << m1[i][j] + m2[i][j] << ' ';
    }
    std::cout << std::endl;
  }

  for(int i = 0; i<r1; i++) {
    delete[] m1[i];
    delete[] m2[i];
  }

  delete[] m1;
  delete[] m2;

  return 0;
}
