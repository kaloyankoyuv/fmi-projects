#include <iostream>

int myStrlen(char *str) {

  int result = 0;
  while (*str != 0) {
    str++;
    result++;
  }
  return result;
}

void myStrcat(char *str1, char *str2) {

  char *str3 = new char[myStrlen(str1) + myStrlen(str2)];

  while (*str1 != 0) {
    *str3 = *str1;
    str1++;
    str3++;
  }
  
  while (*str2 != 0) {
    *str3 = *str2;
    str2++;
    str3++;
  }

  str1 = str3;
}

int main() {

  int n1;
  std::cin >> n1;

  char *str1 = new char[n1];
  for (int i = 0; i < n1; i++) {
    std::cin >> str1[i];
  }

  int n2;
  std::cin >> n2;

  char *str2 = new char[n2];
  for (int i = 0; i < n2; i++) {
    std::cin >> str2[i];
  }

  myStrcat(str1, str2);
  while (*str1 != 0) {
    std::cout << *str1;
    str1++;
  }

  return 0;
}
