#include "Circle.h"
using namespace std;

Circle::Circle(istream& is) {
    is >> centre_ >> radius_;
    if(radius_ <= 0)
        throw "Circle::Circle(istream& is): "
              "negative radius is not allowed";
}

void Circle::draw() const {
    cout <<  "[C: " << centre_ << ", " << radius_ << ']' << endl;
}

void Circle::save(ostream& os) const {
    os << "circle\n" << centre_ << ' ' << radius_ << endl;
}

void Circle::accept(ShapeVisitor& v) {
    v.visitCircle(this);
}