/*
 * TellerEvent.cpp
 *
 *  Created on: Oct 9, 2018
 *      Author: wyuan
 */

#include "TellerEvent.h"
#include <iostream>

TellerEvent::TellerEvent() :
		Event(), teller(nullptr), tellerLines(nullptr), eventQueuePrior(nullptr), arvSerTime(0), completedCus(nullptr){
	// TODO Auto-generated constructor stub
}

TellerEvent::TellerEvent(float time, Teller* ateller, TellerQueueVec* atellerQVec, EventQueuePrior* aeventQ, float aarvSerT, std::vector<Customer*>* acustComplete):
		Event(time), teller(ateller), tellerLines(atellerQVec), eventQueuePrior(aeventQ), arvSerTime(aarvSerT), completedCus(acustComplete){

}
//another constructor
TellerEvent::~TellerEvent() {
	// TODO Auto-generated destructor stub
}

/** The action for when a teller event is next on queue
 * changes state for teller, if there isn't a customer, create teller come back
 * event, if there is a customer create customer complete event
 */
void TellerEvent::action() {
	//set the teller'state to INWORK
	teller->setState(INWORK);
	//ask for next consumer
	//if no consumer set state to REST
	if (tellerLines->getNextCustomer(teller) == nullptr) {
		teller->setState(REST);
		teller->addToTotIdleTime(teller->getIdleTime());
		// create the teller comeback event
		TellerEvent* tComeback = new TellerEvent(time + teller->getIdleTime(), teller, tellerLines, eventQueuePrior, arvSerTime, completedCus); //need to change constructor
		// insert the teller event
		eventQueuePrior->insert(tComeback);
	}
	//if there is next consumer create consumercomplete event with after random service time
	else{
		float randSerTime =  2*arvSerTime*rand()/float(RAND_MAX);
		CustomerComplete* nextService = new CustomerComplete(time + randSerTime, tellerLines->getNextCustomer(teller), tellerLines, teller, completedCus, eventQueuePrior, arvSerTime); // need to change constructor
		//keeping track of when customer called
		tellerLines->getNextCustomer(teller)->setCalledTime(time);
		tellerLines->removeCustomer(tellerLines->getNextCustomer(teller));
		eventQueuePrior->insert(nextService);
	}
}

