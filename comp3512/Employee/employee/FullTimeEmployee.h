#include "Employee.h"

class FullTimeEmployee: public Employee {
public:
  explicit FullTimeEmployee(const std::string& id = "a00000000",
                            const Name& name = Name(),
                            const Date& birthdate = Date(),
                            float salary = 0);

  ~FullTimeEmployee() { count_--; }
  FullTimeEmployee(const FullTimeEmployee& src);
  FullTimeEmployee(FullTimeEmployee&& src);

  // ask compiler to generate copy assignment
  FullTimeEmployee& operator=(const FullTimeEmployee& src) = default;
  // ask compiler to generate move assignment
  FullTimeEmployee& operator=(FullTimeEmployee&& src) = default;

  friend std::ostream& operator<<(std::ostream& os, const FullTimeEmployee& e);
  friend std::istream& operator>>(std::istream& is, FullTimeEmployee& e);

  virtual void display(std::ostream& os) const override;
private:
  float          salary_;
  static size_t  count_;  // declaration only
  static bool    isValid(float s) { return true; }
};  
