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

  template <typename R>
  friend std::ostream &operator<<(std::ostream &out, const LList<R> &ll);

  int get_size() { return this->size; }

  T get_ith(T n) {
    box<T> *crr = this->first;
    for (int i = 0; i < n; i++) {
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
      box<T> *newBox = new box<T>{x, this->first};
      this->first = newBox;
      this->size++;
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
      box<T> *save = this->first->next;
      delete this->first;
      this->first = save;
      this->size--;
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

  void removeAll(const T &x) { //needs fixing

    box<T> *cur = this->first;
    box<T> *prev = this->first;
    while (cur != nullptr) {
      if(this->first->data == x) {
	pop();
      } else {
	if (cur->data == x) {
	  box<T> *save = cur->next;
	  delete cur;
	  prev->next = save;
	  cur = save;
	  this->size--;
	} else {
	  prev = cur;
	  cur = cur->next;
	}
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
