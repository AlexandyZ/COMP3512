#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include <cctype>

class Student{
public:
    explicit Student(const std::string& id = "a12345678",
                    const std::string& first = "homer",
                    const std::string& last = "simpson")
    : id_(id), first_(first), last_(last){
        if(!isValidId(id_))
            throw "Invalid Id";
    }
    
    virtual void print(std::ostream& os) const{
        os << id_ << ' ' << first_ << ' ' << last_;
    }
    
    virtual void display(std::ostream& os) const{
        os << "ID: " << id_ << "\nName: " << first_ << ' ' << last_ << std::endl;
    }
    
    friend std::ostream& operator << (std::ostream& os, const Student& s);
    friend std::istream& operator >> (std::istream& is, Student& s);

    virtual ~Student() {}
private:
    std::string id_;
    std::string first_;
    std::string last_;
    
    static bool isValidId(const std::string& id){
        if(id.length() != 9)
            return false;
        if(id[0] != 'a')
            return false;
        for(size_t i = 1; i < id.length(); i++)
            if(!isdigit(id[i]))
                return false;
        return true;
    }
};

inline std::ostream&
operator << (std::ostream& os, const Student& s){
    s.print(os);
    return os;
    //return os << s.id_ << " " << s.first_ << ' ' << s.last_ << std::endl; 
}
    
inline std::istream&
operator >> (std::istream& is, Student& s){
    std::string id;
    std::string first;
    std::string last;
        
    if(is >> id >> first >> last){
        s.id_ = id;
        s.first_ = first;
        s.last_ = last;
    } else {
        is.setstate(std::ios_base::failbit);
    }        
    return is;
}

/*inline void
print(std::ostream os) const {
    os << id_ << ' ' << first_ << ' ' << last_;
}

inline void
display(std::ostream os) const {
    os << "ID: " << id_ << "\nName: " << first_ << ' ' << last_ << std::endl;
}*/
#endif