#include "TickView.h"
#include "SecView.h"
#include "MinSecView.h"
#include "Timer.h"
#include "KeyboardController.h"
using namespace std;

/*
this is an inherited method of the derived class Timer from its 
base class Observer. It overrides the virtual method of the base class.*/
void Timer::update(Subject *s){
KeyboardController* kc = static_cast<KeyboardController*>(s);

	if(kc->getCommand() == "s"){
		this->start();
	}
	if(kc->getCommand() == "h"){
		this->stop();
	}
	if(kc->getCommand() == "r"){
		this->reset();
	}
}
int main(){

	Timer timer;
	KeyboardController kc;
	MinSecView mins(&timer);
	SecView sec(&timer);
	TickView tick(&timer);

	kc.subscribe(&timer);
	timer.subscribe(&tick);
	timer.subscribe(&sec);
	timer.subscribe(&mins);

	kc.start();

	timer.unsubscribe(&mins);
	timer.unsubscribe(&sec);
	timer.unsubscribe(&tick);
	kc.unsubscribe(&timer);
}