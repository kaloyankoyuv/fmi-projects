#include <iostream>
using namespace std;

int main() {

  int x;
  cin >> x; // 19

  int leapYears = x/4;
  int normalYears = x - leapYears;

  int days = (leapYears*366) + (normalYears*365);
  int hours = days*24;
  int minutes = hours*60;
  int sec = minutes*60;

  cout << "Days: " << days << endl;
  cout << "Hours: " << hours << endl;
  cout << "Minutes: " << minutes << endl;
  cout << "Seconds: " << sec << endl;
  
  return 0;
}
