#include <iostream>

int main() {

  int arr[1024];
  int n;
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }

  int mult = 1;
  for (int i = 1; i < n; i += 2) {
    mult *= arr[i];
  }
  
  std::cout << mult << std::endl;
  
  return 0;
}
