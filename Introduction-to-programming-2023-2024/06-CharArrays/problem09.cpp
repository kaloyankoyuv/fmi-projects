#include <iostream>

int length(char *s) {
  int i = 0;
  while (s[i] != 0) {
    i++;
  }
  return i;
}

void reverse(char *s) {

  for (int i = 0; i<length(s)/2; i++) {
    char x = s[i];
    s[i] = s[length(s)-1-i];
    s[length(s)-1-i] = x;
  }
}

int main() {

  char s[256];
  std::cin.getline(s, 256);

  reverse(s);
  std::cout << s << std::endl;
  

  return 0;
}
