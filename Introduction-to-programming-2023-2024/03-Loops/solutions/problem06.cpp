#include <iostream>
using namespace std;

int main() {

  int n;
  cin >> n;
  
  int a1 = 1;
  int a2 = 1;

  for(int i=0; i<n; i++) {
    cout << a1 + a2 << endl;
    int x = a1;
    a1 = a2;
    a2 = x + a2;
  }
  
  return 0;
}
