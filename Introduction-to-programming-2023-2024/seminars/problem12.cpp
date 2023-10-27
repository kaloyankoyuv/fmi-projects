#include <iostream>

void swap(int arr[], int n) {
  for (int i = 0; i < n - 1; i += 2) {
    int x = arr[i];
    arr[i] = arr[i + 1];
    arr[i + 1] = x;
  }
}

int main() {
  int n;
  std::cin >> n;

  int arr[100];
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }

  swap(arr, n);

  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << ' ';
  }

  std::cout << std::endl;

  return 0;
}
