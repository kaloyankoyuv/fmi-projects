#include <iostream>
#include "llist.cpp"

int main() {
  LList<int> l1;
  l1.push(4);
  std::cout << l1 << std::endl;
  l1.push(5);
  std::cout << l1 << std::endl;
  l1.insertAt(1, 30);
  std::cout << l1 << std::endl;
  l1.push(6);
  std::cout << l1 << std::endl;
  l1.push(7);
  std::cout << l1 << std::endl;
  l1.insertAt(3, 40);
  std::cout << l1 << std::endl;
  l1.insertAt(2, 50);
  std::cout << l1 << std::endl;
}
