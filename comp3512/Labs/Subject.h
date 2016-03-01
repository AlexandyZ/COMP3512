#ifndef SUBJECT_H
#define SUBJECT_H
#include <list>
#include "Observer.h"

class Subject{
public:
	virtual ~Subject(){}
	virtual void subscribe(Observer *obs); 
	virtual void unsubscribe(Observer *obs); 
	virtual void notify(); //ask each subscribed observer to update itself

protected:
	Subject() {} //default constructor

private: 
	std::list<Observer*> observers_; //list of observers
};
//adds to the list
inline void Subject::subscribe(Observer *obs){
	observers_.push_back(obs);
}
//deletes from the list
inline void Subject::unsubscribe(Observer *obs){
	observers_.remove(obs);
}
/*
this function will loop through the list container of Observer classes and
call their abstract update function to each element. */
inline void Subject::notify(){
	for(auto& p : observers_){
		p->update(this);
	}
}

#endif