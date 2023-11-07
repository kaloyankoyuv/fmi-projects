#include <iostream>

void manip(char *s) {

  int counter = 0;
  while (s[counter] != 0) {
    if (s[counter] >= 'a' && s[counter <= 'z']) {
      s[counter] -= 'a' - 'A';
    } else if (s[counter] >= 'A' && s[counter] <= 'Z') {
      s[counter] += 'a' - 'A';
    }
    counter++;
  }
}

int main() {

  char s[256];
  std::cin.getline(s, 256);

  manip(s);
  std::cout << s << std::endl;
  
  return 0;
}
