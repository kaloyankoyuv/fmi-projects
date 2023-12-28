#include <iostream>
#include <ostream>

int myStrlen(char s[]) {
  int counter = 0;
  while (s[counter] != 0) {
    counter++;
  }
  return counter;
}

bool isPalindrom(char s[]) {
  int counter = 0;
  int len = myStrlen(s);
  for (int i = 0; i < len / 2; i++) {
    if (s[i] != s[len - 1 - i]) {
      return false;
    }
  }
  return true;
}

int main() {

  char s[255];
  std::cin >> s;

  std::cout << isPalindrom(s) << std::endl;

  return 0;
}
