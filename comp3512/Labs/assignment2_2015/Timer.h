#ifndef TIMER_H
#define TIMER_H
#include "Subject.h"
#include "Observer.h"
#include <atomic>
#include <thread>
#include <unistd.h>

class Timer: public Subject, public Observer{
public:
	Timer(); //ctor (see below)
	void start(); //method to start the timer
	void stop(); //method to stop the timer
	void reset(); //method to reset timer to 0
	unsigned long get() const; //getter method of seconds elapsed
	
	Timer(const Timer&) = delete; //avoids copying of the timer class
	Timer& operator=(const Timer&) = delete; //avoids assigning

	virtual void update(Subject *s);
	
private:
	std::atomic_ulong sec_; //number of seconds elapsed
	std::atomic_bool ticking_; //is timer ticking or not?
	void run(); //function executed by thread
};
Timer::Timer(){	
	sec_ = 0;
	ticking_ = false;
	std::thread t(&Timer::run,this);
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
inline void Timer::run(){	
	
	while(1){
		sleep(1);
		if(ticking_ == true){
			sec_++;		
			notify();
		}
	}
}

#endif