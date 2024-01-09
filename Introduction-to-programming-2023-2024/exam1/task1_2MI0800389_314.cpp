#include <iostream>

int findMin(int *a, int n) {

  int *b = new int[n];

  for (int i = 0; i < n; i++) {
    b[i] = 0;
  }

  if (a[0] != 1) {
    b[0] = 1;
  } else {
    b[0] = a[0] + 1;
  }

  for (int i = 1; i < n; i++) {
    while (b[i] <= b[i - 1] || b[i] == a[i]) {
      b[i]++;
    }
  }

  int result = b[n - 1];

  delete[] b;

  return result;
}

int main() {

  int n;
  std::cin >> n;

  int *a = new int[n];

  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  std::cout << findMin(a, n);

  std::cout << std::endl;

  delete[] a;

  return 0;
}
