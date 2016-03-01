#ifndef OBSERVER_H
#define OBSERVER_H
#include <iostream>

class Subject;
class Observer{ //abstract base class
public:
	virtual ~Observer(){}
	/* a pure virtual function is implemented 
	in all derived classes. */
	virtual void update(Subject*) = 0;
	
protected:
	Observer(){} //default constructor
};

#endif