#include <iostream>

void strManip(char s[]) {

  int numberC = 0;
  int numberL = 0;

  int i = 0;
  while (s[i] != 0) {

    if (s[i] >= 'a' && s[i] <= 'z') {
      numberL++;
    } else if (s[i] >= 'A' && s[i] <= 'Z') {
      numberC++;
    }
    i++;
  }

  i = 0;
  if (numberL > numberC) {
    while (s[i] != 0) {
      if (s[i] >= 'A' && s[i] <= 'Z') {
        s[i] += 'a' - 'A';
      }

      i++;
    }
  } else {
    while (s[i] != 0) {
      if (s[i] >= 'a' && s[i] <= 'z') {
        s[i] -= 'a' - 'A';
      }
      i++;
    }
  }
}

int main() {

  char s[255];
  std::cin >> s;

  strManip(s);
  std::cout << s << std::endl;

  return 0;
}
