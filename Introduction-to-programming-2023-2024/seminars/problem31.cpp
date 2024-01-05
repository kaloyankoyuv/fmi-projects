#include <fstream>
#include <iostream>

struct Pixel {
  int r;
  int g;
  int b;
};

Pixel **createPicture(int n, int m) {

  Pixel **picture = new Pixel *[n];

  for (int i = 0; i < n; i++) {
    picture[i] = new Pixel[m];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      picture[i][j].r = 0;
      picture[i][j].g = 0;
      picture[i][j].b = 0;
    }
  }

  return picture;
}

void deletePicture(Pixel **picture, int n) {

  for (int i = 0; i < n; i++) {
    delete[] picture[i];
  }

  delete[] picture;
}

Pixel **enlargePicture(Pixel **picture, int &n, int &m) {

  int oldN = n;

  n = (n * 2) + 1;
  m = (m * 2) + 1;

  Pixel **newPicture = createPicture(n, m);

  for (int i = 1; i < n; i += 2) {
    for (int j = 1; j < m; j += 2) {
      newPicture[i][j].r = picture[i / 2][j / 2].r;
      newPicture[i][j].g = picture[i / 2][j / 2].g;
      newPicture[i][j].b = picture[i / 2][j / 2].b;
    }
  }

  deletePicture(picture, oldN);

  return newPicture;
}

Pixel **zoomPicture(Pixel **picture, int &n, int &m, int iter) {

  while (iter--) {

    picture = enlargePicture(picture, n, m);

    for (int i = 1; i < n; i += 2) {
      for (int j = 1; j < m; j += 2) {

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
  }

  return picture;
}



int main() {

  std::ifstream in;
  in.open("input.txt");

  std::ofstream out;
  out.open("output.txt");

  int rows;
  in >> rows;

  int cols;
  in >> cols;

  Pixel **picture = new Pixel *[rows];
  for (int i = 0; i < rows; i++) {
    picture[i] = new Pixel[cols];
  }

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      in >> picture[i][j].r;
      in >> picture[i][j].g;
      in >> picture[i][j].b;
    }
  }

  picture = zoomPicture(picture, rows, cols, 1);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      out << picture[i][j].r << " ";
      out << picture[i][j].g << " ";
      out << picture[i][j].b;
      out << std::endl;
    }
  }

  return 0;
}
