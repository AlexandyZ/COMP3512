#ifndef YREFLECTIONVISITOR_H
#define YREFLECTIONVISITOR_H
// headers, ...
#include "ShapeVisitor.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"

class  YReflectionVisitor: public ShapeVisitor {
public:
  virtual ~YReflectionVisitor() {}  

  // provide implementation for the following in CPP file
  // implementation should reflect the shape about the y-axis
  virtual void visitCircle(Circle *s) override;
  virtual void visitRectangle(Rectangle *s) override;
  virtual void visitTriangle(Triangle *s) override;
};
#endif
