#include <iostream>
#include <string>

//
// Bad code, don't read
//

class Car {
private:
  std::string model;
  int year;
  int range;

public:
  virtual void display_info() const = 0;
  virtual void drive() = 0;
};

class ElectricCar : public Car {
private:
  int battery_level;
  std::string model;
  int year;
  double efficiency;
  int range;

public:
  ElectricCar(int _bat, std::string _model, int _year, double _ef, int _range)
      : battery_level(_bat), model(_model), year(_year), efficiency(_ef),
        range(_range) {}

  void charge(int c) { battery_level += c; }

  double get_remain_range() const { return range; }

  bool drive(int distance) {
    if (range < distance) {
      battery_level = 0;
      return false;
    } else {
      battery_level -= efficiency * range;
      return true;
    }
  }

  void display_info() const {
    std::cout << "Battery Level: " << battery_level << std::endl;
    std::cout << "Model: " << model << std::endl;
    std::cout << "Year: " << year << std::endl;
    std::cout << "Efficiency" << efficiency << std::endl;
    std::cout << "Range" << range << std::endl;
  }
};

class CombustionCar : public Car {
private:
  std::string model;
  double efficiency;
  int fuel;
  int year;

public:
  CombustionCar(std::string _model, double _ef, int _fuel, int _year)
      : model(_model), efficiency(_ef), fuel(_fuel), year(_year) {}

  void display_info() const {
    std::cout << "Fuel: " << fuel << std::endl;
    std::cout << "Model: " << model << std::endl;
    std::cout << "Year: " << year << std::endl;
    std::cout << "Efficiency" << efficiency << std::endl;
  }

  bool drive(int distance) {
    if (fuel * efficiency * 100 < distance) {
      fuel = 0;
      return false;
    } else {
      fuel -= efficiency * distance;
      return true;
    }
  }

  double get_remain_range() { return fuel * efficiency * 100; }
};

class HybridCar : public ElectricCar, public CombustionCar {
public:
  HybridCar();
};

int main() {
  ElectricCar ev(100, "Tesla 3", 2022, 0.6, 250);

  CombustionCar cv("Lexus IS", 0.04, 18, 2020);
}
