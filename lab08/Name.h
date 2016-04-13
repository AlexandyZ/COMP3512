#ifndef NAME_H
#define  NAME_H
#include <string>
#include <iostream>
#include <cctype>

class Name{
public:
    explicit Name(const std::string& first = "alex",
                 const std::string& last = "zhang")
    :first_(first), last_(last){
        if(!isValidName(first_) || !isValidName(last_))
            throw "Invalid name";
    }
    
    friend std::ostream& operator << (std::ostream& os, const Name& n);
    friend std::istream& operator >> (std::istream& is, Name& n);
    
    std::string getFirst() const { return first_; }
    bool setFirst(const std::string& first){
        if(!isValidName(first))
            return false;
        first_ = first;
        return true;
    }

    std::string getLast() const { return last_; }
    bool setLast(const std::string& last){
        if(!isValidName(last))
            return false;
        last_ = last;
        return true;
    }

private:
    std::string first_, last_;
    
    static bool isValidName(const std::string& name) {
        if(name.empty())
            return false;
        for(size_t i = 0; i < name.length(); i++)
            if(isspace(name[i]))
                return false;
        return true;
    }
};

//friend declare
inline std::ostream&
operator<<(std::ostream& os, const Name& n) {
    return os << n.first_ << ' '<< n.last_;
}

inline std::istream&
operator>>(std::istream& is, Name& n) {
    std::string first, last;
    
    if(is >> first >> last && 
        Name::isValidName(first) && 
        Name::isValidName(last)) {
        n.first_ = first;
        n.last_ = last;
    } else{
        is.setstate(std::ios_base::failbit);
    }
    
    return is;   
}
#endif