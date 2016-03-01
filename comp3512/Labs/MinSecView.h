#ifndef MINSECVIEW_H
#define MINSECVIEW_H
#include "TimerView.h"
#include <iomanip>

class MinSecView: public TimerView{
public:
	MinSecView(Timer *timer):TimerView(timer){}
	virtual void display(std::ostream& os) const;
	MinSecView(const MinSecView&) = delete;
	MinSecView& operator=(const MinSecView&) = delete;
};
inline void MinSecView::display(std::ostream& os) const{

	os << std::setw(2) << std::setfill('0') << timer_->get() / 60 << ":";
	os << std::setw(2) << std::setfill('0') << timer_->get() % 60 << std::endl;
}

#endif