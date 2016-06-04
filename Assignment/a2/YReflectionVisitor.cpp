#include "YReflectionVisitor.h"

void YReflectionVisitor::visitCircle(Circle *s){
    Point centre = s -> getCentre();
    centre.setX(-centre.getX());
    s -> setCentre(centre);
}

void YReflectionVisitor::visitRectangle(Rectangle *s){
    Point p0 = s -> getVertex(0);
    Point p1 = s -> getVertex(1);
	
    p0.setX(-p0.getX());
    p1.setX(-p1.getX());
	
    s->setVertex(0, p0);
    s->setVertex(1, p1);
}

void YReflectionVisitor::visitTriangle(Triangle *s){
    Point p0 = s -> getVertex(0);
    Point p1 = s -> getVertex(1);
    Point p2 = s -> getVertex(2);
	
    p0.setX(-p0.getX());
    p1.setX(-p1.getX());
    p2.setX(-p2.getX());
	
    s -> setVertex(0, p0);
    s -> setVertex(1, p1);
    s -> setVertex(2, p2);
}
