#include <iostream>

int length(char *s) {

  int i = 0;
  while (s[i] != 0) {
    i++;
  }
  return i;
}

int main() {

  int maxSize = 256;

  char s[maxSize];
  std::cin.getline(s, maxSize);

  std::cout << length(s) << std::endl;

  return 0;
}
