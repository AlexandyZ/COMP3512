#ifndef COLOUREDSHAPEFACTORY_H
#define COLOUREDSHAPEFACTORY_H
#include <iostream>
#include <string>
#include "ColouredCircle.h"
#include "ColouredTriangle.h"

class ColouredShapeFactory {
public:
  explicit ColouredShapeFactory(std::istream& is): isp_(&is) {}
  ColouredShape *create() {
    std::string  type;

    if (*isp_ >> type) {
      if (type == "ColouredCircle")
        return new ColouredCircle(std::cin);
      if (type == "ColouredTriangle")
        return new ColouredTriangle(std::cin);
    }
    return 0;
  }
private:
  std::istream  *isp_;
};
#endif
