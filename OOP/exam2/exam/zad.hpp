#pragma once
#include <ostream>
#include <vector>

class MathExpression {
public:
  virtual ~MathExpression() = default;
  virtual MathExpression *clone() const = 0;
  virtual double value() const = 0;
  virtual void print(std::ostream &) const = 0;
};

class Constant : public MathExpression {
private:
  double x;

public:
  Constant(double);
  MathExpression *clone() const;
  double value() const;
  void print(std::ostream &) const;
};

class Min : public MathExpression {
private:
  MathExpression *m1;
  MathExpression *m2;

public:
  Min(MathExpression *, MathExpression *);
  Min(const Min &);
  ~Min();
  Min &operator=(const Min &);
  MathExpression *clone() const;
  double value() const;
  void print(std::ostream &) const;
};

class Sum : public MathExpression {
private:
  std::vector<MathExpression *> expressions;

public:
  Sum() = default;
  Sum(const Sum &);
  ~Sum();
  Sum &operator=(const Sum &);
  MathExpression *clone() const;
  void addExpression(MathExpression *);
  double value() const;
  void print(std::ostream &) const;

  // class Iterator {
  //   Iterator &operator++();
  //   MathExpression *operator*();
  //   bool operator!=(Iterator other);
  // };

  // Iterator begin();
  // Iterator end();
};
