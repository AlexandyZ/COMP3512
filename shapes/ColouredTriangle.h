#ifndef COLOUREDTRIANGLE_H
#define COLOUREDTRIANGLE_H
#include <utility>
#include <sstream>
#include "Point.h"
#include "ColouredShape.h" 

class ColouredTriangle: public ColouredShape {
public:
  explicit ColouredTriangle(const Point& v1 = Point(0,0),
                            const Point& v2 = Point(1,0),
                            const Point& v3 = Point(0,1), 
                            const GC::Colour& colour = GC::Colour::Default)
  : ColouredShape(colour), v1_(v1), v2_(v2), v3_(v3) {
  }

  explicit ColouredTriangle(std::istream& is): ColouredShape(is) {
    is >> v1_ >> v2_ >> v3_;
  }

  virtual void draw(GC& gc) const override {
    ColouredShape::draw(gc);
    gc.draw(to_str());
  }

  virtual void save(std::ostream& os) const override {
    os << "ColouredTriangle" << std::endl;
    ColouredShape::save(os);
    os << v1_ << std::endl;
    os << v2_ << std::endl;
    os << v3_ << std::endl;
  }

  virtual ColouredTriangle *clone() const override {
    return new ColouredTriangle(*this);
  }
private:
  std::string to_str() const {
    std::ostringstream  oss;
    oss << "[T: " << v1_ << ' ' << v2_ << ' ' << v3_ << " ]" 
        << std::endl;
    return oss.str();
  }
  Point  v1_, v2_, v3_;
};
#endif
