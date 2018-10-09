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
#include "TellerQueueVec.h"

class CustomerEvent: public Event {
public:
	CustomerEvent();
	CustomerEvent(float, Customer*, TellerQueueVec*);
	virtual ~CustomerEvent();
	virtual void action();
protected:
	Customer* customer;
	TellerQueueVec* tellerLines;
};

#endif /* CUSTOMEREVENT_H_ */
