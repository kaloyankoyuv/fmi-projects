#include <iostream>

template <typename T> class BoundSet {
private:
  T *arr;
  int size;
  int max_size;

public:
  BoundSet(int _max_size) {
    this->arr = new T[_max_size];
    this->size = 0;
    this->max_size = _max_size;
  }

  BoundSet(T *_arr, int _size, int _max_size) {
    this->arr = new T[_max_size];
    this->size = _size;
    this->max_size = _max_size;
    for (int i = 0; i < _size; i++) {
      this->arr[i] = _arr[i];
    }
  }

  BoundSet(const BoundSet &other) {
    this->arr = new T[other.max_size];
    this->size = other.size;
    this->max_size = other.max_size;
    for (int i = 0; i < other.size; i++) {
      this->arr[i] = other.arr[i];
    }
  }

  ~BoundSet() { delete[] this->arr; }

  BoundSet &operator=(const BoundSet &other) {
    if (this != &other) {
      delete[] this->arr;
      this->arr = new T[other.max_size];
      this->size = other.size;
      this->max_size = other.max_size;
      for (int i = 0; i < other.size; i++) {
        this->arr[i] = other.arr[i];
      }
    }
    return *this;
  }

  BoundSet operator+(const BoundSet &other) { // doesn't work
    int num_of_uniq = 0;

    for (int i = 0; i < this->size; i++) {
      bool uniq = true;
      for (int j = 0; j < other.size; j++) {
        if (this->arr[i] == other.arr[j]) {
          uniq = false;
          break;
        }
      }
      if (uniq) {
        num_of_uniq++;
      }
    }

    BoundSet result(num_of_uniq);

    result.arr = new T[num_of_uniq];
    result.size = num_of_uniq;
    result.max_size = num_of_uniq;

    int k = 0;
    for (int i = 0; i < this->size; i++) {
      result.arr[k] = this->arr[i];
      k++;
    }

    for (int i = 0; i < other.size; i++) {
      bool uniq = true;
      for (int j = 0; j < this->size; j++) {
        if (other.arr[i] == this->arr[j]) {
          uniq = false;
          break;
        }
      }
      if (uniq) {
        result.arr[k] = other.arr[i];
        k++;
      }
    }

    return result;
  }

  int get_size() const { return this->size; }
  T *get_arr() const { return this->arr; }

  bool member(T x) {
    for (int i = 0; i < this->size; i++) {
      if (x == this->arr[i]) {
        return true;
      }
    }
    return false;
  }

  bool add(T x) {
    if (!(this->member(x)) && this->size < this->max_size) {
      this->arr[this->size] = x;
      this->size++;
      return true;
    }

    return false;
  }

  bool remove(T x) {
    if (this->member(x)) {

      int index = 0;
      while (this->arr[index] != x) {
        index++;
      }

      T *newArr = new T[this->max_size];
      int k = 0;
      for (int i = 0; i < this->size; i++) {
        if (i == index) {
          i++;
        }
        if (i != index) {
          newArr[k] = this->arr[i];
          k++;
        }
      }

      delete[] this->arr;
      this->arr = newArr;
      this->size--;

      return true;
    }
    return false;
  }
};

template <typename T>
std::ostream &operator<<(std::ostream &out, const BoundSet<T> &s) {
  for (int i = 0; i < s.get_size(); i++) {
    out << s.get_arr()[i] << " ";
  }
  return out;
}

int main() {

  int arr[] = {1, 2, 3, 4, 5, 6};
  int arr2[] = {1, 2, 8, 9};
  BoundSet<int> s1(arr, 6, 10);
  BoundSet<int> s2(arr2, 4, 10);
  s1.remove(5);
  s1.add(7);

  std::cout << (s1 + s2);

  return 0;
}
