#include "FullTimeEmployee.h"

// note: need to prefix by class name
size_t FullTimeEmployee::count_ = 0;  // definition of count_

// note: no explicit; default args not repeated here
FullTimeEmployee::FullTimeEmployee(const std::string& id,
                            const Name& name,
                            const Date& birthdate,
                            float salary) 
: Employee(id, name, birthdate), salary_(salary) {
  // validation goes here
}


FullTimeEmployee::FullTimeEmployee(const FullTimeEmployee& src)
: Employee(src), salary_(src.salary_) {
  count_++;
}


FullTimeEmployee::FullTimeEmployee(FullTimeEmployee&& src)
: Employee(std::move(src)), salary_(std::move(src.salary_)) {
  count_++;
}


std::ostream& operator<<(std::ostream& os, const FullTimeEmployee& e) {
  return os << (const Employee&) e << ' ' << e.salary_;   // note cast
}

std::istream& operator>>(std::istream& is, FullTimeEmployee& e) {
  // return is >> (Employee&) e >> e.salary_;  // version w/o error-handling
  Employee  tmp;
  float     salary;

  if (is >> tmp >> salary && FullTimeEmployee::isValid(salary)) {
    (Employee&) e = tmp;  // or: e.Employee::operator=(tmp);
    e.salary_ = salary;
  } else
    is.setstate(std::ios_base::failbit);
  return is;
}

void 
FullTimeEmployee::display(std::ostream& os) const {
  Employee::display(os);  // call base display method
  os << "Salary: " << salary_ << std::endl;
}
