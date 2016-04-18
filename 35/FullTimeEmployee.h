#ifndef FULLTIMEEMPLOYEE.H
#define FULLTIMEEMPLOYEE.H
#include "Employee.h"

class FullTimeEmployee: public Employee {
public:
    explicit FullTimeEmployee(const std::string& id = "A00000000",
                              const Name& name = Name(),
                              const Date& birthdate = Date(),
                              float salary = 0);
    //copy ctor
    FullTimeEmployee(const FullTimeEmployee& src);
    //move ctor
    FullTimeEmployee(FullTimeEmployee&& src);
    
    virtual ~FullTimeEmployee() { count_--; }
    virtual void print(std::ostream& os) const override;
    friend std::ostream& operator<<(std::ostream& os, const FullTimeEmployee& e);
    friend std::istream& operator>>(std::istream& is, FullTimeEmployee& e);
private:
    float salary_;
    static size_t count_;
};
#endif