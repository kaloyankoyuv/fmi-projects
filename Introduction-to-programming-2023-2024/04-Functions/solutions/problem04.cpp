#include <iostream>
using namespace std;

int calcMax(int a, int b, int c) {
  int range_ab;
  int range_ac;
  int range_bc;

  if (a >= b) {
    range_ab = a - b;
  } else {
    range_ab = b - c;
  }

  if (a >= c) {
    range_ac = a - c;
  } else {
    range_ac = c - a;
  }

  if (b >= c) {
    range_bc = b - c;
  } else {
    range_bc = c - b;
  }

  if (range_ab >= range_ac && range_ab >= range_bc) {
    return range_ab - 1;
  } else if (range_ac >= range_ab && range_ac >= range_bc) {
    return range_ac - 1;
  } else {
    return range_bc - 1;
  }
}

int calcMin(int a, int b, int c) {
  int range_ab;
  int range_ac;
  int range_bc;

  if (a >= b) {
    range_ab = a - b;
  } else {
    range_ab = b - a;
  }

  if (a >= c) {
    range_ac = a - c;
  } else {
    range_ac = c - a;
  }

  if (b >= c) {
    range_bc = b - c;
  } else {
    range_bc = c - b;
  }

  if (range_ab <= range_ac && range_ab <= range_bc) {
    return range_ab - 1;
  } else if (range_ac <= range_ab && range_ac <= range_bc) {
    return range_ac - 1;
  } else {
    return range_bc - 1;
  }
}

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  cout << calcMax(a, b, c) << endl;
  cout << calcMin(a, b, c) << endl;

  return 0;
}
