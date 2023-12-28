#include <iostream>

void reverse(int n) {

  if (n==0) {
    return;
  }

  int num;
  std::cin >> num;

  reverse(n-1);
  
  std::cout << num << " ";
  
}

int main() {

  reverse(4);

  return 0;
}
