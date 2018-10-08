/*
 * CustomerEvent.h
 *
 *  Created on: Oct 7, 2018
 *      Author: wyuan
 */

#ifndef CUSTOMEREVENT_H_
#define CUSTOMEREVENT_H_

#include "Event.h"
#include "Customer.h"
#include "TellerQueue.h"

class CustomerEvent: public Event {
public:
	CustomerEvent();
	CustomerEvent(float, Customer*, TellerQueue*);
	virtual ~CustomerEvent();
	virtual void action();
protected:
	Customer* customer;
	TellerQueue* tellerLine;
};

#endif /* CUSTOMEREVENT_H_ */
