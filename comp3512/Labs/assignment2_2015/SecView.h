#ifndef SECVIEW_H
#define SECVIEW_H
#include "TimerView.h"

class SecView: public TimerView{
public:
	SecView(Timer *timer):TimerView(timer){}
	virtual void display(std::ostream& os) const;
	SecView(const SecView&) = delete;
	SecView& operator=(const SecView&) = delete;
};
inline void SecView::display(std::ostream& os) const{

	os << timer_->get() << std::endl;
}

#endif