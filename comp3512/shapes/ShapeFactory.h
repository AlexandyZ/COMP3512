#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H
#include <iostream>
#include <string>
#include "Shape.h"
#include "Circle.h"
#include "Triangle.h"

class ShapeFactory {
public:
  explicit ShapeFactory(std::istream& is): in_(&is) {}
  
  Shape* create() {
    std::string type;

    if (!(*in_ >> type))
      return nullptr;  // nullptr is in C++11

    if (type == "Circle")
      return new Circle(*in_);  // call Circle ctor to read the data

    if (type == "Triangle")
      return new Triangle(*in_);

    return nullptr;
  }

private:
  std::istream  *in_;
};
#endif
