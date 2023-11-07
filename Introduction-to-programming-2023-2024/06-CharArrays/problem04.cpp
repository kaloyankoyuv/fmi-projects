#include <iostream>

bool isInString(char *s, char c) {

  int i = 0;
  while (s[i] != 0) {
    if (s[i] == c) {
      return true;
    }
    i++;
  }
  return false;
}

int main() {

  int maxSize = 256;

  char s[256];

  std::cin.getline(s, maxSize);

  std::cout << isInString(s, 'a') << std::endl;

  return 0;
}
