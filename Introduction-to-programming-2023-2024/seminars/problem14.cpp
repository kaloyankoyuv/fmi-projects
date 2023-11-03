#include <iostream>

int compare(char *str1, char *str2) {

  int counter = 0;

  while (str1[counter] != 0 || str2[counter] != 0) {

    if (str1[counter] > str2[counter]) {
      return 1;
    } else if (str1[counter] < str2[counter]) {
      return -1;
    }

    counter++;
  }

  return 0;
}

int main() {

  int n1;
  std::cin >> n1;

  int n2;
  std::cin >> n2;

  char *s1 = new char[n1];
  char *s2 = new char[n2];

  std::cin >> s1 >> s2;

  std::cout << compare(s1, s2) << std::endl;
  
  delete [] s1;
  delete [] s2;
  
  return 0;
}
