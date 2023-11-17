#include <iostream>

void bubbleSwap(int *arr, int n, int i = 0) {

  if (i == n - 1) {
    return;
  }

  if (arr[i] > arr[i + 1]) {
    int temp = arr[i];
    arr[i] = arr[i + 1];
    arr[i + 1] = temp;
  }

  bubbleSwap(arr, n, i + 1);
}

void bubbleSort(int *arr, int n) {

  if (n == 1) {
    return;
  }

  bubbleSwap(arr, n);

  bubbleSort(arr, n - 1);
}

int main() {

  int arr[100];
  int n;
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }

  bubbleSort(arr, n);

  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << ' ';
  }

  std::cout << std::endl;

  return 0;
}
