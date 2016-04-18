#include "FullTimeEmployee.h"
using namespace std;

size_t FullTimeEmployee::count_ = 0;

//explicit, virtual, default arguments not repeated here
FullTimeEmployee::FullTimeEmployee(const std::string& id,
                                   const Name& name,
                                   const Date& birthdate,
                                   float salary)
: Employee(id, name, birthdate), salary_(salary){  //call base ctor
    if(salary_ < 0)
        throw "salary cannot be negtive number";
    count_++;
}

//implement copy ctor
FullTimeEmployee::FullTimeEmployee(const FullTimeEmployee& src)
: Employee(src), salary_(src.salary_) {
    count_++;
}
//implement move ctor
FullTimeEmployee::FullTimeEmployee(FullTimeEmployee&& src)
: Employee(move(src)), salary_(move(src.salary_)) {
    count_++;
}

/* 
//copy assignment (not really necessary as compiler-generated version is ok)
FullTimeEmployee&
FullTimeEmployee::operator=(const FullTimeEmployee& src){
    if(this != &src){  // they are not the same object by compare their address.
        //call the base(inheritance) assignment
        Employee::operator=(src);  //this -> Employee::operator=(src)
        salary+ = src.salary_;     //this -> salary_ = src.salary_;
    }
    return *this;
}
//move assignment (...)
FullTimeEmployee&
FullTimeEmployee::operator=(FullTimeEmployee&& src){
    if(this != &src){
        Employee::operator=(move(src));
        salary_ = move(src.salary_);
    }
    return *this;
}
*/
ostream& operator<<(ostream& os, const FullTimeEmployee& e){
    return os << (const Employee&) e << ' ' << e.salary_;  //note cast
}
istream& operator>>(istream& is, FullTimeEmployee& e){
    //return is >> (Employee&) e >> e.salary_;
    Employee tmp;
    float    salary;
    
    if(is >> tmp >> salary && salary >= 0){
        (Employee&) e = tmp;   //or e.Employee::operator=(tmp);
        e.salary_ = salary;
    } else {
        is.setstate(ios_base::failit);
    }
    return is;
}

void 
FullTimeEmployee::print(std::ostream& os) const {
    Employee::print(os);
    os << "Salary: " << salary_ << endl;
}