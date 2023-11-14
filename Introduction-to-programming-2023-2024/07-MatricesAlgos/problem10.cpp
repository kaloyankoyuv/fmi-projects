#include <iostream>

void bubbleSort(int *arr, int n) {

  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

int searchOnly(int *arr, int n) {

  bubbleSort(arr, n);

  if (arr[0] != arr[1]) {
    return arr[0];
  }
  if (arr[n - 1] != arr[n - 2]) {
    return arr[n - 1];
  }

  for (int i = 0; i < n - 1; i++) {

    if (arr[i] != arr[i + 1] && arr[i] != arr[i - 1]) {
      return arr[i];
    }
  }

  return 0;
}

int main() {

  int arr[100];
  int n;
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }

  std::cout << searchOnly(arr, n) << std::endl;

  return 0;
}
