#include <iostream>

class Time {
private:
  int hours;
  int minutes;

public:
  Time(int h = 0, int m = 0) {
    this->hours = h;
    this->minutes = m;
  }
  int get_hours() const { return this->hours; }
  int get_minutes() const { return this->minutes; }
  bool set_hours(int h) {
    if (h >= 0 && h <= 23) {
      this->hours = h;
      return true;
    }
    return false;
  }
  bool set_minutes(int m) {
    if (m >= 0 && m <= 59) {
      this->minutes = m;
      return true;
    }
    return false;
  }

  bool add_minutes(int m) {
    if (m >= 0) {
      this->hours = (this->hours + m / 60) % 24;
      if (this->minutes != 0 && this->minutes + m % 60 >= 60) {
        ++this->hours;
      }
      this->minutes = (this->minutes + m % 60) % 60;
      return true;
    }
    return false;
  }

  int get_minutes_all() { return this->hours * 60 + this->minutes; }

  bool operator<(const Time &other) {
    if (this->hours < other.hours) {
      return true;
    }
    if (this->hours == other.hours && this->minutes < other.minutes) {
      return true;
    }
    return false;
  }

  Time operator+(const Time &other) {
    Time result;
    result.hours = (this->hours + other.hours) % 24;
    if (!(this->minutes == 0 && other.minutes == 0) &&
        this->minutes + other.minutes >= 60) {
      ++result.hours;
    }
    result.minutes = (this->minutes + other.minutes) % 60;
    return result;
  }
};

std::ostream &operator<<(std::ostream &out, const Time &t) {
  if (t.get_hours() >= 10) {
    out << t.get_hours();
  } else {
    out << 0 << t.get_hours();
  }
  out << ":";

  if (t.get_minutes() >= 10) {
    out << t.get_minutes();
  } else {
    out << 0 << t.get_minutes();
  }
  return out;
}

int main() {

  Time t1(2, 5);
  Time t2(2, 59);

  std::cout << t1 + t2 << std::endl;
  std::cout << t1 << std::endl << t2 << std::endl;

  return 0;
}
