#include <iostream>

bool is_prefix(char* str1, char* str2) {
  return str1[0] == str2[0];
}

int main() {

  int n1, n2;
  std::cin >> n1 >> n2;

  char* s1 = new char[n1];
  char* s2 = new char[n2];

  std::cin >> s1 >> s2;

  std::cout << is_prefix(s1, s2) << std::endl;

  delete [] s1;
  delete [] s2;

  return 0;
}
