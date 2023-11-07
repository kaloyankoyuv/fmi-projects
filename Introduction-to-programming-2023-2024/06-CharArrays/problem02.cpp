#include <iostream>

int countLetters(char *s) {

  int i = 0;
  int counter = 0;
  while (s[i] != 0) {
    if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
      counter++;
    }
    i++;
  }
  return counter;
}

int main() {

  int maxSize = 256;
  char s[maxSize];

  std::cin.getline(s, maxSize);
  std::cout << countLetters(s) << std::endl;

  return 0;
}
