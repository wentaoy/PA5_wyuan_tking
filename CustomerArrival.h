/*
 * CustomerArrival.h
 *
 *  Created on: Oct 7, 2018
 *      Author: wyuan
 */

#ifndef CUSTOMERARRIVAL_H_
#define CUSTOMERARRIVAL_H_

#include "CustomerEvent.h"
#include "TellerQueueVec.h"

class CustomerArrival: public CustomerEvent {
public:
	CustomerArrival();
	CustomerArrival(float, Customer*, TellerQueueVec*);
	void action();
	virtual ~CustomerArrival();
};

#endif /* CUSTOMERARRIVAL_H_ */
