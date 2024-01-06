#include <iostream>

int *resizeArray(int *arr, int &size) {

  int oldSize = size;

  size++;

  int *result = new int[size];
  for (int i = 0; i < oldSize; i++) {
    result[i] = arr[i];
  }

  delete[] arr;
  
  return result;
}

int main() {

  int n;
  std::cin >> n;

  int *arr = new int[n];

  int x = 1;
  int i = 0;
  while (x != 0) {
    std::cin >> x;
    arr[i] = x;
    i++;

    if (i >= n) {
      arr = resizeArray(arr, n);
    }
  }

  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  
  std::cout << std::endl;

  return 0;
}
