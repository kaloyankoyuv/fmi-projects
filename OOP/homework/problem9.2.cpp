#include <iostream>

struct Point {
  double x;
  double y;
};

class Line {
private:
  Point a;
  Point b;

public:
  Line(Point p1, Point p2) {
    this->a = p1;
    this->b = p2;
  }
  bool isParallel(const Line &other) {
    if (this->a.x == this->b.x && other.a.x == other.b.x) {
      return true;
    }
    if ((this->b.y - this->a.y) / (this->b.x - this->a.x) ==
        (other.b.y - other.a.y) / (other.b.x - other.a.x)) {
      return true;
    }
    return false;
  }
  bool goes_through(const Point &p) {

    if (this->a.x == this->b.x && this->a.x == p.x) {
      return true;
    }

    if (this->a.x == this->b.x && this->a.x != p.x) {
      return false;
    }

    double slope = (this->b.y - this->a.y) / (this->b.x - this->a.x);
    double c = this->a.y - slope * this->a.x;
    if (p.y == slope * p.x + c) {
      return true;
    }
    return false;
  }
  Point intersects(const Line &l) {
    Point result;
    double slope1 = (this->b.y - this->a.y) / (this->b.x - this->a.x);
    double c1 = this->a.y - slope1 * this->a.x;
    double slope2 = (l.b.y - l.a.y) / (l.b.x - l.a.x);
    double c2 = l.a.y - slope2 * l.a.x;
    result.x = (c1 - c2) / (slope2 - slope1);
    result.y = slope1 * result.x + c1;
    return result;
  }
};

int main() {

  Point A;
  A.x = 2;
  A.y = 3;
  Point B;
  B.x = 4;
  B.y = 1;
  Point C;
  C.x = 1;
  C.y = 0;
  Point D;
  D.x = 5;
  D.y = 4;

  Line l1(A, B);
  Line l2(C, D);

  std::cout << l1.intersects(l2).x << " " << l1.intersects(l2).y;

  return 0;
}
