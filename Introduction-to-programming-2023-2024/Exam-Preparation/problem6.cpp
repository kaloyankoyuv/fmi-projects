#include <iostream>

bool checkSubArray(int *arr1, int n, int *arr2, int m) {

  bool result = false;

  for (int i = 0; i < n - m + 1; i++) {

    bool b = true;
    for (int j = i; j < m; j++) {
      if (arr1[j] != arr2[j - i]) {
        b = false;
        break;
      }
    }
    if (b) {
      result = true;
      break;
    }
  }

  return result;
}

int main() {

  int n;
  std::cin >> n;

  int *arr1 = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> arr1[i];
  }

  int m;
  std::cin >> m;

  int *arr2 = new int[m];
  for (int i = 0; i < m; i++) {
    std::cin >> arr2[i];
  }

  std::cout << checkSubArray(arr1, n, arr2, m);
  delete[] arr1;
  delete[] arr2;

  return 0;
}
