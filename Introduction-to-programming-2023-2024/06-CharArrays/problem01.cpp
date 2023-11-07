#include <iostream>

int main() {

  int maxSize = 256;

  char s[maxSize];
  std::cin.getline(s, maxSize);

  int counter = 0;
  while(s[counter] != 0) {
    std::cout << s[counter] << std::endl;
    counter++;
  }

  return 0;
}
