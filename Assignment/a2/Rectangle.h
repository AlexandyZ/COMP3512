#ifndef RECTANGLE_H
#define RECTANGLE_H
// headers, ...
#include <iostream>
#include "Shape.h"
#include "Point.h"

class Rectangle: public Shape {
public:
  // read data for Rectangle from 'is'; used by factory
  // should read in data members saved by 'save' (except for the type name)
  // should perform some error-checking (see README)
  explicit Rectangle(std::istream& is);  

  // a Rectangle is specified by 2 (opposing) vertices
  // 'i' should be 0 or 1; if not, throw an exception
  Point getVertex(int i) const;

  // again, 'i' should be 0 or 1; if not, throw an exception
  void  setVertex(int i, const Point& p); 

  // write to standard output
  // example output:  [R: (2,-3), (4,-5)]  
  virtual void draw() const override; 

  /* example output:
       rectangle
       (2,-3) (4,-5)
  */
  virtual void save(std::ostream& os = std::cout) const override; 
  
  // accept a visitor
  virtual void accept(ShapeVisitor& visitor) override; 

private:
  // not shown; provide suitable data structure
  Point vertex0_;
  Point vertex1_;
};

// provide inline implementation of getVertex & setVertex here
inline
Point Rectangle::getVertex(int i) const {
    Point p;
    if(i == 0)
        p = vertex0_;
    else if(i == 1)
        p = vertex1_;
    else
        throw "Rectangle::getVertex(int i): invalid vertex";
    return p;
}

inline
void Rectangle::setVertex(int i, const Point& p) {
    if(i == 0) 
        vertex0_ = p;
    else if(i == 1)
        vertex1_ = p;
    else
        throw "void Rectangle::setVertex(int i, const Point& p): "
              "invalid vertex";
}

// implement the other functions in the CPP file
#endif
