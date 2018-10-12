/*
 * EventQueuePrior.h
 *
 *  Created on: Oct 11, 2018
 *      Author: wyuan
 */

#ifndef EVENTQUEUEPRIOR_H_
#define EVENTQUEUEPRIOR_H_

#include "Event.h"
#include <queue>
using namespace std;


class CompareEvent {
public:
    bool operator()(Event*& t1, Event*& t2)
    {
       return t1->time > t2->time;
    }
};

class EventQueuePrior {
public:
	EventQueuePrior();
	virtual ~EventQueuePrior();
	void insert(Event* e);
	bool isEmpty();
	Event* getHead();
	void deleteHead();
	int eventNum();

private:
	priority_queue<Event*, vector<Event*>, CompareEvent>* eventPrior;

};

#endif /* EVENTQUEUEPRIOR_H_ */
