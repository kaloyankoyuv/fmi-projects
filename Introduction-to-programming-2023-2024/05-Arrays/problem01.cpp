#include <iostream>

int main() {

  int arr[5];

  for (int i = 0; i < 5; i++) {
    arr[i] = i + 1;
  }

  for (int i = 0; i < 5; i++) {
    std::cout << arr[i] << std::endl;
  }

  return 0;
}
