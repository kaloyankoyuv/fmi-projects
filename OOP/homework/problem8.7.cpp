#include <iostream>

struct S {
  int a;
  int b;
  int c;
};

bool compare_by_a(S el1, S el2) { return el1.a > el2.a; }
bool compare_by_b(S el1, S el2) { return el1.b > el2.b; }
bool compare_by_abc(S el1, S el2) {

  if (el1.a > el2.a) {
    return true;
  } else if (el1.a < el2.a) {
    return false;
  }

  if (el1.b > el2.b) {
    return true;
  } else if (el1.b < el2.b) {
    return false;
  }

  if (el1.c > el2.c) {
    return true;
  } else if (el1.c < el2.c) {
    return false;
  }

  return false;
}

void sort(S arr[], int n, bool (*compare)(S, S)) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1; j++) {
      if (compare(arr[j], arr[j + 1])) {
        std::swap(arr[j], arr[j + 1]);
      }
    }
  }
}

int main() {

  S el1;
  el1.a = 1;
  el1.b = 3;
  el1.c = 1;

  S el2;
  el2.a = 1;
  el2.b = 3;
  el2.c = 2;

  S el3;
  el3.a = 1;
  el3.b = 2;
  el3.c = 3;

  S el4;
  el4.a = 1;
  el4.b = 3;
  el4.c = 4;

  S el5;
  el5.a = 1;
  el5.b = 1;
  el5.c = 4;

  S arr[] = {el1, el2, el3, el4, el5};

  sort(arr, 5, compare_by_abc);
  for (int i = 0; i < 5; i++) {
    std::cout << arr[i].a << " " << arr[i].b << " " << arr[i].c << std::endl;
  }

  return 0;
}
