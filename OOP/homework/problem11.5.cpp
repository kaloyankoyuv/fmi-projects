#include <functional>
#include <iostream>

template <typename U, typename V>
std::function<V(U)> createfn(U *args, V *values, int n) {

  return [args, values, n](U x) -> V {
    int x_index;
    for (int i = 0; i < n; i++) {
      if (x == args[i]) {
        x_index = i;
        break;
      }
    }
    return values[x_index];
  };
}

int main() {

  int args[] = {34, 12, 45, 21, 3, 4};
  char values[] = {'a', 'g', 'j', 'f', 'r', 'i'};

  std::cout << createfn(args, values, 6)(21);

  return 0;
}
