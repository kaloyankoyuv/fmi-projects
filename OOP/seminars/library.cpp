#include <iostream>

int myStrLen(char *s) {
  int result = 0;
  while (s[result] != 0) {
    result++;
  }
  return result;
}

class Person {

private:
  char *name;
  char gender;
  int age;

public:
  Person(char *n, char g, int a) {

    this->name = new char[myStrLen(n)];
    for (int i = 0; i < myStrLen(n); i++) {
      this->name[i] = n[i];
    }
    this->gender = g;
    this->age = a;
  }

  Person(const Person &other) {
    this->gender = other.gender;
    this->age = other.age;

    this->name = new char[myStrLen(other.name)];
    for (int i = 0; i < myStrLen(other.name); i++) {
      this->name[i] = other.name[i];
    }
  }

  ~Person() { delete[] this->name; }

  Person &operator=(const Person &other) {
    if (this != &other) {
      delete[] this->name;
      this->gender = other.gender;
      this->age = other.age;

      this->name = new char[myStrLen(other.name)];
      for (int i = 0; i < myStrLen(other.name); i++) {
        this->name[i] = other.name[i];
      }
    }
    return *this;
  }

  int get_age() const { return this->age; }
  char get_gender() const { return this->gender; }
  char *get_name() const { return this->name; }

  bool set_age(int age) {
    if (age >= 0 && age <= 150) {
      this->age = age;
      return true;
    }
    return false;
  }
  bool set_gender(char gender) {
    if (gender == 'm' || gender == 'f') {
      this->gender = gender;
      return true;
    }
    return false;
  }

  void set_name(char *name) {
    delete[] this->name;
    this->name = new char[myStrLen(name)];
    for (int i = 0; i <= myStrLen(name); i++) {
      this->name[i] = name[i];
    }
  }
};

std::ostream &operator<<(std::ostream &out, const Person &p) {
  out << "name: " << p.get_name() << ", ";
  out << "gender: " << p.get_gender() << ", ";
  out << "age: " << p.get_age();
  out << std::endl;
  return out;
}

class Book {
private:
  char *name;
  char *author;
  int year;
  char age_rating;

public:
  Book(char *_name, char *_author, int _year, char _age_rating) {
    this->name = new char[myStrLen(_name)];
    for (int i = 0; i < myStrLen(_name); i++) {
      this->name[i] = _name[i];
    }
    this->author = new char[myStrLen(_author)];
    for (int i = 0; i < myStrLen(_author); i++) {
      this->author[i] = _author[i];
    }
    this->year = _year;
    this->age_rating = _age_rating;
  }

  Book(const Book &other) {
    this->name = new char[myStrLen(other.name)];
    for (int i = 0; i < myStrLen(other.name); i++) {
      this->name[i] = other.name[i];
    }
    this->author = new char[myStrLen(other.author)];
    for (int i = 0; i < myStrLen(other.author); i++) {
      this->author[i] = other.author[i];
    }
    this->year = other.year;
    this->age_rating = other.age_rating;
  }

  ~Book() {
    delete[] this->name;
    delete[] this->author;
  }

  Book &operator=(const Book &other) {
    if (this != &other) {
      delete[] this->name;
      delete[] this->author;
      this->year = other.year;
      this->age_rating = other.age_rating;

      this->name = new char[myStrLen(other.name)];
      for (int i = 0; i < myStrLen(other.name); i++) {
        this->name[i] = other.name[i];
      }
      this->author = new char[myStrLen(other.author)];
      for (int i = 0; i < myStrLen(other.author); i++) {
        this->author[i] = other.author[i];
      }
    }
    return *this;
  }

  char *get_name() const { return this->name; }
  char *get_author() const { return this->author; }
  int get_year() const { return this->year; }
  char get_age_rating() const { return this->age_rating; }
};

std::ostream &operator<<(std::ostream &out, const Book &b) {
  out << "name: " << b.get_name() << ", ";
  out << "author: " << b.get_author() << ", ";
  out << "year: " << b.get_year() << ", ";
  out << "age_rating: " << b.get_age_rating();
  out << std::endl;
  return out;
}

