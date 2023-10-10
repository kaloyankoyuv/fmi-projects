#include <iostream>
using namespace std;

int main() {

  char option;
  cin >> option;

  double temp;
  cin >> temp;

  switch(option) {
  case 'C':
    cout << temp << endl << (temp - 32)*5/9;
    break;
  case 'F':
    cout << temp << endl << (temp*9/5) + 32;
    break;
  }
  
  return 0;
}
