#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include <cctype>
#include "Name.h"

class Student{
public:
    explicit Student(const std::string& id = "a00000000",
                    const std::string& first = "alex",
                    const std::string& last = "zhang")
    : id_(id), name_(first,last){
        if(!isValidId(id_))
            throw "Invalid Id";
    }
    friend std::ostream& operator << (std::ostream& os, const Student& s);
    friend std::istream& operator >> (std::istream& is, Student& s);

    virtual ~Student() {}
private:
    std::string id_;
    Name        name_;
    
    static bool isValidId(const std::string& id){
        if(id.length() != 9)
            return false;
        if(id[0] != 'a')
            return false;
        for(size_t i = 1; i < id.length(); i++)
            if(!isdigit(id[i]))
                return false;
        return true;
    }
};
inline std::ostream&
    operator << (std::ostream& os, const Student& s){
        return os << s.id_ << " " << s.name_ << std::endl; 
    }
    
inline std::istream&
    operator >> (std::istream& is, Student& s){
        std::string id;
        Name name;
        
        if(is >> id >> name && Student::isValidId(id)){
            s.id_ = id;
            s.name_ = name;
        } else {
            is.setstate(std::ios_base::failbit);
        }        
        return is;
    }
#endif