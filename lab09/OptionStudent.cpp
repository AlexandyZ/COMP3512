#include <iostream>
#include "OptionStudent.h"
using namespace std;

size_t OptionStudent::count_ = 0;

OptionStudent::OptionStudent(const std::string& id,
                             const std::string& first,
                             const std::string& last,
                             const int term,
                             const std::string& option)
: Student(id, first, last), term_(term), option_(option){
    count_++;
}

void
OptionStudent::print(std::ostream& os) const{
    Student::print(os);
    os << ' ' << term_ << ' ' << option_ << endl;
}

void
OptionStudent::display(std::ostream& os) const{
    Student::display(os);
    os << "Term: " << term_ << "\nOption: " << option_ << endl;
}