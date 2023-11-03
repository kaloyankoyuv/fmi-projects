#include <iostream>

int len(char *str) {
  int counter = 0;
  while(str[counter]!=0) {
    counter++;
  }
  return counter;
}

int main() {

  int n;
  std::cin >> n;
  char *s = new char[n];
  std::cin >> s;

  std::cout << len(s) << std::endl;

  delete [] s;

  return 0;
}
