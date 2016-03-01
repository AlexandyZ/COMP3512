#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.h"
#include "Point.h"

class Triangle: public Shape { //child class 2/2
public:
  explicit Triangle(const Point& v1 = Point(),
           const Point& v2 = Point(1,0),
           const Point& v3 = Point(0,1),
           GC::Colour colour = GC::Colour::Default)
  : Shape(colour),  // call base ctor
    v1_(v1), v2_(v2), v3_(v3) { // initialize other data members
  }

  explicit Triangle(std::istream& is): Shape(is) {
    is >> v1_ >> v2_ >> v3_;
  }

  virtual void save(std::ostream& os) const override {
    os << "Triangle" << std::endl;
    Shape::save(os);  // call corresponding base version
    os << v1_ << ' ' << v2_ << ' ' << v3_ << std::endl;
  }

  virtual void display(GC& gc) const override {
    Shape::display(gc);
    gc.getCanvas() << "[T: " << v1_ << ' ' << v2_ << ' ' << v3_ << ']' << std::endl;
  }

private:
  Point  v1_, v2_, v3_;
};

#endif
