#ifndef NAMELAB_H
#define NAMELAB_H
#include <iostream>

class Name{
public:
explicit Name(const std::string& first = "homer", const std::string& last = "simpson"):first_(first),last_(last){
	if(!isValid(first) || !isValid(last)){
		throw "Name is not valid";
	}
}	
std::string getFirst() const {return first_;}
bool setFirst(const std::string& first){
	if(!isValid(first)){
		return false;
	}
	first_ = first;
	return true;
}
friend std::ostream& operator<<(std::ostream& os, const Name& n);
friend std::istream& operator>>(std::istream& is, Name& n);

private:
	std::string first_, last_;
	static bool isValid(const std::string& s);
};

inline std::ostream& operator<<(std::ostream& os, const Name& n){
	return os << n.first_ << ' ' << n.last_ << std::endl;
}
inline std::istream& operator>>(std::istream& is, Name& n){
	std::string first, last;
	if(is >> first >> last && Name::isValid(first) && Name::isValid(last)){
		n.first_ = first;
		n.last_ = last;
	}
	else{
		is.setstate(std::ios_base::failbit);
	}
	return is;
}

#endif