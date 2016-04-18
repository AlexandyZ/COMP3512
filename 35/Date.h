#ifndef DATE.H
#define DATE.H
#include <iostream>

class Date{
public:
    Date(int year = 2000, int month = 1, int day = 1)
    : year_(year), month_(month), day_(day){
        if(isValid(year_, month_, day_))
            throw "Date::Date(int, int, int): invalid date";
    }
    
    static bool isValid(int year, int month, int day){
        return true;
    }
    friend std::ostream& operator << (std::ostream& os, const Date& d);
    friend std::istream& operator >> (std::istream& is, Date& d);
private:
    int year_, month_, day_;
};

inline std::ostream&
operator<<(std::ostream& os, const Date& d){
    return os << d.year_ << '/' << d.month_ << '/' << d.day_;
}

inline std::istream& 
operator >> (std::istream& is, Date& d){
    int  year, month, day;
    char c1, c2;
    
    if(is >> year >> c1 >> month >> c2 >> day && c1 == '/' && c2 == '/' && Date::isValid(year, month, day)){
        d.year_ = year;
        d.month_ = month;
        d.day_ = day;
    }
    else 
        is.setstate(std::ios_base::failbit);
    return is;
}
#endif