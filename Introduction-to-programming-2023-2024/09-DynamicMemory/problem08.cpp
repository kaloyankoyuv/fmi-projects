#include <iostream>

bool isDuplicate(int x, int *arr, int n) {

  int count = 0;

  for (int i = 0; i < n; i++) {
    if (x == arr[i]) {
      count++;
    }
  }

  return count>1;
}

int countDuplicates(int *arr, int n) {

  int result = 0;

  for (int i = 0; i < n; i++) {
    if (isDuplicate(arr[i], arr, n)) {
      result++;
    }
  }

  return result;
}

// int *removeDuplicates(int *arr, int &n) { int result = new int[] }

int main() {

  int n;
  std::cin >> n;

  int *arr = new int[n];

  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }

  // arr = removeDuplicates(arr, n);

  std::cout << countDuplicates(arr, n);

  delete[] arr;

  return 0;
}
