#include <iostream>

struct S {
  int a;
  int b;
  int c;
};

template <typename T> void map(T *arr, int n, T (*f)(T)) {
  for (int i = 0; i < n; i++) {
    arr[i] = f(arr[i]);
  }
}

int main() {

  S e1;
  e1.a = 1;
  e1.b = 2;
  e1.c = 3;
  S e2;
  e2.a = 3;
  e2.b = 1;
  e2.c = 2;
  S e3;
  e3.a = 4;
  e3.b = 2;
  e3.c = 4;

  S A1[] = {e1, e2, e3};

  map<S>(A1, 3, [](S x) -> S {
    std::cout << x.a << ", " << x.b << ", " << x.c << std::endl;
    return x;
  });

  // S A2[5];
  // map<S>(A2, 5, [](S x)->S{
  //   std::cin >> x.a >> x.b >> x.c;
  //   return x;
  // });

  // map<S>(A2, 5, [](S x)->S{
  //   std::cout << x.a << ", " << x.b<< ", " << x.c << std::endl;
  //   return x;
  // });

  map<S>(A1, 3, [](S x) -> S {
    x.a++;
    return x;
  });

  map<S>(A1, 3, [](S x) -> S {
    std::swap(x.a, x.b);
    return x;
  });

  map<S>(A1, 3, [](S x) -> S {
    std::cout << x.a << ", " << x.b << ", " << x.c << std::endl;
    return x;
  });

  return 0;
}
