#include <fstream>
#include <iostream>

class Set {
public:
  virtual Set *clone() const = 0;
  virtual ~Set() = default;
  virtual void write(std::ostream &out) const = 0;
  virtual void read(std::istream &in) = 0;
  virtual bool member(int x) const = 0;
};

class Singleton : public Set {
private:
  unsigned int x;

public:
  Singleton(unsigned int _x) : x(_x) {}
  Set *clone() const { return new Singleton(*this); }
  void write(std::ostream &out) const { out << "Singleton " << x << "\n"; }
  void read(std::istream &in) { in >> this->x; }
  bool member(int x) const { return this->x == x; }
};

class EmptySet : public Set {
public:
  Set *clone() const { return new EmptySet(*this); }
  void write(std::ostream &out) const { out << "EmptySet\n"; }
  void read(std::istream &in) { return; }
  bool member(int x) const { return false; }
};

class EvenInts : public Set {
public:
  Set *clone() const { return new EvenInts(*this); }
  void write(std::ostream &out) const { out << "EvenInts\n"; }
  void read(std::istream &in) { return; }
  bool member(int x) const { return x % 2 == 0; }
};

class SetUnion : public Set {
private:
  Set *A;
  Set *B;

public:
  SetUnion() = default;
  SetUnion(Set *_A, Set *_B) {
    this->A = _A->clone();
    this->B = _B->clone();
  }
  SetUnion(const SetUnion &other) {
    this->A = other.A->clone();
    this->B = other.B->clone();
  }
  ~SetUnion() {
    delete this->A;
    delete this->B;
    std::cout << "deleted SetUnion\n";
  }
  SetUnion &operator=(const SetUnion &other) {
    if (this != &other) {
      delete this->A;
      delete this->B;
      this->A = other.A->clone();
      this->B = other.B->clone();
    }
    return *this;
  }
  Set *clone() const { return new SetUnion(this->A, this->B); }
  void write(std::ostream &out) const {
    out << "SetUnion\n";
    A->write(out);
    B->write(out);
  }
  void read(std::istream &in) {
    delete this->A;
    delete this->B;
    std::string type;
    in >> type;
    this->A = setFactory(type);
    if (this->A != nullptr)
      this->A->read(in);
    in >> type;
    this->B = setFactory(type);
    if (this->B != nullptr)
      this->B->read(in);
  }
  bool member(int x) const { return A->member(x) || B->member(x); }

  Set *setFactory(const std::string &type) {
    if (type == "Singleton") {
      return new Singleton(0);
    } else if (type == "EmptySet") {
      return new EmptySet;
    } else if (type == "EvenInts") {
      return new EvenInts;
    } else if (type == "SetUnion") {
      return new SetUnion;
    }
    return nullptr;
  }
};

int main() {

  std::ifstream input_file("sets.txt");

  Set *s8 = new SetUnion;
  s8->read(input_file);
  s8->write(std::cout);
  delete s8;

  return 0;
}
