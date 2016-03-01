#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include "Name.h"

class Student{

public:
	explicit Student(const std::string& id = "id",
					const std::string& first = "first",
					const std::string& last = "last"):id_(id),name_(first,last){}
	virtual ~Student(){}
	virtual void print(std::ostream& os)const;
	virtual void display(std::ostream& os)const;

	friend std::ostream& operator<<(std::ostream& os, const Student& s);
	friend std::istream& operator>>(std::istream& is, Student& s);

	std::string getId()const{return id_;}
	bool setId(const std::string& n){
		if(!isValidId(n)){
			return false;
		}
		id_ = n;
		return true;
	}
private:
	std::string id_;
	Name name_;
	static bool isValidId(const std::string& id);
};

inline std::ostream& operator<<(std::ostream& os, const Student& s){
	return os<<s.id_<<s.name_<<std::endl;
}
inline std::istream& operator>>(std::istream& is, Student& s){
	std::string id;
	Name name;

	if(is>>id>>name && Student::isValidId(id)){
		s.id_ = id;
		s.name_ = name;
	}
	else{
		is.setstate(std::ios_base::failbit);
	}
	return is;
}
void Student::print(std::ostream& os)const{
	os << id_ << ' ' << name_ << std::endl;
}
void Student::display(std::ostream& os)const{
	os << "ID: " << id_ << "Name: " << name_ << std::endl;
}

#endif