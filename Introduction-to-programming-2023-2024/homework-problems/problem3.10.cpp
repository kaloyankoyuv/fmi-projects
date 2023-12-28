#include <iostream>

int maxLenPrefix(char s1[], char s2[]) {
  int count = 0;
  while (s1[count] != 0 && s2[count] != 0 && s1[count] == s2[count]) {
    count++;
  }
  return count;
}

int main() {
  char s1[255], s2[255];
  std::cin >> s1 >> s2;

  std::cout << maxLenPrefix(s1, s2) << std::endl;

  return 0;
}
