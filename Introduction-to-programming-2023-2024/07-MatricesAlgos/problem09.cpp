#include <iostream>

int main() {

  int M1[100][100], M2[100][100];
  int m, n;
  std::cin >> m >> n;

  for(int i=0; i<m; i++) {
    for(int j=0; j<n; j++) {
      std::cin >> M1[i][j];
    }
  }

  for(int i=0; i<m; i++) {
    for(int j=0; j<n; j++) {
      std::cin >> M2[i][j];
    }
  }
  for(int i=0; i<m; i++) {
    for(int j=0; j<n; j++) {
      M1[i][j] = M1[i][j] + M2[i][j];
    }
  }

  for(int i=0; i<m; i++) {
    for(int j=0; j<n; j++) {
      std::cout << M1[i][j] << ' ';
    }
    std::cout << std::endl;
  }

  return 0;
}
