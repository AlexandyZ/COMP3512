#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H
// headers, ...

class ShapeFactory {
public:
  explicit ShapeFactory(std::istream& is): pis_(&is) {}

  // refer to lecture; see writeup for brief description
  Shape* create();

private:
  std::istream  *pis_;
};
#endif
