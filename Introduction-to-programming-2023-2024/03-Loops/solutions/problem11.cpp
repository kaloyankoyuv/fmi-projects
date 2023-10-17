#include <iostream>
using namespace std;

int main() {

  int randomNum = 78;

  int x;
  cin >> x;

  while (x!= randomNum) {
    cin >> x;
  }

  cout << "guessed" << endl;
  
  return 0;
}
