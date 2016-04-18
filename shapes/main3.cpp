// sample program to demonstrate prototype pattern
// compile with: g++ -std=c++11 -W -Wall -pedantic GC.cpp main3.cpp -o main3
#include <vector>
#include "ColouredShape.h"
#include "ColouredCircle.h"
#include "ColouredTriangle.h"
#include "GC.h"
using namespace std;

// not a good version (should read line by line instead)
int get_choice() {
  int  n;

  while (1) {
    cout << "Enter a choice: ";
    if (!(cin >> n))
      break;
    if (n == 0 || n == 1)
      return n;
    cout << "Invalid choice" << endl;
  }
  return -1;
}

void draw(const vector<ColouredShape*>& v, GC& gc) {
  for (auto p: v)
    p->draw(gc);
}

int main() {
  ColouredCircle    c;
  ColouredTriangle  t;
  ColouredShape *shapes[] = {&c, &t};
  vector<ColouredShape*>   v;
  GC                       gc(cout);
  int                      choice;

  while ((choice = get_choice()) != -1) {
    v.push_back(shapes[choice]->clone());
    draw(v, gc);
  }

  for (auto p: v)
    delete p;
}

