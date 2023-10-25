#include <iostream>

void toUpperCase(char s[]) {

  int i = 0;
  while (s[i] != 0) {
    if (s[i] >= 'a' && s[i] <= 'z') {
      s[i] += 'A' - 'a';
    }
    ++i;
  }
}

int main() {

  char s[255];
  std::cin >> s;
  toUpperCase(s);

  std::cout << s;

  return 0;
}
