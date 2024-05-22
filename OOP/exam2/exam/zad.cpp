#include "zad.hpp"

Constant::Constant(double _x) : x(_x) {}

MathExpression *Constant::clone() const { return new Constant(*this); }

double Constant::value() const { return x; }

void Constant::print(std::ostream &out) const { out << this->x << ", "; }

Min::Min(MathExpression *_m1, MathExpression *_m2) {
  this->m1 = _m1->clone();
  this->m2 = _m2->clone();
}

Min::Min(const Min &other) {
  this->m1 = other.m1->clone();
  this->m2 = other.m2->clone();
}

Min::~Min() {
  delete m1;
  delete m2;
}

Min &Min::operator=(const Min &other) {
  if (this != &other) {
    delete this->m1;
    delete this->m2;
    this->m1 = other.m1->clone();
    this->m2 = other.m2->clone();
  }
  return *this;
}

MathExpression *Min::clone() const { return new Min(this->m1, this->m2); }

double Min::value() const {
  return std::min(this->m1->value(), this->m2->value());
}

void Min::print(std::ostream &out) const {
  out << "min(";
  this->m1->print(out);
  this->m2->print(out);
  out << "), ";
}

Sum::Sum(const Sum &other) {
  for (MathExpression *m : other.expressions) {
    this->addExpression(m);
  }
}

Sum::~Sum() {
  for (MathExpression *m : this->expressions) {
    delete m;
  }
}

Sum &Sum::operator=(const Sum &other) {
  if (this != &other) {
    for (MathExpression *m : this->expressions) {
      delete m;
    }
    for (MathExpression *m : other.expressions) {
      this->addExpression(m);
    }
  }
  return *this;
}

MathExpression *Sum::clone() const {
  Sum *newSum = new Sum;
  for (MathExpression *m : this->expressions) {
    newSum->addExpression(m);
  }
  return newSum;
}

void Sum::addExpression(MathExpression *m) {
  this->expressions.push_back(m->clone());
}

double Sum::value() const {
  double sum = 0;
  for (MathExpression *m : this->expressions) {
    sum += m->value();
  }
  return sum;
}

void Sum::print(std::ostream &out) const {
  out << "sum(";
  for (MathExpression *m : this->expressions) {
    m->print(out);
  }
  out << "), ";
}
