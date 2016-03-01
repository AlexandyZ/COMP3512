#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include "GC.h"
// don't put: using namespace std;

class Shape {//base class
public:
  explicit Shape(GC::Colour colour): colour_(colour) {}
  explicit Shape(std::istream& is) { 
    int  c;
    is >> c;
    colour_ = static_cast<GC::Colour>(c);
  }
  virtual ~Shape() {}
  virtual void save(std::ostream& os) const = 0;
  virtual void display(GC& gc) const = 0;
private:
  GC::Colour  colour_;
};

inline void  // virtual not repeated
Shape::save(std::ostream& os) const {
  os << static_cast<int>(colour_) << std::endl;
}

inline void
Shape::display(GC& gc) const {
  gc.setColour(colour_);
}
#endif
