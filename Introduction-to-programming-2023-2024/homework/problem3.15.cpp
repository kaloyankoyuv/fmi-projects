#include <iostream>

int myStrLength(char *s) {

  int counter = 0;
  while (s[counter] != 0) {
    counter++;
  }

  return counter;
}

int numOfMatches(char *s1, char *s2, int i) {

  int s2_len = myStrLength(s2);
  int counter = 0;

  for (int j = 0; j < s2_len; j++) {
    if (s1[j + i] == s2[j]) {
      counter++;
    }
  }

  return counter;
}

bool isSubstring(char *s1, char *s2) {

  int s1_len = myStrLength(s1);
  int s2_len = myStrLength(s2);

  for (int i = 0; i < s1_len; i++) {

    if (numOfMatches(s1, s2, i) == s2_len) {
      return true;
    }
  }
  return false;
}

int main() {

  char s1[] = "firefox";
  char s2[] = "fox";

  std::cout << isSubstring(s1, s2);

  return 0;
}
