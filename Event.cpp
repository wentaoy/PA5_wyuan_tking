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
/** Returns the time when the event happens
 * @return float time of event
 */
float Event::getTime() {
	return time;
}
/**Prints out error message if attempts to call action on this object
 *
 */
void Event::action() {
	std::cout << "Error: what type of the event has the action" << std::endl;
}

