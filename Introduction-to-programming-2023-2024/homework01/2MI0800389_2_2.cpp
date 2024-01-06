#include <iostream>

int log2(int x) {

  int result = 0;

  while (x > 0) {
    result++;
    x /= 2;
  }

  return result;
}

int pow2(int x) {

  int result = 1;

  for (int i = 0; i < x; i++) {
    result *= 2;
  }

  return result;
}

bool isBitInPosXOn(int num, int pos) { return num & (1 << pos); }

int main() {

  int n;
  std::cin >> n;

  int *data = new int[n];

  for (int i = 0; i < n; i++) {
    std::cin >> data[i];
  }

  int result = 0;

  for (int i = 0; i < log2(n); i++) {

    int sum = 0;

    for (int j = 0; j < n; j++) {
      if (isBitInPosXOn(j, i)) {
        sum += data[j];
      }
    }

    if (sum % 2 != 0) {
      result += pow2(i);
    }
  }

  std::cout << "Hacker is in room: " << result << std::endl;

  delete[] data;

  return 0;
}
