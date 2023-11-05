#include <iostream>

float overlapArea(float x1, float y1, float w1, float h1,
		  float x2, float y2, float w2, float h2) {

  float x = std::min(x1 + w1, x2 + w2) - std::max(x1, x2);
  float y = std::min(y1 + h1, y2 + h2) - std::max(y1, y2);
  
  if (x > 0 && y > 0) {
    return x * y;
  } else {
    return 0;
  }
  
}

int main() {

  float x1, y1, w1, h1, x2, y2, w2, h2;

  std::cin >> x1 >> y1 >> w1 >> h1 >> x2 >> y2 >> w2 >> h2;

  std::cout << overlapArea(x1, y1, w1, h1, x2, y2, w2, h2) << std::endl;

  return 0;
  
}
