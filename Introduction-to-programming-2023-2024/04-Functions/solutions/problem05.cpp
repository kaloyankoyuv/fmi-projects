#include <iostream>
using namespace std;

bool isEven(int a) {
  if (a%2==0) {
    return true;
  }
  return false;
}

int main() {

  int a;
  cin >> a;

  cout << isEven(a) << endl;
  
  return 0;
}
