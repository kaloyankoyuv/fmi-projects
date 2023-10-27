#include <iostream>

int positionOfFirstNegative(int n) {

  int x;
  int result = 1;
  while (n--) {
    std::cin >> x;
    if (x < 0) {
      break;
    }
    result++;
  }
  return result;
}

int main() {
  int n;
  std::cin >> n;

  std::cout << positionOfFirstNegative(n) << std::endl;

  return 0;
}
