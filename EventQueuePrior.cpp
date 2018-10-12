/*
 * EventQueuePrior.cpp
 *
 *  Created on: Oct 11, 2018
 *      Author: wyuan
 */

#include "EventQueuePrior.h"

EventQueuePrior::EventQueuePrior() {
	eventPrior = new priority_queue<Event*, vector<Event*>, CompareEvent>;
}

EventQueuePrior::~EventQueuePrior() {
	// TODO Auto-generated destructor stub
}

void EventQueuePrior::insert(Event* e) {
	eventPrior->push(e);
}

bool EventQueuePrior::isEmpty(){
	return eventPrior->empty();
}

Event* EventQueuePrior::getHead(){
	return eventPrior->top();
}

void EventQueuePrior::deleteHead(){
	eventPrior->pop();
}

int EventQueuePrior::eventNum(){
	return eventPrior->size();
}


