#include <iostream>

double inc(double x) {
  return x+1;
}
double sq(double x) {
  return x*x;
}

double fmax(double (*f)(double), double (*g)(double), double x) {

  return std::max(f(x), g(x));
  
}

int main() {

  std::cout << fmax(inc, sq,2);
  
  return 0;
}
