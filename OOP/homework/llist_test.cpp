#include "llist.cpp"
#include <iostream>

int main() {
  LList<int> l1;
  l1.insertAt(0, 37);
  l1.insertAt(1, 1);
  l1.insertAt(2, 37);
  l1.insertAt(3, 37);
  l1.insertAt(4, 37);
  l1.insertAt(5, 1);
  std::cout << l1 << std::endl;
  l1.removeAll(37);
  std::cout << l1 << std::endl;


  return 0;
}
