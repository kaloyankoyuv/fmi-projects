#include <iostream>
using namespace std;

int main() {

  int num1, num2; // 12 8
  cin >> num1 >> num2;

  int min;
  
  if (num1 >= num2) {
    min = num2;
  }  else {
    min = num1;
  }

  while(!(num1%min==0 && num2%min==0)) {
    min--;
  }

  cout << min << endl;
  
  return 0;
}
