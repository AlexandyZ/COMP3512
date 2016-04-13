#include "Triangle.h"
using namespace std;

Triangle::Triangle(istream& is){
    if(!(is >> vertex0_ >> vertex1_ >> vertex2_))
      throw "Triangle::Triangle(istream& is): "
            "cannot read vertices";
}

void Triangle::draw() const {
    cout << "[T: " << vertex0_ << ", " << vertex1_ << ", " << vertex2_ << "]" << endl;
}

void Triangle::save(ostream& os) const {
    os << "triangle\n" << vertex0_ << ' ' << vertex1_ << ' ' << vertex2_ << endl;
}

void Triangle::accept(ShapeVisitor& v) {
    v.visitTriangle(this);
}
