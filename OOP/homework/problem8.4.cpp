#include <iostream>

double inc(double x) { return x + 1; }

double id(double x) { return x; }

double mult(double x) { return x * 2; }

double sq(double x) { return x * x; }

double cube(double x) { return x * x * x; }

int main() {

  double (*arr[])(double) = {inc, id, mult, sq, cube};

  int x;
  std::cin >> x;
  int max = 0;
  for (int i = 1; i < 5; i++) {
    if (arr[i](x) > arr[max](x)) {
      max = i;
    }
  }
  std::cout << max;

  return 0;
}
