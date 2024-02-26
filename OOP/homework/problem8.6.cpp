#include <iostream>

double sq(double x) { return x * x; }

double cube(double x) { return x * x * x; }

double inc(double x) { return x + 1; }

double fmax(double (*f)(double), double (*g)(double), double x) {

  return std::max(f(x), g(x));
}

double maxarray(double (*arr[])(double), int n, double x) {

  double max = arr[0](x);

  for (int i = 1; i < n; i++) {
    if (arr[i](x) > max) {
      max = arr[i](x);
    }
  }

  return max;
}

double maxarray2(double (*arr[])(double), int n, double x) {
  if (n == 1) {
    return arr[0](x);
  }

  if (n == 2) {
    return fmax(arr[0], arr[1], x);
  }

  return std::max(arr[n - 1](x), maxarray2(arr, n - 1, x));
}

double maxarray3(double (*arr[])(double), int n, double x) {

  double max = arr[0](x);
  for (int i = 1; i < n-1; i++) {
    if (max < fmax(arr[i], arr[i + 1], x)) {
      max = fmax(arr[i], arr[i + 1], x);
    }
  }
  return max;
}

int main() {

  double (*arr[])(double) = {sq, cube, inc};
  std::cout << maxarray3(arr, 3, 1);

  return 0;
}
