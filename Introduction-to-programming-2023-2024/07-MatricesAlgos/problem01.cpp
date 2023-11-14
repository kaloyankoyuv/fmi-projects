#include <iostream>

void getM(int M[100][100], int m, int n) {

  for(int i=0; i<m; i++) {
    for(int j=0; j<n; j++) {
      std::cin >> M[i][j];
    }
  }
  
};

int main() {

  int M[100][100];

  int m, n;
  std::cin >> m >> n;

  getM(M, n, m);

  for(int i=0; i<m; i++) {
    for(int j=0; j<n; j++) {
      std::cout << M[i][j] << ' ';
    }
    std::cout << std::endl;
  }  

  return 0;
}
