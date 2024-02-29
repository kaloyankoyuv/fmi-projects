#include <iostream>

const int MAX_SIZE = 1000000;

int pow(int number, int power) {
  int result = 1;
  while (power--) {
    result *= number;
  }
  return result;
}

class Number {
private:
  int number;
  int base;

public:
  Number(int n, int b) {
    this->number = n;
    this->base = b;
  }

  Number to_decimal() {
    int r = 0;
    int x = 0;
    int temp = this->number;
    while (temp > 0) {
      r += temp % 10 * pow(base, x);
      x++;
      temp /= 10;
    }
    Number result(r, 10);
    return result;
  }

  Number to_base(int target_base) {
    Number temp = this->to_decimal();
    int result_arr[MAX_SIZE];
    int index = 0;
    while (temp.number > 0) {
      result_arr[index] = temp.number % target_base;
      index++;
      temp.number /= target_base;
    }

    int r = 0;
    int t = 0;
    for (int i = 0; i <= index; i++) {
      r += result_arr[i] * pow(10, t);
      t++;
    }
    Number result(r, target_base);
    return result;
  }

  int get_number() {
    return this->number;
  }
};

int main() {

  Number n(24, 6);
  std::cout << n.get_number() << std::endl;
  std::cout << n.to_decimal().get_number() << std::endl;
  std::cout << n.to_base(5).get_number() << std::endl;

  return 0;
}
