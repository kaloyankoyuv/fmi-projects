#include <iostream>

int main() {

  int M[100][100];
  int m, n;
  std::cin >> m >> n;

  for(int i=0; i<m; i++) {
    for(int j=0; j<n; j++) {
      std::cin >> M[i][j];
    }
  }

  for(int i=0; i<m; i++) {
    for(int j=0; j<n; j++) {
      if (j>i) {
	std::cout << M[i][j] << ' ';
      }
    }
    std::cout << std::endl;
  }


  return 0;
}
