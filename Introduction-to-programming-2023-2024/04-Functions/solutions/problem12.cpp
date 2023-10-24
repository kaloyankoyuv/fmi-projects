#include <iostream>
using namespace std;

bool isLeap(int year) {
  if ((year % 4 == 0 && year % 100 != 0) || (year % 400)) {
    return true;
  }
  return false;
}

void livedFor(int a, int b, int c, int d, int e, int f) {
  int leapYears = 0;
  int x = a;
  for (int i = x; i < d; i++) {
    if (isLeap(i)) {
      leapYears++;
    }
  }

  int years = d - a - leapYears;
  int months = (years + leapYears) * 12;
  int days = years * 365 + leapYears * 366;

  cout << years+leapYears << endl;
  cout << months << endl;
  cout << days << endl;
}

int main() {

  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;

  livedFor(a, b, c, d, e, f);

  return 0;
}
