#include <iostream>

void bubbleSort(int *arr, int n) {

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        std::swap(arr[j], arr[j + 1]);
      }
    }
  }
}

int *merge(int **arr, int numOfArrays, int *numOfElementsInArrays) {

  int sum = 0;
  for (int i = 0; i < numOfArrays; i++) {
    sum += numOfElementsInArrays[i];
  }

  int *result = new int[sum];

  int k = 0;

  for (int i = 0; i < numOfArrays; i++) {
    for (int j = 0; j < numOfElementsInArrays[i]; j++) {
      result[k] = arr[i][j];
      k++;
    }
  }

  bubbleSort(result, sum);

  return result;
}

int main() {

  int numOfArrays;
  std::cin >> numOfArrays;

  int *numOfElementsInArrays = new int[numOfArrays];

  for (int i = 0; i < numOfArrays; i++) {
    std::cin >> numOfElementsInArrays[i];
  }

  int **arr = new int *[numOfArrays];
  for (int i = 0; i < numOfArrays; i++) {
    arr[i] = new int[numOfElementsInArrays[i]];
  }

  for (int i = 0; i < numOfArrays; i++) {
    for (int j = 0; j < numOfElementsInArrays[i]; j++) {
      std::cin >> arr[i][j];
    }
  }

  int *result = merge(arr, numOfArrays, numOfElementsInArrays);

  int sum = 0;
  for (int i = 0; i < numOfArrays; i++) {
    sum += numOfElementsInArrays[i];
  }

  for (int i = 0; i < sum; i++) {
    std::cout << result[i] << " ";
  }

  std::cout << std::endl;

  delete[] numOfElementsInArrays;
  delete[] result;

  for (int i = 0; i < numOfArrays; i++) {
    delete[] arr[i];
  }

  delete[] arr;

  return 0;
}
