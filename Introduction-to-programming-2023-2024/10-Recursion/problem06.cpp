#include <iostream>

void reverseStr(char *str, int n, int i = 0) {

  if (i > n / 2 -1) {
    return;
  }

  char temp = str[i];
  str[i] = str[n - 1 - i];
  str[n - 1 - i] = temp;
  reverseStr(str, n, i + 1);
}

int main() {

  int n;
  std::cin >> n;
  char *str = new char[n];
  std::cin >> str;
  reverseStr(str, n);
  std::cout << str;

  delete[] str;

  return 0;
}
