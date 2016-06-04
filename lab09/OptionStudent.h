#ifndef OPTIONSTUDENT_H
#define OPTIONSTUDENT_H
#include <iostream>
#include <string>
#include "Student.h"

class OptionStudent: public Student{
public:
    explicit OptionStudent(const Student& student = Student(),
                           const int term = 3,
                           const std::string& option = "IS");
    OptionStudent(const OptionStudent& ops);
    static size_t getCount() { return count_; }
    virtual void print(std::ostream& os) const override;
    virtual void display(std::ostream& os) const override;
    virtual ~OptionStudent() { count_--; }
    
    friend std::istream& operator>>(std::istream& is, OptionStudent& s);
private:
    Student       student_;
    int           term_;
    std::string   option_;
    static size_t count_;
};

#endif