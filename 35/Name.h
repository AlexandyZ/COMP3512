class Name{
public:
    explicit Name(){
        
    }
    friend std::ostream& operator<<(std::ostream& os, const Name& n);
    friend std::istream& operator<<(std::istream& os, Name& n);
    friend bool operator == (const Name&, const Name&);
    friend bool operator < (const Name&, const Name&); 
private:
    std::string first_, last_;
    static bool isValid(){
        
    }
};

bool setLast(const std::string& last){
    if(!isValid(last))
        return false;
    last_ = last;
    return true;
}

inline std::ostream&
operator<<(std::ostream& os, const Name& n) {
    return os << n.first_ << ' ' << n.last_;
}

inline std::istream&
operator<<(std::istream& os, Name& n) {
    std::string first, last;
    
    if(is >> first >> last && Name::isValid(first) && Name::isValid(last))
        n.first_ = first, n.last_ = last;
    else
        is.setstate(std::ios_base::failbit);
    
    return is;
}

inline bool 
operator == (const Name& lhs, const Name& rhs) {
    return lhs.first_ == rhs.first_ &&
           lhs.last_ == rhs.last_;
}

inline bool 
operator < (const Name& lhs, const Name& rhs) {
    return lhs.last_ < rhs.last_ ||
           (lhs.last_ == rhs.last_ && lhs.first_ < rhs.first_);
}

inline bool 
operator != (const Name& lhs, const Name& rhs) {
    return !(lhs == rhs);
}

inline bool 
operator <= (const Name& lhs, const Name& rhs) {
    return lhs < rhs || lhs == rhs;
}

inline bool 
operator >= (const Name& lhs, const Name& rhs) {
    return !(lhs < rhs);
}

inline bool 
operator > (const Name& lhs, const Name& rhs) {
    return lhs > rhs;
}