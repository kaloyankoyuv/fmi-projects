#include <iostream>
using namespace std;

int main() {
  int x;
  cin >> x; // 123

  int a = x % 10;
  x /=10;
  int b = x % 10;
  int c = x / 10;
  cout << a << b << c;

  // or:
  // int num;
  // cin >> num; //123
  // cout << num % 10; //3
  // num /= 10;
  // cout << num % 10; //2
  // num /= 10;
  // cout << num % 10; //1
}
