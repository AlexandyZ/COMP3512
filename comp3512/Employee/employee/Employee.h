// Incomplete
#include <string>
#include <iostream>
#include "Date.h"
#include "Name.h"

class Employee {
public:
  explicit Employee(const std::string id = "a00000000", 
                    const Name& name = Name(),
                    const Date& birthdate = Date())
  : id_(id), name_(name), birthdate_(birthdate) {
    // validation goes here
  }

  virtual ~Employee() {}

  // ask compiler to generate these
  Employee(const Employee&) = default;
  Employee& operator=(const Employee&) = default;
  Employee(Employee&&) = default;
  Employee& operator=(Employee&&) = default;

  std::string getId() const { return id_; }
  bool        setId(const std::string& id) {
    // validate id here
    id_ = id;
    return true;
  }

  virtual void display(std::ostream& os) const {
    os << "ID: " << id_ << std::endl;
    os << "Name: " << name_ << std::endl;
    os << "Birthdate: " << birthdate_ << std::endl;
  }

  friend std::ostream& operator<<(std::ostream& os, const Employee& e);
  friend std::istream& operator>>(std::istream& is, Employee& e);
private:
  std::string  id_;
  Name         name_;
  Date         birthdate_;
  static bool  isValidId(const std::string& ) { return true; }
};

inline std::ostream&
operator<<(std::ostream& os, const Employee& e) {
  return os << e.id_ << ' ' << e.name_ << ' ' << e.birthdate_;
}

inline std::istream& 
operator>>(std::istream& is, Employee& e) {
  std::string  id;
  Name         n;
  Date         d;

  if (is >> id >> n >> d && Employee::isValidId(id))
    e.id_ = id, e.name_ = n, e.birthdate_ = d;
  else
    is.setstate(std::ios_base::failbit);

  return is;
}
