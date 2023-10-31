#include <iostream>

int main() {

  int arr[255];
  int n;
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }

  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }

  std::cout << sum / n << std::endl;

  return 0;
}
