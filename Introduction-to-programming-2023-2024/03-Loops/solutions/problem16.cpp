#include <iostream>
using namespace std;

int main() {

  int n;
  cin >> n;

  int counter = 0;
  for (int i=2; i<n; i++) {
    if (n%i==0)
    counter++;
  }

  if (counter > 0) {
    cout << "Not Prime" << endl;
  } else {
    cout << "Prime" << endl;
  }
  
  return 0;
}
