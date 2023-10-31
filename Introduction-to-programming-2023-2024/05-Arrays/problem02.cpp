#include <iostream>

int main() {

  int arr[10];
  for (int i = 0; i < 10; i++) {
    std::cin >> arr[i];
  }

  int sum = 0;
  for (int i = 0; i < 10; i++) {
    sum += arr[i];
  }

  std::cout << sum << std::endl;

  return 0;
}
