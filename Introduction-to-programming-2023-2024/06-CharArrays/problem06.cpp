#include <iostream>

int length(char *s) {

  int counter = 0;
  while (s[counter]!=0) {
    counter++;
  }
  return counter;
}

bool isPalindrom(char *s) {


  for (int i = 0; i<length(s)/2; i++) {
    if (s[i]!=s[length(s)-1-i]) {
      return false;
    }
  }
  return true;
}

int main() {

  int maxSize = 256;
  char s[maxSize];

  std::cin.getline(s, maxSize);

  std::cout << isPalindrom(s) << std::endl;

  return 0;
}
