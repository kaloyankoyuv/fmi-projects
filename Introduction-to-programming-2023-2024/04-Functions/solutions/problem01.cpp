#include <iostream>
using namespace std;

int sumOfTwoNumbers(int a, int b) {
  return a+b;
}

int main() {
  
  int a, b;
  cin >> a >> b;
  cout << sumOfTwoNumbers(a, b) << endl;;
  
  return 0;
}
