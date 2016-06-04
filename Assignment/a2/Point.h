#ifndef POINT_H
#define POINT_H
#include <iostream>

class Point {
public:
  explicit Point(int x = 0, int y = 0) noexcept: x_(x), y_(y) {}

  // note that Point(std::istream&) is not really needed although you
  // may implement one if you want

  int  getX() const noexcept { return x_; }
  int  getY() const noexcept { return y_; }
  void setX(int x) noexcept { x_ = x; }
  void setY(int y) noexcept { y_ = y; }
 
  void save(std::ostream& os = std::cout) const {
    os << "(" << x_ << ", " << y_ << ")" << std::endl;
  }

  // called by operator+ (see below)
  Point& operator+=(const Point& rhs) {
    // provide implementation here
    x_ += rhs.getX();
    y_ += rhs.getY();
    return *this;
  }

  friend Point operator*(int n, const Point& p);
  friend std::istream& operator>>(std::istream&, Point&); 
  friend std::ostream& operator<<(std::ostream&, const Point&); 
private:
  int x_, y_;
};

// addition of Points, e.g. (1,2) + (3,4) should give (4,6)
inline Point  
operator+(const Point& lhs, const Point& rhs) {
  Point tmp(lhs);
  return tmp += rhs;
}

// multiply a point by an int, e.g. 3 * (1,2) should give (3,6)
inline Point
operator*(int n, const Point& p) {
  // provide implementation here
  return Point(n * p.getX(), n * p.getY());
}

// should read back what's written by operator<< as well as by the save method
// some error-checking should be performed (see README)
inline std::istream&
operator>>(std::istream& is, Point& pt) {
  // provide implementation here
  int x, y;
  char c1, c2, c3;
  is >> c1 >> x >> c2 >> y >> c3;
  if(c1 == '(' && c2 == ',' && c3 == ')') {
      pt.x_ = x;
      pt.y_ = y;
  }
  else
      is.setstate(std::ios_base::failbit);
  return is;
}

inline std::ostream& 
operator<<(std::ostream& os, const Point& pt) {
  os << '(' << pt.x_ << ',' << pt.y_ << ')';
  return os;
} 
#endif
