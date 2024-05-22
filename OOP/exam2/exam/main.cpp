#include "zad.hpp"
#include <iostream>

int main() {

  Constant *c1 = new Constant(1);
  Constant *c2 = new Constant(2);
  Constant *c3 = new Constant(3);
  Constant *c4 = new Constant(4);
  Constant *c5 = new Constant(5);
  Constant *c10 = new Constant(10);

  Sum *s1 = new Sum;
  Sum *s2 = new Sum;

  Sum *s3 = new Sum;

  s1->addExpression(c1);
  s1->addExpression(c2);

  Min *m1 = new Min(c1, s1);

  s2->addExpression(c3);
  s2->addExpression(c4);
  s2->addExpression(c5);

  s3->addExpression(m1);
  s3->addExpression(s2);
  s3->addExpression(c10);

  s3->print(std::cout);
  std::cout << std::endl;
  std::cout << s3->value() << std::endl;

  delete c1;
  delete c2;
  delete c3;
  delete c4;
  delete c5;
  delete c10;
  delete s1;
  delete s2;
  delete s3;
  delete m1;

  return 0;
}
