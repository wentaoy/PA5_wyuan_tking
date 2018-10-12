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
#include "EventQueuePrior.h"
#include "CustomerComplete.h"
#include <stdlib.h>
class TellerEvent: public Event {
public:
	TellerEvent();
	TellerEvent(float , Teller*, TellerQueueVec*, EventQueuePrior*, float, std::vector<Customer*>*);
	virtual ~TellerEvent();
	void action();
private:
	Teller* teller;
	TellerQueueVec* tellerLines;
	EventQueuePrior* eventQueuePrior;
	float arvSerTime;
	std::vector<Customer*>* completedCus;
};

#endif /* TELLEREVENT_H_ */
