#include <iostream>

class Statistics {

private:
  int numbers_num;
  int numbers_sum;
  int numbers_prod;
  int numbers_max;
  int numbers_average;

public:
  Statistics() {
    this->numbers_num = 0;
    this->numbers_sum = 0;
    this->numbers_prod = 0;
    this->numbers_max = 0;
    this->numbers_average = 0;
  }

  Statistics operator+(int x) {
    Statistics result = *this;
    result.numbers_num++;
    result.numbers_sum += x;
    result.numbers_prod *= x;
    if (x > result.numbers_max) {
      result.numbers_max = x;
    }
    result.numbers_average = (result.numbers_average + x) / result.numbers_num;

    return result;
  }

  Statistics &operator+=(int x) {
    this->numbers_num++;
    this->numbers_sum += x;
    this->numbers_prod *= x;
    if (x > this->numbers_max) {
      this->numbers_max = x;
    }
    this->numbers_average = (this->numbers_average + x) / this->numbers_num;
    return *this;
  }

  void add(int x) {
    this->numbers_num++;
    this->numbers_sum += x;
    this->numbers_prod *= x;
    if (x > this->numbers_max) {
      this->numbers_max = x;
    }
    this->numbers_average = (this->numbers_average + x) / this->numbers_num;
  }

  int num() { return numbers_num; }
  int sum() { return numbers_sum; }
  int prod() { return numbers_prod; }
  int max() { return numbers_max; }
  int average() { return numbers_average; }
};

int main() {

  Statistics s1;
  (s1 += 10) += 5; std::cout << s1.sum() << s1.max() ;

  s1+4;
  std::cout << s1.sum();

  s1+=4;
  std::cout << s1.sum();
  
  return 0;
}
