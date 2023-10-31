#include <iostream>

int main() {

  int arr1[1024];
  int arr2[1024];

  int n1, n2;

  std::cin >> n1;
  std::cin >> n2;

  bool result = true;

  if (n1 == n2) {
    for (int i = 0; i < n1; i++) {
      std::cin >> arr1[i];
    }

    for (int i = 0; i < n2; i++) {
      std::cin >> arr2[i];
    }

    for (int i = 0; i < n2; i++) {
      if (arr1[i] != arr2[i]) {
        result = false;
        break;
      }
    }

  } else {
    result = false;
  }

  std::cout << result;  

  return 0;
}
