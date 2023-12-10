#include <iostream>

void bubbleSort(int *a, int n) {

  for (int i = 0; i < n; i++) {

    for (int j = 0; j < n-1; j++) {
      
      if (a[j] > a[j+1]) {
        std::swap(a[j], a[j+1]);
      }
      
    }
    
  }
}

int main() {

  int arr[] = {4, 5, 3, 1, 2};

  bubbleSort(arr, 5);

  for (int i = 0; i < 5; i++) {
    std::cout << arr[i] << " ";
  }

  return 0;
}
