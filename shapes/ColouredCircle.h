#ifndef COLOUREDCIRCLE_H
#define COLOUREDCIRCLE_H
#include <utility>
#include <sstream>
#include "Point.h"
#include "ColouredShape.h"  // needs to include header file of base class

class ColouredCircle: public ColouredShape {
public:
  // note call to base class ctor 
  explicit ColouredCircle(const Point& centre = Point(0,0), int radius = 1, 
                          const GC::Colour& colour = GC::Colour::Default)
  : ColouredShape(colour), centre_(centre), radius_(radius) {
    if (radius_ < 0)
      throw "ColouredCircle::ColouredCircle(const Point&, int, int): "
            "negative radius not allowed";
  }

  explicit ColouredCircle(std::istream& is): ColouredShape(is) {
    is >> centre_ >> radius_;
  }

  virtual void draw(GC& gc) const override {
    ColouredShape::draw(gc);
    gc.draw(to_str());
  }

  // note call to overridden method
  virtual void save(std::ostream& os) const override {
    os << "ColouredCircle" << std::endl;
    ColouredShape::save(os);   // call base save method; note syntax
    os << centre_ << std::endl;
    os << radius_ << std::endl;
  }

  // note: return type can be "slightly" different from base version
  virtual ColouredCircle *clone() const override { 
    return new ColouredCircle(*this);  // calls copy ctor
  }
private:
  std::string to_str() const {
    std::ostringstream  oss;
    oss << "[C: " << centre_ << " " << radius_ << "]" 
        << std::endl;
    return oss.str();
  }

  Point  centre_;
  int    radius_;
};
#endif
