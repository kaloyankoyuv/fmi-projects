#include <iostream>

struct rect {
  int x;
  int y;
};

class Land {
private:
  int fence;
  int area;
  int maxy;
  int sumx;

public:
  Land() {
    this->fence = 0;
    this->area = 0;
    this->maxy = 0;
    this->sumx = 0;
  }
  Land(rect r) {
    this->fence = 2 * (r.x + r.y);
    this->area = r.x * r.y;
    this->maxy = r.y;
    this->sumx = r.x;
  }
  Land operator+(const rect &r) {
    Land result;
    result.maxy = std::max(this->maxy, r.y);
    result.sumx = this->sumx + r.x;
    result.fence = 2 * result.maxy + 2 * result.sumx;
    result.area = this->area + r.x * r.y;
    return result;
  }

  Land operator+=(const rect &r) {
    this->maxy = std::max(this->maxy, r.y);
    this->sumx = this->sumx + r.x;
    this->fence = 2 * this->maxy + 2 * this->sumx;
    ;
    this->area = this->area + r.x * r.y;
    return *this;
  }
  int get_fence() { return this->fence; }
  int get_area() { return this->area; }
};

int main() {

  rect r1;
  r1.x = 2;
  r1.y = 3;
  rect r2;
  r2.x = 3;
  r2.y = 4;

  Land l1(r1);
  l1 += r2;
  std::cout << l1.get_fence() << " " << l1.get_area();

  return 0;
}
