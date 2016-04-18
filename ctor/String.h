#include <iostream>
#include <cstring>

class String{
private:
    char *s_;
public:
    typedef char *iterator;
    typedef const char *const_iterator;
    String(const char *s): s_(new char[strlen(s) + 1]){  //initialize a new copy
        strcpy(s_, s);
    }
    
    String(const String& src): s_(new char[strlen(src.s_) + 1]){
        strcpy(s_, src.s_);
    }
    
    ~String() { delete [] s_; }
    /*
    String& operator=(const String& src){
        if(&src != this){  // this is the current object
            char *tmp = new char[strlen(src.s_) + 1];
            strcpy(s_, src.s_);
            delete [] s_;
            s_ = tmp;   
        }
        return *this;
    }*/
    friend std::ostream operator<<(std::ostream& os, const String& s);
    
    void swap(String& other){
        std::swap(s_, other.s_);
    }
    
    String& operator=(const String& src){
        String tmp(src);
        swap(tmp);
        return *this;
    }
    
    iterator begin() { return s_; }
    iterator end() { return s_ + strlen(s_); }
};

std::ostream&
operator<<(std::ostream& os, const String& s){
    return os << s;
}