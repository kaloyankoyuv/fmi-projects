#include <iostream>
#include <string>
#include <vector>

class Person {
private:
  std::string name;
  int age;
  char gender;

public:
  Person(const std::string &_name = "none", int _age = 0, char _gender = '0')
      : name(_name), age(_age), gender(_gender) {}

  virtual std::string get_type() { return "person"; }

  virtual void print() {
    std::cout << "Name: " << this->name << std::endl
              << "Age: " << this->age << std::endl
              << "Gender: " << this->gender << std::endl;
  }
};

class Student : virtual public Person {
private:
  std::string fn;
  std::string major;
  int avg_grade;
  std::vector<std::string> subjects;

public:
  Student(const std::string &_name = "none", int _age = 0, char _gender = '0',
          const std::string &_fn = "none", const std::string &_major = "none",
          int _avg_grade = 0,
          std::vector<std::string> _subjects = std::vector<std::string>())
      : Person(_name, _age, _gender), fn(_fn), major(_major),
        avg_grade(_avg_grade), subjects(_subjects) {}

  virtual std::string get_type() { return "student"; }

  virtual void print() {
    Person::print();
    std::cout << "FN: " << this->fn << std::endl
              << "Major: " << this->major << std::endl
              << "AvgGrade: " << this->avg_grade << std::endl;
    std::cout << "Subjects: ";
    for (std::string s : this->subjects) {
      std::cout << s << " ";
    }
    std::cout << std::endl;
  }
};

class Teacher : virtual public Person {
private:
  std::string title;
  std::vector<std::string> subjects;
  int salary;

public:
  Teacher(const std::string &_name = "none", int _age = 0, char _gender = '0',
          const std::string &_title = "none",
          std::vector<std::string> _subjects = std::vector<std::string>(),
          int _salary = 0)
      : Person(_name, _age, _gender), title(_title), subjects(_subjects),
        salary(_salary) {}

  virtual std::string get_type() { return "teacher"; }

  virtual void print() {
    Person::print();
    std::cout << "Title: " << this->title << std::endl
              << "Salary: " << this->salary << std::endl;
    std::cout << "Subjects: ";
    for (std::string s : this->subjects) {
      std::cout << s << " ";
    }
    std::cout << std::endl;
  }
};

class TeachingAssistant : public Student, public Teacher {
public:
  TeachingAssistant(
      const std::string &_name = "none", int _age = 0, char _gender = '0',
      const std::string &_fn = "none", const std::string &_major = "none",
      int _avg_grade = 0,
      std::vector<std::string> _subjects = std::vector<std::string>(),
      const std::string &_title = "none", int _salary = 0)
      : Student(_name, _age, _gender, _fn, _major, _avg_grade, _subjects),
        Teacher(_name, _age, _gender, _title, _subjects, _salary) {}

  std::string get_type() { return "assistant"; }

  void print() {
    Student::print();
    Teacher::print();
  }
};

int main() {

  Person *p1 = new Person("Kaloyan", 19, 'm');
  Student *s1 =
      new Student("Ioan", 20, 'm', "2MI0920", "CS", 5, {"math", "programming"});
  Teacher *t1 =
      new Teacher("Kalin", 30, 'm', "Doctor", {"programming", "algos"}, 3000);
  TeachingAssistant *a1 = new TeachingAssistant(
      "Vicky", 24, 'f', "2MI000987", "OOP", 6, {"OOP", "UP"}, "Ph. d", 2700);

  std::vector<Person *> persons;

  persons.push_back(p1);
  persons.push_back(s1);
  persons.push_back(t1);
  persons.push_back(a1);

  for (Person *p : persons) {
    if (p->get_type() == "teacher")
      p->print();
  }
  return 0;
}
