#include <iostream>

int main() {

  int n;
  std::cin >> n;
  int a[50];
  int b[50];

  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  for (int i = 0; i < n; i++) {
    std::cin >> b[i];
  }

  int counter = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i] == b[j]) {
        counter++;
      }
    }
  }

  std::cout << counter;

  return 0;
}
