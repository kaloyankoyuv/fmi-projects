#include <iostream>

void swapElements(int *a, int *b, int n) {
  for(int i = 0; i<n; i++) {
    std::swap(a[i], b[i]);
  }
}

int main() {

  int n;
  std::cin >> n;

  int a[20];
  int b[20];

  for(int i = 0; i<n; i++) {
    std::cin >> a[i];
  }

  for(int i = 0; i<n; i++) {
    std::cin >> b[i];
  }

  swapElements(a, b, n);
  
  for(int i = 0; i<n; i++) {
    std::cout << a[i] << " ";
  }

  for(int i = 0; i<n; i++) {
    std::cout << b[i] << " ";
  }

  

  return 0;
}
