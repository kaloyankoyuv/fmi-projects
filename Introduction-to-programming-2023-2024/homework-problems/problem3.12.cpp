#include <iostream>

int myStrlen(char s[]) {
  int counter = 0;
  while (s[counter] != 0) {
    counter++;
  }
  return counter;
}

void reverse(char s[]) { // abcde edcba

  int len = myStrlen(s);

  for (int i = 0; i < len / 2; i++) {
    char x = s[i];
    s[i] = s[len - 1 - i];
    s[len - 1 - i] = x;
  }
}

int main() {

  char s[255];
  std::cin >> s;

  reverse(s);

  std::cout << s << std::endl;

  return 0;
}
