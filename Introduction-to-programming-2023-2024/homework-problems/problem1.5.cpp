#include <iostream>
using namespace std;

int main() {

  int x, y;
  cin >> x >> y;

  if (x==0 && y==0) {
    cout << "Point A is in the center of the coordinate system" << endl;
  } else if (x==0 && y!=0) {
    cout << "Point A is on the Y-axis" << endl;
  } else if (x!=0 && y==0) {
    cout << "Point A is on the X-axis" << endl;
  } else if (x>0 && y>0) {
    cout << "Point A is in the first quadrant" << endl;
  } else if (x>0 && y<0) {
    cout << "Point A is in the forth quadrant" << endl;
  } else if (x<0 && y>0) {
    cout << "Point A is in the second quadrant" << endl;
  } else if (x<0 && y<0) {
    cout << "Point A is in the third quadrant" << endl;
  }

  return 0;
}
