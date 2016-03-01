#include <iostream>
#include <vector>
#include "GC.h"
#include "Shape.h"
#include "Circle.h"
#include "Triangle.h"
using namespace std;

int main(){
  vector<Shape*>  v;
  v.push_back(new Circle(Point(1,1), 2, GC::Colour::Green));
  v.push_back(new Triangle());
  v.push_back(new Circle(Point(1,2), 5, GC::Colour::Red));

  GC  gc(cout);
  for (auto p: v)
    p->display(gc);
}