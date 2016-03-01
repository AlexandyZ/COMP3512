#ifndef TIMERVIEW_H
#define TIMERVIEW_H
#include "Observer.h"
#include "Timer.h"
/*
derived class from an abstract base class. It contains
one pure virtual function which will be overridden
and implemented by the 3 child classes. */
class TimerView: public Observer{
public:
/*
this is the constructor, it will set the value in the parameter 
as a pointer to the protected variable timer_. */
	TimerView(Timer *timer){
		timer_ = timer;
	}
	virtual void update(Subject *s);//from Observer class
	virtual void display(std::ostream& os) const = 0;

/*
the derived classes including this class can use any of the
functions in the Timer class by calling it with the -> method.
The variable is a pointer because the class contains a delete
constructor to avoid making copies or changing the class.
Everything in its class is passed through its address. */
protected:
	Timer *timer_;
};

/*
an inherited method from the Observer base class and it is
called by the Subject::notify to notify any changes. In this
instance it is calling a virtual function that is overridden
by all the derived classes. */
inline void TimerView::update(Subject *s){
	timer_ = static_cast<Timer*>(s);
	display(std::cout);
}

#endif