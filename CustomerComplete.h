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

class CustomerComplete: public CustomerEvent {
public:
	CustomerComplete();
	CustomerComplete(Teller* ateller);
	virtual ~CustomerComplete();
	virtual void action();
private:
	Teller* teller;
	TellerQueue* completedCus;
	EventQueue* eventQueue;
	float arvSerTime;
};

#endif /* CUSTOMERCOMPLETE_H_ */