class Library {
private:
  Person *librarian;
  Person **readers;
  int nreaders;
  Book **books;
  int nbooks;

public:
  Library(Person *_librarian, Person **_readers, int _nreaders, Book **_books,
          int _nbooks) {
    this->nreaders = _nreaders;
    this->nbooks = _nbooks;
    this->librarian = _librarian;
    this->readers = new Person *[this->nreaders];
    for (int i = 0; i < this->nreaders; i++) {
      this->readers[i] = _readers[i];
    }
    this->books = new Book *[this->nbooks];
    for (int i = 0; i < this->nbooks; i++) {
      this->books[i] = _books[i];
    }
  }
  Library(const Library &other) {
    this->librarian = other.librarian;
    this->nreaders = other.nreaders;
    this->nbooks = other.nbooks;
    this->readers = new Person *[this->nreaders];
    for (int i = 0; i < this->nreaders; i++) {
      this->readers[i] = other.readers[i];
    }
    this->books = new Book *[this->nbooks];
    for (int i = 0; i < this->nbooks; i++) {
      this->books[i] = other.books[i];
    }
  }
  ~Library() {
    delete[] readers;
    delete[] books;
  }

  Library &operator=(const Library &other) {
    if (this != &other) {
      delete[] this->readers;
      delete[] this->books;
      this->nreaders = other.nreaders;
      this->nbooks = other.nbooks;
      this->librarian = other.librarian;

      this->readers = new Person *[this->nreaders];
      for (int i = 0; i < this->nreaders; i++) {
        this->readers[i] = other.readers[i];
      }
      this->books = new Book *[this->nbooks];
      for (int i = 0; i < this->nbooks; i++) {
        this->books[i] = other.books[i];
      }
    }
    return *this;
  }

  int get_nreaders() const { return this->nreaders; }
  int get_nbooks() const { return this->nbooks; }
  Person *get_librarian() const { return this->librarian; }
  Person **get_readers() const { return this->readers; }
  Book **get_books() const { return this->books; }

  void add_reader(Person *p) {
    Person **newReaders = new Person *[this->nreaders + 1];
    for (int i = 0; i < this->nreaders; i++) {
      newReaders[i] = this->readers[i];
    }
    newReaders[this->nreaders] = p;
    delete[] this->readers;
    this->readers = newReaders;
    this->nreaders += 1;
  }

  void add_book(Book *b) {
    Book **newBooks = new Book *[this->nbooks + 1];
    for (int i = 0; i < this->nbooks; i++) {
      newBooks[i] = this->books[i];
    }
    newBooks[this->nbooks] = b;
    delete[] this->books;
    this->books = newBooks;
    this->nbooks += 1;
  }
  void change_librarian(Person *p) { this->librarian = p; }
};

std::ostream &operator<<(std::ostream &out, const Library &l) {
  out << "Number of readers: " << l.get_nreaders() << std::endl;
  out << "Number of books: " << l.get_nbooks() << std::endl;
  out << "Librarian: " << *l.get_librarian() << std::endl;
  out << "Readers: " << std::endl;
  for (int i = 0; i < l.get_nreaders(); i++) {
    out << *l.get_readers()[i];
  }
  out << "Books: " << std::endl;
  for (int i = 0; i < l.get_nbooks(); i++) {
    out << *l.get_books()[i];
  }
  out << std::endl;

  return out;
}

int main() {

  int nbooks = 3;
  int nreaders = 3;

  Person librarian("Valio", 'm', 20);

  Person reader1("Kaloyan", 'm', 20);
  Person reader2("Kris", 'm', 20);
  Person reader3("Simona", 'f', 23);

  Book book1("LoTR", "J.R.R", 1987, 'd');
  Book book2("WoT", "Robert Jordan", 1998, 'e');
  Book book3("Harry Potter", "J.K", 1996, 'c');

  Person *readers[] = {&reader1, &reader2, &reader3};
  Book *books[] = {&book1, &book2, &book3};

  Library l1(&librarian, readers, nreaders, books, nbooks);

  l1.add_reader(&reader1);
  l1.add_book(&book1);
  l1.change_librarian(&reader1);

  std::cout << l1;

  return 0;
}
