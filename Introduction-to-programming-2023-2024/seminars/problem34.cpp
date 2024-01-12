#include <iostream>

int main() {

  int n;
  std::cin >> n;

  double *arr = new double[2 * n];

  for (int i = 0; i < 2 * n; i++) {
    std::cin >> arr[i];
  }

  int minX = arr[0];

  for (int i = 1; i < n; i++) {
    if (arr[i] < minX) {
      minX = arr[i];
    }
  }

  int minY = arr[n];

  for (int i = n + 1; i < 2 * n; i++) {
    if (arr[i] < minY) {
      minY = arr[i];
    }
  }

  int maxX = arr[0];

  for (int i = 1; i < n; i++) {
    if (arr[i] > maxX) {
      maxX = arr[i];
    }
  }

  int maxY = arr[n];

  for (int i = n + 1; i < 2 * n; i++) {
    if (arr[i] > maxY) {
      maxY = arr[i];
    }
  }

  std::cout << minX << " " << maxY << std::endl;
  std::cout << "x: " << maxX - minX << std::endl;
  std::cout << "y: " << maxY - minY << std::endl;

  return 0;
}
