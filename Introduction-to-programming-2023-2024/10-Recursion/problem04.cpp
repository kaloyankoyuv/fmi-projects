#include <iostream>

int sumOfElArr(int *arr, int n) { // 1 2 3

  if (n == 0) {
    return 0;
  }

  if (n == 1) {
    return arr[0];
  }

  return arr[n-1] + sumOfElArr(arr, n-1);
}

int main() {


  int n;
  std::cin >> n;
  int *arr = new int[n];

  for(int i=0; i<n; i++) {
    std::cin >> arr[i];
  }

  std::cout << sumOfElArr(arr, n);

  delete[] arr;

  return 0;
}
