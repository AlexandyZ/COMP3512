#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "Name.h"
#include "Date.h"
#include <string>
#include <tuple>

typedef std::tuple<int, int, int> Date;

class Employee {
public:
    explicit Employee(const std::string& id = "A00000000",
                      const Name& name = Name(),
                      const Date& birthdate = Date())
    : id_(id), name_(name), birthdate_(birthdate){
        // validation
        count_++;
    }
    
    virtual void print(std::ostream& os) const {
        os << "ID:" << id_ << std::endl
           << "Name:" << name_ << std::endl
           << "Birthdate:" << birthdate_ << std::endl;
    }
    /*//copy ctor
    Employee(const Employee& src)
    : id_(src.id_), name_(src.name_), birthdate_(src.birthdate_){
        count_++;
    }
    
    //move ctor
    Employee(Employee&& src)
    : id_(std::move(src.id_)), name_(std::move(name_)), birthdate_(std::move(birthdate_)){
        count_++;
    }*/
    Employee(const Employee& src);
    Employee(Employee&& src);
    
    virtual ~Employee(){ count_--; }
    
    Employee& operator = (const Employee& src) = default;  //copy assignment
    Employee& operator = (Employee&& src) = default;  //move assignment

    friend std::ostream& operator << (std::ostream& os, const Employee& e);
    friend std::istream& operator >> (std::istream& is, Employee& e);
private:
    std::string   id_;
    Name          name_;
    Date          birthdate_;
    static size_t count_;   //declaration only, must be define in .cpp file
};


inline std::ostream& 
operator << (std::ostream& os, const Employee& e){
    return os << e.id_ << ' ' << e.name_ << ' ' << e.birthdate_;
}

inline std::istream& 
operator >> (std::istream& is, Employee& e){
    std::string id;
    Name        name;
    Date        birthdate;
    
    if(is >> id >> name >> birthdate)
        e.id_ = id, e.name_ = name, e.birthdate_ = birthdate;
    else
        is.setstate(std::ios_base::failbit);

    return is;
}

#endif