#ifndef KEYBOARDCONTROLLER_H
#define KEYBOARDCONTROLLER_H
#include "Subject.h"

class KeyboardController: public Subject{
public:
	void start(); //start the loop to get user commands
	std::string getCommand() const; //return the command

private:
	std::string cmd_;
};

inline void KeyboardController::start() {
	std::string line;
	while(!getline(std::cin,line).eof()){
		cmd_ = line[0];
		notify();
	}
}
inline std::string KeyboardController::getCommand() const{
	return cmd_;
}

#endif