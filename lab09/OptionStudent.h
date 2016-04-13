#ifndef OPTIONSTUDENT_H
#define OPTIONSTUDENT_H
#include <iostream>
#include <string>
#include "Student.h"

class OptionStudent: public Student{
public:
    explicit OptionStudent(const std::string& id = "a12345678",
                           const std::string& first = "homer",
                           const std::string& last = "simpson",
                           const int term = 3,
                           const std::string& option = "IS");

    static size_t getCount() { return count_; }
    virtual void print(std::ostream& os) const override;
    virtual void display(std::ostream& os) const override;
    virtual ~OptionStudent() { count_--; }
    
    friend std::istream& operator>>(std::istream& is, OptionStudent& s);
private:
    int           term_;
    std::string    option_;
    static size_t count_;
};

#endif