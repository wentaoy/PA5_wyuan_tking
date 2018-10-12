/*
 * CustomerComplete.h
 *
 *  Created on: Oct 8, 2018
 *      Author: wyuan
 */

#ifndef CUSTOMERCOMPLETE_H_
#define CUSTOMERCOMPLETE_H_

#include "CustomerEvent.h"
#include "TellerQueue.h"
#include "TellerEvent.h"
#include "EventQueue.h"
#include "EventQueuePrior.h"

class CustomerComplete: public CustomerEvent {
public:
	CustomerComplete();
	CustomerComplete(float time,Customer* aCustomer, TellerQueueVec* aTellLine, Teller* ateller, std::vector<Customer*>* acusComplete, EventQueuePrior* aeventQ, float aarvSerT);
	virtual ~CustomerComplete();
	virtual void action();
private:
	Teller* teller;
	std::vector<Customer*>* completedCus;
	EventQueuePrior* eventQueuePrior;
	float arvSerTime;
};

#endif /* CUSTOMERCOMPLETE_H_ */
