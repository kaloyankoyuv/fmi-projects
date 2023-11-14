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
    int sum = 0;
    for(int j=0; j<n; j++) {
      sum+=M[j][i];
    }
    std::cout << i << ':' << sum << ' ';
  }
  

  return 0;
}
