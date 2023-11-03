#include <iostream>

int len(char *str) {
  int counter = 0;
  while (str[counter] != 0) {
    counter++;
  }
  return counter;
}

char *concat(char *str1, char *str2) {

  int counter = 0;
  char *str3 = new char[len(str1) + len(str2) + 1];

  while (str1[counter] != 0) {
    str3[counter] = str1[counter];
    counter++;
  }

  counter = 0;
  while (str2[counter] != 0) {
    str3[counter + len(str1)] = str2[counter];
    counter++;
  }

  return str3;
}

int main() {

  int n1, n2;
  std::cin >> n1 >> n2;

  char *s1 = new char[n1];
  char *s2 = new char[n2];

  std::cin >> s1 >> s2;

  char* s3 = concat(s1, s2);
  std::cout << s3;
  
  delete[] s3;

  delete[] s1;
  delete[] s2;

  return 0;
}
