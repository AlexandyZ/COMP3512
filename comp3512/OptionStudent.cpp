#include "OptionStudent.h"

size_t OptionStudent::count_ = 0;
OptionStudent::OptionStudent(const OptionStudent& src) : Student(src), term_(src.term_), option_(src.option_){count_++;}

OptionStudent::OptionStudent(OptionStudent&& src) : Student(src), term_(src.term_), option_(src.option_){count_++;}
	
void OptionStudent::display(std::ostream& os)const{
Student::display(os);
os << "Term: " << term_ << "Option: " << option_ << std::endl;
}
void OptionStudent::print(std::ostream& os)const{
Student::print(os);
os << term_ << ' ' << option_ << std::endl;
}
std::ostream& operator<<(std::ostream& os, const OptionStudent& op){
return os << op.term_ << op.option_ << std::endl;
}
std::istream& operator>>(std::istream& is, OptionStudent& op){
Student temp;
std::string option;
int term;

if(is>>temp>>option>>term){
	(Student&)op = temp;
	op.option_ = option;
	op.term_ = term;
}
else{
	is.setstate(std::ios_base::failbit);
}
return is;
}