/*
 * Event.cpp
 *
 *  Created on: Oct 7, 2018
 *      Author: wyuan
 */

#include "Event.h"
#include <iostream>

Event::Event() :
		time(0) {
}
Event::Event(float atime) :
		time(atime) {
}
Event::~Event() {
	// TODO Auto-generated destructor stub
}

float Event::getTime(){
	return time;
}

void Event::action(){
	std::cout << "Error: what type of the event has the action" << std::endl;
}

