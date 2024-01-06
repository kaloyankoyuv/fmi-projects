#include <iostream>

bool isInArr(int x, int *arr, int n) {

  for (int i = 0; i < n; i++) {
    if (x == arr[i]) {
      return true;
    }
  }

  return false;
}

int countCommon(int *arr1, int n, int *arr2, int m) {

  int result = 0;

  for (int i = 0; i < n; i++) {

    if (isInArr(arr1[i], arr2, m)) {
      result++;
    }
  }

  return result;
}

int *myIntersection(int *arr1, int n, int *arr2, int m, int &k) {

  int *result = new int[countCommon(arr1, n, arr2, m)];

  k = 0;

  for (int i = 0; i < n; i++) {

    if (isInArr(arr1[i], arr2, m)) {
      result[k] = arr1[i];
      k++;
    }
  }

  return result;
}

int main() {

  int n;
  std::cin >> n;

  int *arr1 = new int[n];

  int m;
  std::cin >> m;

  int *arr2 = new int[m];

  for (int i = 0; i < n; i++) {
    std::cin >> arr1[i];
  }

  for (int i = 0; i < m; i++) {
    std::cin >> arr2[i];
  }

  int k = 0;

  int *intersec = myIntersection(arr1, n, arr2, m, k);

  for (int i = 0; i < k; i++) {
    std::cout << intersec[i] << " ";
  }

  std::cout << std::endl;

  delete[] arr1;
  delete[] arr2;
  delete[] intersec;

  return 0;
}
