/*
 * CustomerComplete.cpp
 *
 *  Created on: Oct 8, 2018
 *      Author: wyuan
 */

#include "CustomerComplete.h"
#include <iostream>

CustomerComplete::CustomerComplete() :
		CustomerEvent(), teller(nullptr), completedCus(nullptr), eventQueuePrior(
				nullptr), arvSerTime(0) {
}

CustomerComplete::CustomerComplete(float time, Customer* aCustomer,
		TellerQueueVec* aTellLine, Teller* ateller, std::vector<Customer*>* acusComplete,
		EventQueuePrior* aeventQ, float aarvSerT) :
		CustomerEvent(time, aCustomer, aTellLine), teller(ateller), completedCus(
				acusComplete), eventQueuePrior(aeventQ), arvSerTime(aarvSerT) {

}
// need another Constructor
CustomerComplete::~CustomerComplete() {
	// TODO Auto-generated destructor stub
}
/** The action for when a customer complete is next on queue
 * prints the time duration customer was in bank, sets the leave time, adds
 * to teller queue of completed customer, and determines whether to go on break
 * or serve a new customer
 */
void CustomerComplete::action() {
	customer->setLeaveTime(time);
	// store customer into the tellerqueue of completed customers
	completedCus->push_back(customer);
	// teller gets next customer if nullptr then set teller to rest and create new tellerevent after idle time
	Customer* nextCus = tellerLines->getNextCustomer(teller);
	if (nextCus == nullptr) {
		teller->setState(REST);
		teller->addToTotIdleTime(teller->getIdleTime());
		TellerEvent* tComeback = new TellerEvent(time + teller->getIdleTime(),
				teller, tellerLines, eventQueuePrior, arvSerTime, completedCus); //need to be changed with eventtime = time + idletime
		eventQueuePrior->insert(tComeback);
	}
	// if there is next customer then create new customercomplete event after a random service time
	else {
		float randSerTime = 2 * arvSerTime * rand() / float(RAND_MAX);
		CustomerComplete* nextService = new CustomerComplete(time + randSerTime,
				nextCus, tellerLines, teller, completedCus, eventQueuePrior,
				arvSerTime);
		//keeping track of when customer called
		nextCus->setCalledTime(time);
		tellerLines->removeCustomer(nextCus);
		eventQueuePrior->insert(nextService);
	}
}
