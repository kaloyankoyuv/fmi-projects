#include <iostream>

int myStrlen(char *str) {
  int result = 0;
  while (str[result] != 0) {
    result++;
  }
  return result;
}

class Word {
private:
  char word[20];

public:
  Word(char *_word) {
    for (int i = 0; i <= myStrlen(_word); i++) {
      this->word[i] = _word[i];
    }
  }

  Word() { this->word[0] = 0; }

  char *get_word() { return this->word; }
  void set_word(char *_word) {
    for (int i = 0; i <= myStrlen(_word); i++) {
      this->word[i] = _word[i];
    }
  }
  int get_len() { return myStrlen(this->word); }
  char operator[](int index) { return this->word[index]; }
  Word operator+(Word other) {
    if (this->get_len() > 10 || other.get_len() > 10) {
      return *this;
    }
    Word result;
    int k = 0;
    for (int i = 0; i < this->get_len(); i++) {
      result.word[k] = this->word[i];
      k++;
    }
    for (int i = 0; i <= other.get_len(); i++) {
      result.word[k] = other.word[i];
      k++;
    }
    return result;
  }
  Word &operator+=(Word &other) {
    if (this->get_len() + other.get_len() > 20) {
      return *this;
    }
    int x = this->get_len();
    for (int i = 0; i <= other.get_len(); i++) {
      this->word[i + x] = other.word[i];
    }
    return *this;
  }

  bool operator<(Word &other) {
    if (this->get_len() < other.get_len()) {
      return true;
    } else if (this->get_len() > other.get_len()) {
      return false;
    } else {
      for (int i = 0; i < this->get_len(); i++) {
        if (this->word[i] < other.word[i]) {
          return true;
        } else if (this->word[i] > other.word[i]) {
          return false;
        }
      }
      return false;
    }
  }

  bool operator==(Word &other) {
    if (this->get_len() != other.get_len()) {
      return false;
    }
    for (int i = 0; i < this->get_len(); i++) {
      if (this->word[i] != other.word[i]) {
        return false;
      }
    }
    return true;
  }
};

class Sentence {
private:
  char *str;

public:
  Sentence() { this->str = new char[0]; }
  Sentence(char *_str) {
    this->str = new char[myStrlen(_str) + 1];
    for (int i = 0; i <= myStrlen(_str); i++) {
      this->str[i] = _str[i];
    }
  }
  ~Sentence() { delete[] this->str; }

  Sentence(const Sentence &other) {
    this->str = new char[myStrlen(other.str) + 1];
    for (int i = 0; i <= myStrlen(other.str); i++) {
      this->str[i] = other.str[i];
    }
  }
  Sentence &operator=(const Sentence &other) {
    if (this != &other) {
      delete[] this->str;
      this->str = new char[myStrlen(other.str) + 1];
      for (int i = 0; i <= myStrlen(other.str); i++) {
        this->str[i] = other.str[i];
      }
    }
    return *this;
  }

  char *get_str() const { return this->str; }
  int get_strlen() const { return myStrlen(this->str); }
  Sentence &addWord(Word &w) {
    char *newStr = new char[this->get_strlen() + w.get_len() + 1];
    int k = 0;
    for (int i = 0; i < this->get_strlen(); i++) {
      newStr[k] = this->str[i];
      k++;
    }
    for (int i = 0; i <= w.get_len(); i++) {
      newStr[k] = w[i];
      k++;
    }
    delete this->str;
    this->str = newStr;
    return *this;
  }
};

std::ostream &operator<<(std::ostream &out, const Sentence &other) {
  out << other.get_str();
  return out;
}

int main() {

  char str1[] = "123";
  char str2[] = "asdf";
  Word w1(str1);
  Word w2(str2);

  Sentence s1(str1);
  std::cout << s1.addWord(w2) << std::endl;
  std::cout << s1;

  return 0;
}
