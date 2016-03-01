#ifndef TIMER_H
#define TIMER_H
#include "Subject.h"
#include "Observer.h"
#include <atomic>
#include <thread>
#include <unistd.h>

/*
derived class of both Subject and Observer. There are four functions in
total it can use and/or inherit. 3 from Subject, 1 from Observer. */
class Timer: public Subject, public Observer{
public:
	Timer(); //ctor (see below)
	void start(); //method to start the timer
	void stop(); //method to stop the timer
	void reset(); //method to reset timer to 0
	unsigned long get() const; //getter method of seconds elapsed
	
	Timer(const Timer&) = delete; //avoids copying of the timer class
	Timer& operator=(const Timer&) = delete; //avoids assigning

	//inherited from abstract base class Observer
	virtual void update(Subject *s);
	
private:
	std::atomic_ulong sec_; //number of seconds elapsed
	std::atomic_bool ticking_; //is timer ticking or not?
	void run(); //function executed by thread
};
/*
this is the Timer constructor with empy parameters. 
When a timer object is created in the main, the thread 
begins asynchonously with the main function. */
Timer::Timer(){
	sec_ = 0;
	ticking_ = false;
	std::thread t(Timer::run,this);
	t.detach();
}
inline void Timer::start(){
	ticking_ = true;
}
inline void Timer::stop(){
	ticking_ = false;
}
inline void Timer::reset(){
	sec_ = 0;
}
inline unsigned long Timer::get() const{
	return sec_;
}
/*
infinitely ticks and with each tick it will call the notify function
of the base class Subject.h to update its list of observers. */
inline void Timer::run(){	
	
	while(1){
		sleep(1);
		if(ticking_ == true){
			sec_++;		
			Subject::notify();
		}
	}
}

#endif