#include <iostream>

int pow(int num, int power) {

  if (power == 0) {
    return 1;
  }
  if (power == 1) {
    return num;
  }

  return num * pow(num, power - 1);
}

int myStrLen(char *s) {

  int result = 0;

  while (s[result] != 0) {
    result++;
  }

  return result;
}

int convertCharToInt(char c) { return int(c - 48); }

int convertToInt(char *s) {

  int result = 0;

  int str_len = myStrLen(s);

  for (int i = 0; i < str_len; i++) {
    result += convertCharToInt(s[i]) * pow(10, str_len - i - 1);
  }
  return result;
}

bool leq(char *n1, char *n2) { return convertToInt(n1) <= convertToInt(n2); }

int main() {

  int n1, n2;
  std::cin >> n1 >> n2;

  char *s1 = new char[n1];
  char *s2 = new char[n2];

  std::cin >> s1;

  std::cin >> s2;

  std::cout << leq(s1, s2);

  return 0;
}
