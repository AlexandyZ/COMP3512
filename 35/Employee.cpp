#include "Employee.h"

size_t Employee::count_ = 0;  //definition of count_


Employee::Employee(const Employee& src)
: id_(src.id_), name_(src.name_), birthdate_(src.birthdate_){
    count_++;
}
    
    //move ctor
Employee::Employee(Employee&& src)
: id_(std::move(src.id_)), name_(std::move(name_)), birthdate_(std::move(birthdate_)){
    count_++;
}