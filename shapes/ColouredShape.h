#ifndef COLOUREDSHAPE_H
#define COLOUREDSHAPE_H
#include <iostream>
#include "GC.h"
// don't use: using namespace std;

class ColouredShape {  // ABC (abstract base class): 
                       // 1) has at least 1 pure virtual function
                       // 2) cannot be instantiated
public:
  ColouredShape(const GC::Colour& colour): colour_(colour) {}

  virtual ~ColouredShape() {}

  virtual void draw(GC& gc) const = 0; // pure virtual function: implementation
                                       // is optional
  explicit ColouredShape(std::istream& is) {
    is >> colour_;
  }

  virtual void save(std::ostream& os) const = 0;

  virtual ColouredShape *clone() const = 0;
private:
  GC::Colour colour_;
};

// note inline
inline void
ColouredShape::save(std::ostream& os) const {
  os << colour_ << std::endl;
}

inline void 
ColouredShape::draw(GC& gc) const {
  gc.setColour(colour_);
}
#endif
