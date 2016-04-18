#include <iostream>
#include "OptionStudent.h"
using namespace std;

size_t OptionStudent::count_ = 0;

OptionStudent::OptionStudent(const std::string& id,
                             const Name& name,
                             const int term,
                             const std::string& option)
: Student(id, name), term_(term), option_(option){
    count_++;
}
OptionStudent::OptionStudent(const OptionStudent& ops)
: Student(ops), term_(ops.term_), option_(ops.option_) {
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

istream&
operator>>(istream& is, OptionStudent& s){
    Student tmp;
    int     term;
    string  opt;
    
    if(is >> tmp >> term >> opt){
        (Student&) s = tmp;
        s.term_      = term;
        s.option_    = opt;
    } else {
        is.setstate(ios_base::failbit);
    }
    
    return is;
}