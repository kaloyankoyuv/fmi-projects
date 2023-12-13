#include <iostream>

int myStrLen(char *s) {

  int counter = 0;
  while (s[counter] != 0) {
    counter++;
  }
  return counter;
}

bool checkWord(char *word) {

  int wordLength = myStrLen(word);

  for (int i = 0; i < wordLength; i++) {
    if (!(word[i] >= 'a' && word[i] <= 'z')) {
      return false;
    }
  }
  return true;
}

void writeWordToBuffer(char *word, char *buffer, int bufferIndex) {

  for (int i = 0; i < myStrLen(word); i++) {
    buffer[bufferIndex] = word[i];
    bufferIndex++;
  }
}

void split(char *s, char *a, char *b) {

  int sLength = myStrLen(s);

  char word[255];

  int start = 0;

  int bufferIndexA = 0;
  int bufferIndexB = 0;

  for (int i = 0; i < sLength; i++) {

    if (s[i] == ' ') {

      for (int j = start; j < i; j++) {
        word[j - start] = s[j];
      }

      start = i + 1;

      if (checkWord(word)) {
        writeWordToBuffer(word, a, bufferIndexA);
        bufferIndexA += myStrLen(word) - 1;
      } else {
        writeWordToBuffer(word, b, bufferIndexB);
        bufferIndexB += myStrLen(word) - 1;
      }
    }
  }
}

int main() {

  char s[255];
  char a[255];
  char b[255];

  std::cin.getline(s, 255);

  split(s, a, b);
  std::cout << s << std::endl;
  std::cout << a << std::endl;
  std::cout << b << std::endl;

  return 0;
}
