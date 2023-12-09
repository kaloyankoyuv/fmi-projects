#include <iostream>

int myStrLength(char *str) {

  int counter = 0;
  while (str[counter] != 0) {
    counter++;
  }

  return counter;
}

void myStrSort(char *str) {
  int str_size = myStrLength(str);
  
  for (int i = 0; i < str_size; i++) {
    
    for (int j = 0; j < str_size - 1; j++) {
      if (str[j] > str[j + 1]) {
        std::swap(str[j], str[j + 1]);
      }
    }
    
  }

  
}

int main() {

  char str1[255];
  std::cin >> str1;

  char str2[255];
  std::cin >> str2;

  myStrSort(str1);
  myStrSort(str2);

  int countOfDuplicates1 = 0;
  int countOfDuplicates2 = 0;
  
  int i = 0;
    
  while (str1[i] != 0) {

    if (str1[i] != str1[i + 1]) {
      countOfDuplicates1++;
    }
    i++;
  }

  i = 0;
  while (str2[i] != 0) {

    if (str2[i] != str2[i + 1]) {
      countOfDuplicates2++;
    }
    i++;
  }

  std::cout << (countOfDuplicates1 == countOfDuplicates2);

  return 0;
}
