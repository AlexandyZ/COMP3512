#ifndef OPTIONSTUDENT_H
#define OPTIONSTUDENT_H
#include "Student.h"
#include <iostream>
#include <string>

class OptionStudent:public Student{
public:
	OptionStudent(const std::string& id = "a00",
				const std::string& first = "first",
				const std::string& last = "last",
				const int& term = 1,
				const std::string& option = "IS")
	:Student(id,first,last),term_(term),option_(option){count_++;}
	OptionStudent(const OptionStudent& src);
	OptionStudent& operator=(const OptionStudent&) = default;
	OptionStudent(OptionStudent&& src);
	OptionStudent& operator=(OptionStudent&&) = default;
	~OptionStudent(){count_--;}
	virtual void print(std::ostream& os)const override;
	virtual void display(std::ostream& os)const override;

	friend std::ostream& operator<<(std::ostream& os, const OptionStudent& op);
	friend std::istream& operator>>(std::istream& is, OptionStudent& op);

private:
	int term_;
	std::string option_;
	static size_t count_;
};

#endif