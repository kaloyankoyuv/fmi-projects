#include <iostream>

int stringLength(const char *str) {

  int result = 0;
  while (*(str + result) != 0) {
    result++;
  }
  return result;
}

int stringLength2(const char *str) {

  int result = 0;
  while (*str != 0) {
    str++;
    result++;
  }
  return result;
}

int main() {

  int n;
  std::cin >> n;

  char *str = new char[n];

  for(int i=0; i<n; i++) {
    std::cin >> str[i];
  }

  std::cout << stringLength(str) << std::endl;
  std::cout << stringLength2(str) << std::endl;

  delete[] str;

  return 0;
}
