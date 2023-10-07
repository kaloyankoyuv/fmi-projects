#include <iostream>
#include <cmath>
using namespace std;

int main() {

  int n, k; 
  cin >> n >> k;

  for (k; n>1 && n%k==0; n/=k);

  if (n==1) 
    cout << 1 << endl;
  else
    cout << 0 << endl;
    
  return 0;
}
