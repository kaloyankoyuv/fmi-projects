#include <iostream>

template <typename T> T print(T x) {
  std::cout << x << ", ";
  return x;
}

template <typename T> void map(T *arr, int n, T (*f)(T)) {
  for (int i = 0; i < n; i++) {
    arr[i] = f(arr[i]);
  }
}

int main() {

  int arr[] = {1, 2, 3, 4};

  map<int>(arr, 4, [](int x)->int{
    std::cout << x << ", ";
    return x;});

  return 0;
}
