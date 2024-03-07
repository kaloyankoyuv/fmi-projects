#include <iostream>

int myStrLen(char *s) {
  int result = 0;
  while (s[result] != 0) {
    result++;
  }
  return result;
}

class Person {

private:
  char *name;
  char gender;
  int age;

public:
  Person(char *n, char g, int a) {

    this->name = new char[myStrLen(n)];
    for (int i = 0; i < myStrLen(n); i++) {
      this->name[i] = n[i];
    }
    this->gender = g;
    this->age = a;
  }

  Person(const Person &other) {
    this->gender = other.gender;
    this->age = other.age;

    this->name = new char[myStrLen(other.name)];
    for (int i = 0; i < myStrLen(other.name); i++) {
      this->name[i] = other.name[i];
    }
  }

  ~Person() { delete[] this->name; }

  Person &operator=(const Person &other) {
    if (this != &other) {
      delete[] this->name;
      this->gender = other.gender;
      this->age = other.age;

      this->name = new char[myStrLen(other.name)];
      for (int i = 0; i < myStrLen(other.name); i++) {
        this->name[i] = other.name[i];
      }
    }
    return *this;
  }

  int get_age() const { return this->age; }
  char get_gender() const { return this->gender; }
  char *get_name() const { return this->name; }

  bool set_age(int age) {
    if (age >= 0 && age <= 150) {
      this->age = age;
      return true;
    }
    return false;
  }
  bool set_gender(char gender) {
    if (gender == 'm' || gender == 'f') {
      this->gender = gender;
      return true;
    }
    return false;
  }

  void set_name(char *name) {
    delete[] this->name;
    this->name = new char[myStrLen(name)];
    for (int i = 0; i < myStrLen(name); i++) {
      this->name[i] = name[i];
    }
  }
};

std::ostream &operator<<(std::ostream &out, const Person &p) {
  out << "name: " << p.get_name() << ", ";
  out << "gender: " << p.get_gender() << ", ";
  out << "age: " << p.get_age();
  return out;
}

template <typename T> class Queue {

private:
  T *arr;
  int size;

public:
  Queue<T>(T *a, int s) {
    this->arr = new T[s];
    for (int i = 0; i < s; i++) {
      this->arr[i] = a[i];
    }
    this->size = s;
  }

  Queue<T>(const Queue &other) {
    this->size = other.size;
    this->arr = new T[other.size];
    for (int i = 0; i < other.size; i++) {
      this->arr[i] = other.arr[i];
    }
  }

  ~Queue<T>() { delete[] this->arr; }

  Queue<T> &operator=(const Queue &other) {
    if (this != &other) {
      this->size = other.size;

      delete[] this->arr;
      this->arr = new T[other.size];
      for (int i = 0; i < other.size; i++) {
        this->arr[i] = other.arr[i];
      }
    }
    return *this;
  }

  void print() {
    std::cout << "elements: ";
    for (int i = 0; i < this->size - 1; i++) {
      std::cout << this->arr[i] << ", ";
    }
    std::cout << this->arr[this->size - 1];
    std::cout << std::endl;
    std::cout << "size: " << this->size;
    std::cout << std::endl;
  }

  void push(T x) {
    T *newArr = new T[this->size + 1];
    for (int i = 0; i < this->size; i++) {
      newArr[i] = this->arr[i];
    }
    newArr[this->size] = x;
    delete[] this->arr;
    this->arr = newArr;
    this->size = this->size + 1;
  }

  bool pop() {
    if (this->size > 0) {
      T *newArr = new T[this->size - 1];
      for (int i = 1; i < this->size; i++) {
        newArr[i - 1] = this->arr[i];
      }
      delete[] this->arr;
      this->arr = newArr;
      this->size = this->size - 1;
      return true;
    }
    return false;
  }

  T top() { return this->arr[0]; }
};

int main() {

  // Person p1("Kaloyan", 'm', 19);
  // std::cout << p1.get_name() << std::endl;
  // std::cout << p1.get_age() << std::endl;
  // std::cout << p1.get_gender() << std::endl;
  // p1.set_name("Kaloyan Koyuv");
  // p1.set_age(200);
  // p1.set_gender('l');
  // std::cout << p1.get_name() << std::endl;
  // std::cout << p1.get_age() << std::endl;
  // std::cout << p1.get_gender() << std::endl;

  // int arr[] = {1, 2, 3};
  // Queue<int> q1(arr, 3);
  // q1.print();
  // q1.push(8);
  // q1.print();
  // std::cout << q1.top() << std::endl;

  // q1.pop();
  // q1.print();

  // int arr[] = {1, 2, 3};
  // Queue<int> q1(arr, 3);
  // q1.print();
  // q1.pop();
  // q1.print();

  // std::cout << q1.bot();

  Person p1("Kaloyan", 'm', 19);
  Person p2("Georgi", 'm', 20);
  Person p3("Simona", 'f', 23);

  Person *persons[] = {&p1, &p2, &p3};

  Queue<Person *> q1(persons, 3);

  Person p4("Pesho", 'm', 10);
  q1.push(&p4);

  q1.print();

  q1.pop();
  q1.print();

  return 0;
}
