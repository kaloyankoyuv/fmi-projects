#include <iostream>

int main() {

  char s[256];
  std::cin.getline(s, 256);

  int i = 0;
  while (s[i] != 0) {
    if (s[i] != ' ') {
      std::cout << s[i];
    }
    i++;
  }
  std::cout << std::endl;

  return 0;
}
