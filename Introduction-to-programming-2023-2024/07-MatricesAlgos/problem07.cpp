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

  int sum = 0;
  for(int i=0; i<m; i++) {
    for(int j=0; j<n; j++) {
      if(i == j) {
	sum+=M[i][j];
      }
    }
  }

  std::cout << sum << std::endl;

  return 0;
}
