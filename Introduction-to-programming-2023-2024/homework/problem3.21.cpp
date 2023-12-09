#include <iostream>

int arrPeriod(int *arr, int n) {

  int period = 0;

  for (int i = 1; i < n; i++) {

    bool hasPeriod = true;
    for (int j = 0; j < n - i; j++) {
      if (arr[j] != arr[j + i]) {
        hasPeriod = false;
        break;
      }
    }
    if (hasPeriod) {
      period = i;
      break;
    }
  }

  return period;
}

int main() {

  int n;
  std::cin >> n;

  int arr[255];
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }

  std::cout << arrPeriod(arr, n);

  return 0;
}
