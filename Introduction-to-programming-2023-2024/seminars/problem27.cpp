#include <cmath>
#include <iostream>

bool check(int S[20][2], int E[20][2], int i, int k, int K) {
  int x2x1 = E[k][0] - S[i][0];
  int y2y1 = E[k][1] - S[i][1];

  int d = sqrt((x2x1) * (x2x1) + (y2y1) * (y2y1));
  return d >= K;
}

int main() {

  int S[20][2];
  int E[20][2];

  int K;
  std::cin >> K;

  int n;
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      std::cin >> S[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      std::cin >> E[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int k = 0; k < n; k++) {
      if (check(S, E, i, k, K)) {
        std::cout << "(" << S[i][0] << ", " << S[i][1] << ")"
                  << " ";
        std::cout << "(" << E[k][0] << ", " << E[k][1] << ")" << std::endl;
      }
    }
  }

  return 0;
}
