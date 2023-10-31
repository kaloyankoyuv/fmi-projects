#include <iostream>

int main() {

  int arr[1024];
  int n;
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }

  for (int i = 0; i < n / 2; i++) {
    int x = arr[i];
    arr[i] = arr[n - 1 - i];
    arr[n - 1 - i] = x;
  }

  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }

  std::cout << std::endl;
  return 0;
}
