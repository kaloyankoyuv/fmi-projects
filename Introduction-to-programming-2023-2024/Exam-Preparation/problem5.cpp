#include <iostream>

void mySort(int *arr, int n) {

  int num0 = 0;
  int num1 = 0;
  int num2 = 0;

  for (int i = 0; i < n; i++) {
    if (arr[i] == 0) {
      num0++;
    } else if (arr[i] == 1) {
      num1++;
    } else if (arr[i] == 2) {
      num2++;
    }
  }

  int k = 0;
  for (int i = 0; i < num0; i++) {
    arr[k] = 0;
    k++;
  }
  for (int i = 0; i < num1; i++) {
    arr[k] = 1;
    k++;
  }
  for (int i = 0; i < num2; i++) {
    arr[k] = 2;
    k++;
  }
}
  

int main() {

  int n;
  std::cin >> n;

  int *arr = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }  

  mySort(arr, n);

  for (int i = 0; i < n; i++) {
    std::cout << arr[i];
  } 

  return 0;
}
