#include <functional>
#include <iostream>

template <typename T> struct box {

  T data;
  box<T> *next;
};

template <typename T> class LList {
private:
  box<T> *first;
  int size;

  void clear() {
    box<T> *save = this->first;
    while (this->first != nullptr) {
      save = this->first->next;
      delete this->first;
      this->first = save;
    }
  }

  void copy(const LList<T> &other) {
    if (other.first == nullptr) {
      this->first = nullptr;
      return;
    }
    this->size = other.size;
    this->first = new box<T>{other.first->data, nullptr};
    box<T> *previous = this->first;
    box<T> *other_cur = other.first->next;
    while (other_cur != nullptr) {
      previous->next = new box<T>{other_cur->data, nullptr};
      other_cur = other_cur->next;
      previous = previous->next;
    }
  }

public:
  LList<T>() {
    this->first = nullptr;
    this->size = 0;
  }

  LList<T>(const LList<T> &other) { copy(other); }

  LList<T>(int x, int y) {
    this->first = new box<int>{x, nullptr};
    box<int> *cur = this->first;
    for (int i = x + 1; i <= y; i++) {
      cur->next = new box<int>{i, nullptr};
      cur = cur->next;
    }
    this->size = y - x + 1;
  }

  ~LList<T>() { clear(); }

  LList<T> &operator=(const LList<T> &other) {
    if (this != &other) {
      clear();
      copy(other);
    }
    return *this;
  }

  T &operator[](int index) {
    box<T> *crr = this->first;
    for (int i = 0; i < index; i++) {
      crr = crr->next;
    }
    return crr->data;
  }

  bool operator==(const LList<T> &other) const {
    if (this->size != other.size) {
      return false;
    }
    box<T> *cur = this->first;
    box<T> *other_cur = other.first;
    while (cur != nullptr && other_cur != nullptr &&
           cur->data == other.cur->data) {
      cur = cur->next;
      other_cur = other_cur->next;
    }
    return cur = nullptr;
  }

  LList<T> &operator+=(const T &x) {
    box<T> *cur = this->first;
    box<T> *prev = this->first;
    while (cur != nullptr) {
      prev = cur;
      cur = cur->next;
    }
    cur = new box<T>{x, nullptr};
    prev->next = cur;
    this->size++;
    return *this;
  }

  LList<T> &operator+=(LList<T> &other) {
    this->append(other);
    return *this;
  }

  LList<T> operator+(LList<T> &other) { return this->concat(other); }

  int get_size() { return this->size; }

  box<T> *get_first() { return this->first; }

  T get_ith(int index) {
    box<T> *crr = this->first;
    for (int i = 0; i < index; i++) {
      crr = crr->next;
    }
    return crr->data;
  }

  void push(const T &x) {
    this->first = new box<T>{x, this->first};
    this->size++;
  }

  void push_back(const T &x) {
    box<T> *cur = this->first;
    box<T> *prev = this->first;
    while (cur != nullptr) {
      prev = cur;
      cur = cur->next;
    }
    cur = new box<T>{x, nullptr};
    prev->next = cur;
    this->size++;
  }

  void pop() {
    box<T> *save = this->first->next;
    delete this->first;
    this->first = save;
    this->size--;
  }

  void insertAt(int index, const T &x) {
    if (index == 0) {
      push(x);
      return;
    }
    box<T> *cur = this->first;
    box<T> *prev = this->first;
    for (int i = 0; i < index; i++) {
      prev = cur;
      cur = cur->next;
    }
    box<T> *newBox = new box<T>{x, cur};
    prev->next = newBox;
    this->size++;
  }

  void deleteAt(int index) {
    if (index == 0) {
      pop();
      return;
    }
    box<T> *cur = this->first;
    box<T> *prev = this->first;
    for (int i = 0; i < index; i++) {
      prev = cur;
      cur = cur->next;
    }
    box<T> *save = cur->next;
    delete cur;
    prev->next = save;
    this->size--;
  }

  void removeAll(const T &x) {
    for (int i = 0; i < this->size; i++) {
      if ((*this)[i] == x) {
        deleteAt(i);
        i--;
      }
    }
  }

  int count(const T &x) {
    int result = 0;
    box<T> *cur = this->first;
    while (cur != nullptr) {
      if (cur->data == x) {
        result++;
      }
      cur = cur->next;
    }
    return result;
  }

  LList<T> &append(LList<T> &other) {
    for (int i = 0; i < other.size; i++) {
      this->push_back(other[i]);
    }
    return *this;
  }

  LList<T> concat(LList<T> &other) {
    LList<T> result(*this);
    result.append(other);
    return result;
  }

  void reverse() {
    for (int i = 0; i < this->size/2; i++) {
      std::swap((*this)[i], (*this)[this->size-i-1]);
    }
  }

  void map(std::function<T(T)> f) {
    for (int i = 0; i < this->size; i++) {
      (*this)[i] = f((*this)[i]);
    }
  }
};

template <typename T>
std::ostream &operator<<(std::ostream &out, LList<T> &ll) {
  box<T> *cur = ll.get_first();
  out << "{";
  while (cur != nullptr) {
    out << " " << cur->data;
    cur = cur->next;
  }
  out << " }";
  return out;
}
