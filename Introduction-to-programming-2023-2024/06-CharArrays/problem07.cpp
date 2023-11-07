#include <iostream>

int countOfVowels(char *s) {
  int i = 0;
  int counter = 0;
  while (s[i] != 0) {
    if (s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' ||
        s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' ||
        s[i] == 'u' || s[i] == 'U') {
      counter++;
    }
    i++;
  }
  return counter;
}

int main() {

  char s[256];
  std::cin.getline(s, 256);

  std::cout << countOfVowels(s) << std::endl;

  return 0;
}
