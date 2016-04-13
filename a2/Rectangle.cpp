#include "Rectangle.h"
using namespace std;

Rectangle::Rectangle(istream& is) {
    if(!(is >> vertex0_ >> vertex1_))
      throw "Rectangle::Rectangle(istream& is): "
            "cannot read vertexes";
}

void Rectangle::draw() const {
    cout << "[R: " << vertex0_ << ", " << vertex1_ << "]" << endl;
}

void Rectangle::save(ostream& os) const {
    os << "rectangle\n" << vertex0_ << ' ' << vertex1_ << endl;
}

void Rectangle::accept(ShapeVisitor& v) {
    v.visitRectangle(this);
}
