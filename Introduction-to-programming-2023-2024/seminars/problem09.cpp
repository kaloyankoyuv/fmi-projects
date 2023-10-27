#include <iostream>
#include <cmath>

bool isInCircle(double x, double y, double Ox, double Oy, double R) {
  return sqrt((x-Ox)*(x-Ox) + (y-Oy)*(y-Oy)) <= R;
}

int main() {

  double Ox,Oy,R;
  std::cin >> Ox >> Oy >> R;
  
  double a, b;
  for(int i=0; i<9; i++){
    std::cin >> a >> b;
    std::cout << isInCircle(a, b, Ox, Oy, R) << std::endl;
  }

  return 0;
}
