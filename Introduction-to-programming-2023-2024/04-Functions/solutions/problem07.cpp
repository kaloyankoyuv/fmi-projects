#include <iostream>
using namespace std;

bool isPrime(int a) {

  if(a==2) {
    return true;
  }

  for (int i=2; i<a; i++){
    if(a%i==0) {
      return false;
    }
  }
  return true;
}

int main() {
  
  int a;
  cin >> a;

  cout << isPrime(a) << endl;
  

  return 0;
}
