#include <iostream>

template <typename T> bool member(T *arr, int n, T x) {

  for (int i = 0; i < n; i++) {
    if (arr[i] == x) {
      return true;
    }
  }
  return false;
}

int main() {

  int n;
  std::cin >> n;

  int *arr = new int[n];

  for(int i = 0; i<n; i++) {
    std::cin >> arr[i];
  }

  std::cout << member<int>(arr, n, 20);

  delete[] arr;
  
  return 0;
}
