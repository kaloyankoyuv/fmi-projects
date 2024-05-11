#include <cstring>
#include <iostream>
#include <vector>

class Document {
protected:
  std::string name;

public:
  virtual void ListContents() = 0;
};

class TextDocument : public Document {
private:
  char *text;

public:
  TextDocument(char *_text = "", std::string _name = "noname") {
    this->name = _name;
    this->text = new char[std::strlen(_text)];
    std::strcpy(this->text, _text);
  }
  TextDocument(const TextDocument &other) {
    this->name = other.name;
    this->text = new char[std::strlen(other.text)];
    std::strcpy(this->text, other.text);
  }
  ~TextDocument() { delete this->text; }
  TextDocument &operator=(const TextDocument &other) {
    if (this != &other) {
      delete this->text;
      this->name = other.name;
      this->text = new char[std::strlen(other.text)];
      std::strcpy(this->text, other.text);
    }
    return *this;
  }
  void ListContents() {
    std::cout << "Name: " << this->name << std::endl;
    std::cout << "Conents: " << this->text << std::endl;
  }
};

class Folder : public Document {
private:
  std::vector<Document *> Documents;

public:
  Folder(std::string _name = "noname") { this->name = _name; }
  void ListContents() {
    std::cout << "Name: " << this->name << std::endl;
    for (Document *d : this->Documents) {
      d->ListContents();
    }
  }
  void addDocument(Document &d) { this->Documents.push_back(&d); }
};

int main() {

  TextDocument t1("This is a line of text", "text_doc_1");
  TextDocument t2("This is another line of text", "text_doc_2");
  TextDocument t3("This is another another line of text", "text_doc_3");
  TextDocument t4;

  Folder f1("folder 1");
  f1.addDocument(t1);
  f1.addDocument(t2);

  Folder f2("folder 2");
  f2.addDocument(t3);
  f2.addDocument(f1);

  Folder f3;
  f3.addDocument(t4);
  f3.addDocument(f2);

  f3.ListContents();

  return 0;
}
