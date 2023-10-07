#include <iostream>
using namespace std;

int main() {

  cout << "Enter year: ";

  int year;
  cin >> year;

  bool isLeap = ((year%4==0 && year%100!=0) || year%400==0);

  if (isLeap) {
    cout << "Year " << year << " is a leap year" << endl;
  } else {
    cout << "Year " << year << " is not a leap year" << endl;
  }

  return 0;
}
