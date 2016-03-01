#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>
#include <utility>
#include "GC.h"
#include "Shape.h"
#include "Point.h"

class Circle: public Shape { //child class 1/2
public:
  explicit Circle(const Point& centre = Point(), int radius = 1, 
                  GC::Colour colour = GC::Colour::Default)
  : Shape(colour),  // call base ctor
    centre_(centre), radius_(radius) {
    if (radius_ < 0)
      throw "Circle::Circle(const Point&, int, int): "
            " negative radius not allowed";
  }

  explicit Circle(std::istream& is): Shape(is) {
    is >> centre_ >> radius_;
  }

  virtual void save(std::ostream& os) const override;
  virtual void display(GC& gc) const override;

private:
  Point  centre_;
  int    radius_;
};

inline void  // virtual & override not repeated
Circle::save(std::ostream& os) const {
  os << "Circle" << std::endl;
  Shape::save(os);  // calls corresponding base method
  os << centre_ << ' ' << radius_ << std::endl;
}

inline void
Circle::display(GC& gc) const {
  Shape::display(gc);
  gc.getCanvas() << "[C: " << centre_ << ' ' << radius_ << ']' << std::endl;
}
#endif
