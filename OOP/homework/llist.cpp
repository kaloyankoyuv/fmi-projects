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
      previous->next = new box{other_cur->data, nullptr};
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

  template <typename R>
  friend std::ostream &operator<<(std::ostream &out, const LList<R> &ll);

  int get_size() { return this->size; }

  void push(const T &x) {
    this->first = new box<T>{x, first};
    this->size++;
  }

  void pop() {
    box<T> *save = this->first->next;
    delete this->first;
    this->first = save;
    this->size--;
  }

  void insertAt(int index, const T &x) {
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
  
  void deleteAt(int index) { // doesnt work for index=0
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
};

template <typename R>
std::ostream &operator<<(std::ostream &out, const LList<R> &ll) {
  box<R> *cur = ll.first;
  out << "{";
  while (cur != nullptr) {
    out << " " << cur->data;
    cur = cur->next;
  }
  out << " }";
  return out;
}
