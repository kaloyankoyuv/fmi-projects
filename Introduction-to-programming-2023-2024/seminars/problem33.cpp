#include <iostream>

bool is_saw(int *a, int n) {

  if (a[0] <= a[1]) {

    for (int i = 0; i < n - 1; i += 2) {
      if (a[i] > a[i + 1]) {
        return false;
      }
    }

    for (int i = 1; i < n - 1; i += 2) {
      if (a[i] < a[i + 1]) {
        return false;
      }
    }
  }

  if (a[0] >= a[1]) {

    for (int i = 0; i < n - 1; i += 2) {
      if (a[i] < a[i + 1]) {
        return false;
      }
    }

    for (int i = 1; i < n - 1; i += 2) {
      if (a[i] > a[i + 1]) {
        return false;
      }
    }
  }

  return true;
}

int main() {

  int n;
  std::cin >> n;

  int *a = new int[n];

  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  std::cout << is_saw(a, n);

  return 0;
}
