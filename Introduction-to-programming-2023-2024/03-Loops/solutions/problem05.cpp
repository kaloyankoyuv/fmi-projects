#include <iostream>
using namespace std;

int main() {

  double n;
  cin >> n;
  double sum = 0;
  int x;
  for(int i=0; i<n; i++) {
    cin >> x;
    sum+=x;
  }

  cout << sum/n << endl;
  
  return 0;
}
