#include <iostream>
#include <vector>
#include "Shape.h"
#include "Circle.h"
#include "Triangle.h"
#include "ShapeFactory.h"
using namespace std;

int main(){
  vector<Shape*>  v;
  ShapeFactory    f(cin);
  Shape          *p;

  while ( (p = f.create()) != nullptr )
    v.push_back(p);

  for (auto x: v)
    x->display(gc);

  for (auto x: v)
    delete x;
}