#ifndef NAME_H
#define NAME_H
#include <iostream>
#include <string>

class Name {
public:
  explicit Name(const std::string& first = "homer", 
                const std::string& last = "simpson")
  : first_(first), last_(last) {  // always use member initializers
    if (!isValid(first_) || !isValid(last_))
      throw "Name::Name(string, string): invalid name";
  }
  // compiler-generated dtor, copy ctor, copy assignment, move ctor,
  // move assignment are OK
  /* compiler-generated copy assignment basically does the following:
    Name& operator=(const Name& src) {
      first_ = src.first_;
      last_ = src.last_;
      return *this;
    }
  */
  /* compiler-generated dtor
    ~Name() {}
  */

  std::string getFirst() const { return first_; }
  bool        setFirst(const std::string& first) { 
    if (!isValid(first))
      return false;
    first_ = first;
    return true;
  }

  friend std::ostream& operator<<(std::ostream&, const Name&);
  friend std::istream& operator>>(std::istream&, Name&);

private:
  std::string  first_, last_;
  static bool isValid(const std::string& s) { return true; }
};

inline std::ostream&
operator<<(std::ostream& os, const Name& n) {
  return os << n.first_ << ' ' << n.last_;
}

inline std::istream&
operator>>(std::istream& is, Name& n) {
  std::string  first, last;

  // need to prefix isValid by Name because operator>> is not a member of Name
  if (is >> first >> last && Name::isValid(first) && Name::isValid(last))
    n.first_ = first, n.last_ = last;
  else
    is.setstate(std::ios_base::failbit);

  return is;
}
#endif
