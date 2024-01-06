#include <fstream>
#include <iostream>

struct Pixel {
  int r;
  int g;
  int b;
};

Pixel **createPicture(int heigth, int width) {

  Pixel **picture = new Pixel *[heigth];

  for (int i = 0; i < heigth; i++) {
    picture[i] = new Pixel[width];
  }

  for (int i = 0; i < heigth; i++) {
    for (int j = 0; j < width; j++) {
      picture[i][j].r = 0;
      picture[i][j].g = 0;
      picture[i][j].b = 0;
    }
  }

  return picture;
}

void deletePicture(Pixel **picture, int heigth) {

  for (int i = 0; i < heigth; i++) {
    delete[] picture[i];
  }

  delete[] picture;
}

Pixel **enlargePicture(Pixel **picture, int &heigth, int &width) {

  int oldHeigth = heigth;

  heigth = (heigth * 2) + 1;
  width = (width * 2) + 1;

  Pixel **newPicture = createPicture(heigth, width);

  for (int i = 1; i < heigth; i += 2) {
    for (int j = 1; j < width; j += 2) {
      newPicture[i][j].r = picture[i / 2][j / 2].r;
      newPicture[i][j].g = picture[i / 2][j / 2].g;
      newPicture[i][j].b = picture[i / 2][j / 2].b;
    }
  }

  deletePicture(picture, oldHeigth);

  return newPicture;
}

Pixel **zoomPicture(Pixel **picture, int &heigth, int &width, int iter) {

  while (iter--) {

    picture = enlargePicture(picture, heigth, width);

    for (int i = 1; i < heigth; i += 2) {
      for (int j = 1; j < width; j += 2) {

        picture[i][j - 1].r += picture[i][j].r / 2;
        picture[i][j - 1].g += picture[i][j].g / 2;
        picture[i][j - 1].b += picture[i][j].b / 2;

        picture[i][j + 1].r += picture[i][j].r / 2;
        picture[i][j + 1].g += picture[i][j].g / 2;
        picture[i][j + 1].b += picture[i][j].b / 2;

        picture[i - 1][j].r += picture[i][j].r / 2;
        picture[i - 1][j].g += picture[i][j].g / 2;
        picture[i - 1][j].b += picture[i][j].b / 2;

        picture[i + 1][j].r += picture[i][j].r / 2;
        picture[i + 1][j].g += picture[i][j].g / 2;
        picture[i + 1][j].b += picture[i][j].b / 2;
      }
    }

    for (int i = 2; i < heigth - 1; i += 2) {
      for (int j = 2; j < width - 1; j += 2) {
        picture[i][j].r = (picture[i - 1][j].r + picture[i + 1][j].r +
                           picture[i][j - 1].r + picture[i][j + 1].r) /
                          4;
        picture[i][j].g = (picture[i - 1][j].g + picture[i + 1][j].g +
                           picture[i][j - 1].g + picture[i][j + 1].g) /
                          4;
        picture[i][j].b = (picture[i - 1][j].b + picture[i + 1][j].b +
                           picture[i][j - 1].b + picture[i][j + 1].b) /
                          4;
      }
    }
  }

  return picture;
}

Pixel **invertPicture(Pixel **picture, int heigth, int width) {
  for (int i = 0; i < heigth; i++) {
    for (int j = 0; j < width; j++) {
      picture[i][j].r = 255 - picture[i][j].r;
      picture[i][j].g = 255 - picture[i][j].g;
      picture[i][j].b = 255 - picture[i][j].b;
    }
  }
  return picture;
}

int main() {

  std::ifstream in;
  in.open("input.txt");

  std::ofstream out;
  out.open("output.txt");

  int heigth, width;
  in >> heigth >> width;

  Pixel **picture = createPicture(heigth, width);

  for (int i = 0; i < heigth; i++) {
    for (int j = 0; j < width; j++) {
      in >> picture[i][j].r;
      in >> picture[i][j].g;
      in >> picture[i][j].b;
    }
  }

  // picture = invertPicture(picture, heigth, width);

  picture = zoomPicture(picture, heigth, width, 1);

  out << heigth;
  out << std::endl;

  out << width;
  out << std::endl;

  for (int i = 0; i < heigth; i++) {
    for (int j = 0; j < width; j++) {
      out << picture[i][j].r << " ";
      out << picture[i][j].g << " ";
      out << picture[i][j].b;
      out << std::endl;
    }
  }

  deletePicture(picture, heigth);

  return 0;
}
