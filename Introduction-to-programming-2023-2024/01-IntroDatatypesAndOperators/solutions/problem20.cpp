#include <iostream>
using namespace std;

int main() {
  int a;
  cin >> a;

  int firstNum = a /1000;
  int secondNum = (a/100)%10;
  int thirdNum = (a/10)%10;
  int forthNum = a % 10;

  cout << (firstNum == forthNum && secondNum == thirdNum);
}
