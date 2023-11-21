#include <iostream>

int myStrlen(char *str) {
  
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
  for(int i = 0; i<n; i++) {
    std::cin >> str[i];
  }

  std::cout << myStrlen(str);
  delete[] str;

  return 0;
}
