#include <iostream>

int myStrLen(char *str) {

  int counter = 0;
  while (str[counter] != 0) {
    counter++;
  }

  return counter;
}

bool isPerm(char *S, char *candidate) {

  int Ssize = myStrLen(S);

  int counter;

  for (int i = 0; i < Ssize; i++) {

    counter = 0;
    for (int j = 0; j < Ssize; j++) {
      if (S[i] == candidate[j]) {
        counter++;
      }
    }
    if (counter == 0) {
      return false;
    }
  }
  return true;
}

void printPerm(char *S, int l, int r) {

  if (l == r) {
    std::cout << S << std::endl;
    return;
  }

  for(int i = l; i<=r; i++) {
    std::swap(S[l], S[i]);
    printPerm(S, l+1, r);
    std::swap(S[l], S[i]);
  }
  
}

int main() {

  char S[10];
  std::cin >> S;
  int n = myStrLen(S);

  printPerm(S, 0, n-1);

  return 0;
}
