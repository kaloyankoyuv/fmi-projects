#include <iostream>

void resizeArray(int **orig, int size) {
  int *resized = new int[size * 2];
  for (int i = 0; i < size; i++)
    resized[i] = (*orig)[i];
  delete[] *orig;
  *orig = resized;
}

int main() {

  int n;
  std::cin >> n;

  int *arr = new int[n];

  int i = 0;
  int x = 1;
  while (x != 0) {

    std::cin >> x;
    arr[i] = x;
    i++;

    if (i > n) {
      int **parr = &arr; 
      resizeArray(parr, n);
      n *= 2;
    }
  }

  for (int k = 0; k <= i; k++) {
    std::cout << arr[k] << ' ';
  }

  delete[] arr;

  return 0;
}
