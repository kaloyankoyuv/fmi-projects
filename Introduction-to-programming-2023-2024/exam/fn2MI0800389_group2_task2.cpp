#include <iostream>

unsigned long countSums(long *arr1, long *arr2, long *arr3, int n) {

  int counter = 0;
  for (int i = 0; i < n; i++) {

    for (int j = 0; j < n; j++) {

      for (int k = 0; k < n; k++) {

        if ((arr1[i] == arr2[j] + arr3[k]) || (arr2[j] == arr1[i] + arr3[k]) ||
            (arr3[k] == arr1[i] + arr2[j])) {
          counter++;
        }
      }
    }
  }

  return counter;
}

int main() {

  int n;
  std::cin >> n;

  long arr1[10];
  long arr2[10];
  long arr3[10];

  for (int i = 0; i < n; i++) {
    std::cin >> arr1[i];
  }

  for (int i = 0; i < n; i++) {
    std::cin >> arr2[i];
  }

  for (int i = 0; i < n; i++) {
    std::cin >> arr3[i];
  }

  std::cout << countSums(arr1, arr2, arr3, n);

  return 0;
}
