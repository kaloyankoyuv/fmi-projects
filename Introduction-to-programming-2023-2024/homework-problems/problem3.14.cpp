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

  char str[255];
  std::cin >> str;

  myStrSort(str);

  int i = 0;
  int counter = 1;
  while (str[i] != 0) {

    if (str[i] == str[i + 1]) {
      counter++;
    } else {
      std::cout << str[i] << ": " << counter << std::endl;
      counter = 1;
    }
    i++;
  }

  return 0;
}
