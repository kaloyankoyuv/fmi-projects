#include <iostream>
using namespace std;

int main() {

  cout << "Enter balance and amount to withdraw" << endl;
  
  int balance, sum;
  cin >> balance >> sum;

  if (balance > sum && sum%10 == 0) {
    balance = balance - sum;
    cout << "Successful withdraw" << endl;
    cout << "New balance: " << balance << endl;
  } else {
    cout << "Unsuccessful withdraw (not enough money in balance)" << endl;
  }

  return 0;
}
