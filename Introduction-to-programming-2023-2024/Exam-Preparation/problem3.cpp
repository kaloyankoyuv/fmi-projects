#include <iostream>

struct Cat {
  char *name;
  int age;
};

void greet(Cat whisker) {
  std::cout << "name: " << whisker.name << std::endl << "age: " << whisker.age;
}

int main() {

  Cat whisker;

  char name[255];
  std::cin >> name;
  whisker.name = name;
  std::cin >> whisker.age;

  greet(whisker);

  return 0;
}
