#include <iostream>

int main() {

  int arr[1024];
  int n;
  int num;
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }

  std::cin >> num;
  int result = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] == num)
      result++;
  }

  std::cout << result << std::endl;

  return 0;
}
