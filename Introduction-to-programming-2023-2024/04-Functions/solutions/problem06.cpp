#include <iostream>
using namespace std;

bool hasAge(int a) {
  if (a>=18) {
    return true;
  }

  return false;
}

int main() {

  int a;
  cin >> a;
  cout << hasAge(a) << endl;
  
  return 0;
}
