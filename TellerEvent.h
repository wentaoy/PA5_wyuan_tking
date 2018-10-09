/*
 * TellerEvent.h
 *
 *  Created on: Oct 9, 2018
 *      Author: wyuan
 */

#ifndef TELLEREVENT_H_
#define TELLEREVENT_H_

#include "Event.h"
#include "Teller.h"
#include "TellerQueueVec.h"
#include "Customer.h"
#include "EventQueue.h"
#include "CustomerComplete.h"
#include <stdlib.h>
class TellerEvent: public Event {
public:
	TellerEvent();
	virtual ~TellerEvent();
	void action();
private:
	Teller* teller;
	TellerQueueVec* tellerLines;
	EventQueue* eventQueue;
	float arvSerTime;
};

#endif /* TELLEREVENT_H_ */
