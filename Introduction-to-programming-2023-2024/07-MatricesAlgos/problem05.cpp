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

  int Mt[100][100];
  for(int i=0; i<m; i++) {
    for(int j=0; j<n; j++) {
      Mt[i][j] = M[j][i];
    }
  }
  
  for(int i=0; i<m; i++) {
    for(int j=0; j<n; j++) {
      std::cout << Mt[i][j] << ' ';
    }
    std::cout << std::endl;
  }
  

  return 0;
}
