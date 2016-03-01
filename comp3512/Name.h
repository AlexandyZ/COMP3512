#ifndef NAME_H
#define NAME_H
#include <iostream>
#include <string>

class Name{
public:
	explicit Name(const std::string& first = "defaut", 
				const std::string& last = "default"):first_(first), last_(last){
		if(!isValid(first) || !isValid(last)){
			throw "invalid Name";
		}
	}

	friend std::ostream& operator<<(std::ostream& os, const Name& n){
		return os << n.first_ << ' ' << n.last_ << std::endl;
	}
	friend std::istream& operator>>(std::istream& is, Name& n){
		std::string first, last;

		if(is >> first >> last && isValid(first) && isValid(last)){
			n.first_=first;
			n.last_=last;
		}
		else{
			is.setstate(std::ios_base::failbit);
		}
		return is;
	}

private:
	static bool isValid(const std::string& name);
	std::string first_,last_;
};

#endif