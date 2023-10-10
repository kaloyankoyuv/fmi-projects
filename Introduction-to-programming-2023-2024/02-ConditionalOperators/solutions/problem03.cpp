#include <iostream>
using namespace std;

int main() {

  int result;
  cin >> result;

  if (result >= 90 && result <=100) {
    cout << 6 << endl;
  } else if (result >=80 && result <=89) {
    cout << 5 << endl;
  } else if (result >=70 && result <=79) {
    cout << 4 << endl;
  } else if (result >=60 && result <=69) {
    cout << 3 << endl;
  } else {
    cout << 2 << endl;
  }

  return 0;
}
