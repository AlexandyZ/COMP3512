#ifndef OBSERVER_H
#define OBSERVER_H
#include <iostream>

class Subject;
class Observer{ //abstract base class
public:
	virtual ~Observer(){}
	virtual void update(Subject*) = 0;
	
protected:
	Observer(){} //default constructor
};

#endif