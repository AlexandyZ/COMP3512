#include "XReflectionVisitor.h"

void XReflectionVisitor::visitCircle(Circle *s) {
    Point centre =  s -> getCentre();
    centre.setY(-centre.getY());
    s -> setCentre(centre);
}

void XReflectionVisitor::visitRectangle(Rectangle *s) {
    Point p0 =  s -> getVertex(0);
    Point p1 =  s -> getVertex(1);
	
    p0.setY(-p0.getY());
    p1.setY(-p1.getY());
	
    s -> setVertex(0, p0);
    s -> setVertex(1, p1);
}

void XReflectionVisitor::visitTriangle(Triangle *s) {
    Point p0 = s -> getVertex(0);
    Point p1 = s -> getVertex(1);
    Point p2 = s -> getVertex(2);
	
    p0.setY(-p0.getY());
    p1.setY(-p1.getY());
    p2.setY(-p2.getY());
	
    s -> setVertex(0, p0);
    s -> setVertex(1, p1);
    s -> setVertex(2, p2);
}
