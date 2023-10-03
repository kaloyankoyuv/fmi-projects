#include <iostream>
using namespace std;

int main() {
  int x;
  cin >> x; // 293

  int sto = x / 100;
  x = x - sto*100;
  int petdeset = x / 50;
  x = x - petdeset*50;
  int dvadeset = x / 20;
  x = x - dvadeset*20;
  int pet = x / 5;
  x = x - pet*5;
  int dva = x / 2;
  x = x - dva*2;
  int edin = x / 1;

  cout << "sto: " << sto << endl;
  cout << "petdeset: " << petdeset << endl;
  cout << "dvadeset: " << dvadeset << endl;
  cout << "pet: " << pet << endl;
  cout << "dva: " << dva << endl;
  cout << "edin: " << edin << endl;  
  
}
