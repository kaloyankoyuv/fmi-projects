#include <iostream>
using namespace std;

int main() {

  int age, time, price;
  cin >> age >> time;

  if (age >=0 && age <=12) {
    if (time < 17) {
      price = 9;
    } else {
      price = 14;
    }
  } else if (age >=13 && age <=64) {
    if (time < 17) {
      price = 13;
    } else {
      price = 15;
    }
  } else {
    if (time < 17) {
      price = 10;
    } else {
      price = 13;
    }
  }

  cout << price << endl;

  return 0;
}
