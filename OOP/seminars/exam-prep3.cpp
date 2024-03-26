#include <iostream>

class Vector {

private:
  double arr[20];
  int size;

public:
  Vector() {
    this->arr[0] = 0;
    size = 1;
  }

  Vector(double *_arr, int _size) {
    for (int i = 0; i < _size; i++) {
      this->arr[i] = _arr[i];
    }
    this->size = _size;
  }

  double operator[](int index) const { return this->arr[index]; }

  Vector operator+(double x) {
    if (this->size == 20) {
      return *this;
    }
    Vector result;
    result.size = this->size + 1;
    result.arr[this->size] = x;
    return result;
  }

  Vector &operator+=(double x) {
    if (this->size == 20) {
      return *this;
    }
    this->arr[this->size] = x;
    this->size += 1;
    return *this;
  }

  bool operator<(const Vector &other) {
    double length1 = 0;
    for (int i = 0; i < this->size; i++) {
      length1 += this->arr[i] * this->arr[i];
    }
    double length2 = 0;
    for (int i = 0; i < other.size; i++) {
      length2 += other.arr[i] * other.arr[i];
    }
    return length1 < length2;
  }

  bool operator==(const Vector &other) {
    double length1 = 0;
    for (int i = 0; i < this->size; i++) {
      length1 += this->arr[i] * this->arr[i];
    }
    double length2 = 0;
    for (int i = 0; i < other.size; i++) {
      length2 += other.arr[i] * other.arr[i];
    }
    return length1 == length2;
  }

  int get_size() const { return this->size; }
};

class Sequence {

private:
  double *arr;
  int size;

public:
  Sequence() {
    this->arr = new double[0];
    this->size = 0;
  }

  Sequence(double *_arr, int _size) {
    this->arr = new double[_size];
    for (int i = 0; i < _size; i++) {
      this->arr[i] = _arr[i];
    }
    this->size = _size;
  }

  Sequence(const Sequence &other) {
    this->arr = new double[other.size];
    for (int i = 0; i < other.size; i++) {
      this->arr[i] = other.arr[i];
    }
    this->size = other.size;
  }

  ~Sequence() { delete[] this->arr; }

  Sequence &operator=(const Sequence &other) {
    if (this != &other) {
      delete[] this->arr;
      this->arr = new double[other.size];
      for (int i = 0; i < other.size; i++) {
        this->arr[i] = other.arr[i];
      }
      this->size = other.size;
    }
    return *this;
  }

  double *get_arr() const { return this->arr; }

  int get_size() const { return this->size; }

  void addVector(const Vector &v) {
    double *newArr = new double[this->size + v.get_size()];
    for (int i = 0; i < this->size; i++) {
      newArr[i] = this->arr[i];
    }
    for (int i = 0; i < v.get_size(); i++) {
      newArr[i + this->size] = v[i];
    }
    delete[] this->arr;
    this->arr = newArr;
    this->size += v.get_size();
  }
};

std::ostream &operator<<(std::ostream &out, const Sequence &s) {
  for (int i = 0; i < s.get_size(); i++) {
    out << s.get_arr()[i] << " ";
  }
  return out;
}

int main() {

  double arr1[] = {1, 2, 3, 4};
  double arr2[] = {1, 2, 3};

  Vector v1(arr1, 4);
  Vector v2(arr2, 3);

  v2 += 4;
  v2 + 4;

  std::cout << (v1 == v2) << v1[2];

  Sequence s1(arr1, 4);
  s1.addVector(v2);
  std::cout << s1;

  return 0;
}
