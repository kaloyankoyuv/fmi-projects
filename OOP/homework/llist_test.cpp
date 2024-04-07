#include "llist.cpp"
#include <iostream>

int main() {
  LList<int> l1;
  l1.push(4);
  l1.push(7);
  l1.push(9);
  l1.push(3);
  l1.push(5);

  LList<int> l2;
  l2.push(2);
  l2.push(8);
  l2.push(6);
  l2.push(1);

  std::cout << l1 << std::endl;
  std::cout << l2 << std::endl;
  
  return 0;
}
