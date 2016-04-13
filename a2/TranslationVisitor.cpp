#include "TranslationVisitor.h"

void TranslationVisitor::visitCircle(Circle *s){
    Point p = d_ + s->getCentre();
    s->setCentre(p);
}

void TranslationVisitor::visitRectangle(Rectangle *s){
    Point p0 = d_ + s->getVertex(0);
    Point p1 = d_ + s->getVertex(1);
    s->setVertex(0, p0);
    s->setVertex(1, p1);
}

void TranslationVisitor::visitTriangle(Triangle *s){
    Point p0 = d_ +  s->getVertex(0);
    Point p1 = d_ +  s->getVertex(1);
    Point p2 = d_ +  s->getVertex(2);
    s->setVertex(0, p0);
    s->setVertex(1, p1);
    s->setVertex(2, p2);
}