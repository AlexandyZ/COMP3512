#ifndef POINT_H
#define POINT_H
#include <iostream>

class Point { //used by the child classes
public:
  explicit Point(int x = 0, int y = 0): x_(x), y_(y) {}

  friend declarations
  friend std::ostream& operator<<(std::ostream&, const Point&);
  friend std::istream& operator>>(std::istream&, Point&);
private:
  int  x_, y_;
};

inline std::ostream& 
operator<<(std::ostream& os, const Point& p) {
  return os << '(' << p.x_ << ',' << p.y_ << ')';
}

/*
inline std::istream&
operator>>(std::istream& is, Point& p) { 
  char  c1, c2, c3;
  return is >> c1 >> p.x_ >> c2 >> p.y_ >> c3;
}
*/

inline std::istream&
operator>>(std::istream& is, Point& p) {
  char  c1, c2, c3;
  int   x, y;
  if (is >> c1 >> x >> c2 >> y >> c3 && c1 == '(' && c2 == ',' && c3 == ')')
    p.x_ = x, p.y_ = y;
  else
    is.setstate(std::ios_base::failbit);
  return is;
}

#endif
