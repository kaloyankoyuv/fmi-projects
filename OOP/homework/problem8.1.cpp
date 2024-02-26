#include <iostream>

template <typename T> void input(T *arr, int n) {
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
}

int main() {

  int arr[20];
  int n;
  std::cin >> n;
  input<int>(arr, n);
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }

  return 0;
}
