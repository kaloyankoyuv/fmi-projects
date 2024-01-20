#include <iostream>

int myStrLen(char *str) {
  int result = 0;
  while (str[result] != 0) {
    result++;
  }
  return result;
}

char *findLargest(char *str) {

  int start = 0;
  int max = 1;
  for (int i = 0; i < myStrLen(str); i++) {

    int count = 1;
    char temp = str[i];
    for (int j = i + 1; j < myStrLen(str); j++) {
      if (str[j] > temp) {
        count++;
        temp = str[j];
      }
    }

    if (count > max) {
      max = count;
      start = i;
    }
  }

  char *result = new char[max];
  int k = 1;
  result[0] = str[start];

  char temp = str[start];
  for(int i = start+1; i<myStrLen(str); i++) {
    if(str[i] > temp) {
      result[k] = str[i];
      k++;
      temp = str[i];
    }
  }

  return result;
}

int main() {

  int n;
  std::cin >> n;

  char *str = new char[n];

  std::cin >> str;

  char *result = findLargest(str);
  std::cout << result;
  delete[] str;
  delete[] result;

  return 0;
}
