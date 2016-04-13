#ifndef XREFLECTIONVISITOR_H
#define XREFLECTIONVISITOR_H
// headers, ...
#include "ShapeVisitor.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"

class  XReflectionVisitor: public ShapeVisitor {
public:
  virtual ~XReflectionVisitor() {}  

  // provide implementation for the following in CPP file
  // implementation should reflect the shape about the x-axis
  virtual void visitCircle(Circle *s) override;
  virtual void visitRectangle(Rectangle *s) override;
  virtual void visitTriangle(Triangle *s) override;
};
#endif
