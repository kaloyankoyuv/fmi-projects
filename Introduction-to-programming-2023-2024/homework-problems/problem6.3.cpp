#include <iostream>

struct Product {
  char description[32];

  int partNum;

  double cost;
};

int main() {

  Product prods[5];

  for(int i = 0; i<5; i++) {

    for(int j = 0; j<32; j++) {
      prods[i].description[j] = 0;
    }

    prods[i].partNum = 0;
    prods[i].cost = 0;
  }

  for(int i = 0; i<5; i++) {

    std::cout << prods[i].description << std::endl;
      
    std::cout << prods[i].partNum << std::endl;
    std::cout << prods[i].cost << std::endl;
  }


  for(int i = 0; i<5; i++) {

    std::cin >> prods[i].description;
      
    std::cin >> prods[i].partNum;
    std::cin >> prods[i].cost;
  }

  for(int i = 0; i<5; i++) {

    std::cout << prods[i].description << std::endl;
      
    std::cout << prods[i].partNum << std::endl;
    std::cout << prods[i].cost << std::endl;
  }

  return 0;
}
