#ifndef TICKVIEW_H
#define TICKVIEW_H
#include "TimerView.h"

class TickView: public TimerView{
public:
	TickView(Timer *timer):TimerView(timer){}
	virtual void display(std::ostream& os) const;
	TickView(const TickView&) = delete;
	TickView& operator=(const TickView&) = delete;
};

inline void TickView::display(std::ostream& os) const{
	
	os << "*" << std::endl;
}

#endif