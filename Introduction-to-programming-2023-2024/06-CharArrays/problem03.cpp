#include <iostream>

void replaceFirstOccurance(char *s, char c1, char c2) {

  int i=0;
  while (s[i] != 0) {
    if (s[i] == c1) {
      s[i] = c2;
      return;
    }
    i++;
  }
}

int main() {

  int maxSize = 256;
  char s[maxSize];

  std::cin.getline(s, maxSize);

  replaceFirstOccurance(s, 'a', 'b');
  
  std::cout << s << std::endl;

  return 0;
}
