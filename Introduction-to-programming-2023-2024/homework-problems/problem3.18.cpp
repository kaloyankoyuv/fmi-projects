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

  int counter_a = 0;
  int counter_b = 0;

  for (int i = 0; i < n; i++) {

    bool isInB = false;
    for (int j = 0; j < n; j++) {
      if (a[i] == b[j]) {
        isInB = true;
        break;
      }
    }

    if (isInB) {
      counter_a++;
    }
  }

  for (int i = 0; i < n; i++) {

    bool isInA = false;
    for (int j = 0; j < n; j++) {
      if (b[i] == a[j]) {
        isInA = true;
        break;
      }
    }

    if (isInA) {
      counter_b++;
    }
  }

  std::cout << (counter_a == counter_b);

  return 0;
}
