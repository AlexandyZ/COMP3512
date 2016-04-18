#ifndef POINT_H
#define POINT_H
#include <iostream>

class Point {
public:
  explicit Point(int x = 0, int y = 0): x_(x), y_(y) {}
  friend std::ostream& operator<<(std::ostream& os, const Point& p);
  friend std::istream& operator>>(std::istream& is, Point& p);
private:
  int  x_, y_;
};

std::ostream&
operator<<(std::ostream& os, const Point& p) {
  return os << "(" << p.x_ << "," << p.y_ << ")";
}

std::istream&
operator>>(std::istream& is, Point& p) {
  char c1, c2, c3;
  return is >> c1 >> p.x_ >> c2 >> p.y_ >> c3;
}
#endif
