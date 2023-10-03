#include <iostream>
using namespace std;

int main() {
  int x;
  cin >> x;

  int a = x%10;
  x /= 10;
  int b = x%10;
  x /= 10;
  int c = x%10;
  x /= 10;
  int d = x;

  cout << a + b + c + d;
}
