#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H
// headers, ...
#include <iostream>
#include <string>
#include "Shape.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"

class ShapeFactory {
public:
  explicit ShapeFactory(std::istream& is): pis_(&is) {}

  // refer to lecture; see writeup for brief description
  Shape* create() {
      std::string type;
      
      if(*pis_ >> type) {
          if(type == "circle")
            return new Circle(*pis_);
          if(type == "triangle")
            return new Triangle(*pis_);
          if(type == "rectangle")
            return new Rectangle(*pis_);
      }
      return 0;
  }

private:
  std::istream  *pis_;
};
#endif
