#ifndef TRIANGLE_H
#define TRIANGLE_H
// headers, ... 
#include <iostream>
#include "Shape.h"
#include "Point.h"

class Triangle: public Shape {
public:
  // read data for Triangle from 'is'; used by factory
  // should read in data members saved by 'save' (except for the type name)
  // should perform some error-checking (see README)
  explicit Triangle(std::istream& is); 

  // a Triangle consists of 3 vertices
  // 'i' should be 0, 1, or 2; if not, throw an exception
  Point getVertex(int i) const;

  // 'i' should be 0, 1, or 2; if not, throw an exception
  void  setVertex(int i, const Point& p); 

  // write to standard output
  // example output:  [T: (5,-6), (7,-8), (2,1)]
  virtual void draw() const override; 

  /* example output:
       triangle
       (5,-6) (7,-8) (2,1)
  */
  virtual void save(std::ostream& os = std::cout) const override; 

  // accept a visitor
  virtual void accept(ShapeVisitor& v) override;

private:
  // provide suitable data structure
  Point vertex0_;
  Point vertex1_;
  Point vertex2_;
};

// provide inline implementation of getVertex & setVertex here
inline
Point Triangle::getVertex(int i) const {
    Point p;
    if(i == 0)
        p = vertex0_;
    else if(i == 1)
        p = vertex1_;
    else if(i == 2)
        p = vertex2_;
    else
        throw "Point Triangle::getVertex(int i): invalid vertices";
    return p;
}

inline
void Triangle::setVertex(int i, const Point& p) {
    if(i == 0)
        vertex0_ = p;
    else if(i == 1)
        vertex1_ = p;
    else if(i == 2)
        vertex2_ = p;
    else
        throw "void Triangle::setVertex(int i, const Point& p): "
              "invalid vertices";
}
// implement the other functions in the CPP file
#endif
