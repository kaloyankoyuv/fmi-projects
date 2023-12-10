#include <iostream>

void bubbleSort(int *a, int n) {

  for (int i = 0; i < n; i++) {

    for (int j = 0; j < n - 1; j++) {

      if (a[j] > a[j + 1]) {
        std::swap(a[j], a[j + 1]);
      }
    }
  }
}

int unsortedness(int *a, int n) {

  int b[20];
  for (int i = 0; i < n; i++) {
    b[i] = a[i];
  }

  bubbleSort(b, n);

  int result = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      result++;
    }
  }
  return result;
}

int main() {

  int a[20];
  int n;
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  std::cout << unsortedness(a, n);

  return 0;
}
