#include <iostream>
#include "pixels/draw/sdlwrapper.h"

void drawTriangle(int a) {

  sdlw::drawLine(500, 0, 1+a, 1+a);
  
}

int main() {

  drawTriangle(100);
  sdlw::updateGraphics();

  return 0;
}
