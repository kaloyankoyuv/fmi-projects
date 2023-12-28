#include <iostream>
#include <ostream>

int main() {

  char s[255];
  std::cin >> s;

  int i = 0;
  while (s[i] != 0) {
    if (s[i] >= '0' && s[i] <= '9') {
      std::cout << s[i];
    }
    ++i;
  }
  i = 0;
  while (s[i] != 0) {
    if (s[i] >= 'a' && s[i] <= 'z') {
      std::cout << s[i];
    }
    ++i;
  }
  i=0;
  while (s[i] != 0) {
    if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))) {
      std::cout << s[i];
    }
    ++i;
  }
  return 0;
}
