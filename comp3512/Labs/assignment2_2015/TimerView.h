#ifndef TIMERVIEW_H
#define TIMERVIEW_H
#include "Observer.h"
#include "Timer.h"

class TimerView: public Observer{
public:
	TimerView(Timer *timer){
		timer_ = timer;
	}
	virtual void update(Subject *s);//from Observer class
	virtual void display(std::ostream& os) const = 0;

protected:
	Timer *timer_;
};

inline void TimerView::update(Subject *s){
	timer_ = static_cast<Timer*>(s);
	display(std::cout);
}

#endif