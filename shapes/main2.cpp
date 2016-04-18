// sample program to read back & draw saved shapes
// compile with: g++ -std=c++11 -W -Wall -pedantic GC.cpp main2.cpp -o main2
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include "GC.h"
#include "ColouredShape.h"
#include "ColouredShapeFactory.h"
using namespace std;
using namespace std::placeholders;

int main() {
  vector<shared_ptr<ColouredShape>> v;
  ColouredShapeFactory              sf(cin);
  shared_ptr<ColouredShape>         p;
  GC                                gc(cout);

  while ((p = sf.create()) != nullptr)
    v.push_back(p);

  /*for (auto p: v)
    p->draw(gc);*/
    
  //note: arguments to bind are passed by value
  for_each(v.begin(), v.end(),
           bind(mem_fn(&ColouredShape::draw), _1, ref(gc)));
  
  for (auto p: v)
    delete p;
} 
