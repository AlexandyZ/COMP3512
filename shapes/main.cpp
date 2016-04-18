// sample program that create some shapes & save them
// compile with: g++ -std=c++11 -W -Wall -pedantic GC.cpp main.cpp -o main
#include <iostream>
#include <vector>
#include "ColouredCircle.h"
#include "ColouredTriangle.h"
using namespace std;

int main() {
  vector<ColouredShape*>  v;
  v.push_back(new ColouredCircle(Point(1,2), 3, GC::Colour::Red));
  v.push_back(new ColouredTriangle());
  v.push_back(new ColouredCircle(Point(2,6), 5, GC::Colour::Green));

  for (auto p: v)
    p->save(cout);

  for (auto p: v)
    delete p;
}
