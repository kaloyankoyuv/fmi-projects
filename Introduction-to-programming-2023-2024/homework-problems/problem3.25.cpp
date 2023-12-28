#include <iostream>

bool isSorted(int *a, int n) {
  for (int i = 0; i < n - 1; i++) {
    if (a[i] > a[i + 1]) {
      return false;
    }
  }
  return true;
}

void arrShift(int *a, int n) {
  int temp = a[0];
  for (int i = 0; i < n - 1; i++) {

    a[i] = a[i + 1];
  }
  a[n - 1] = temp;
}

bool isSwappable(int *a, int n) {

  for (int i = 0; i < n; i++) {
    if (isSorted(a, n)) {
      return true;
    } else {
      arrShift(a, n);
    }
  }
  return false;
}

bool isSwappable2(int *a, int n) {

  int counter = 0;
  for (int i = 0; i < n - 1; i++) {
    if (a[i] > a[i + 1]) {
      counter++;
    }
  }

  return (counter <= 1);
}

int main() {

  int a[20];
  int n;
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  std::cout << isSwappable2(a, n);

  return 0;
}
