#include <iostream>

template <typename T> bool ordered(T *arr, int n) {

  for (int i = 0; i < n - 1; i++) {
    if (arr[i] > arr[i + 1]) {
      return false;
    }
  }

  return true;
}

int main() {

  char arr[20];
  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
  std::cout << ordered<char>(arr, n);

  return 0;
}
