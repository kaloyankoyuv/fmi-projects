#include <iostream>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int first = max(a, b);
  cout << max(first, c);
}
