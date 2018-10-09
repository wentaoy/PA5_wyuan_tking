/*
 * TellerEvent.cpp
 *
 *  Created on: Oct 9, 2018
 *      Author: wyuan
 */

#include "TellerEvent.h"

TellerEvent::TellerEvent() :
		Event(), teller(nullptr), tellerLines(nullptr), eventQueue(nullptr), arvSerTime(0){
	// TODO Auto-generated constructor stub
}

//another constructor
TellerEvent::~TellerEvent() {
	// TODO Auto-generated destructor stub
}

void TellerEvent::action() {
	//set the teller'state to INWORK
	teller->setState(INWORK);
	//ask for next consumer
	Customer* nextCus = tellerLines->getNextCustomer(teller);
	//if no consumer set state to REST
	if (nextCus == nullptr) {
		teller->setState(REST);
		// create the teller comeback event
		TellerEvent* tComeback = new TellerEvent(); //need to change constructor
	}
	//if there is next consumer create consumercomplete event with after random service time
	else{
		float randSerTime =  2*arvSerTime*rand()/float(RAND_MAX);
		CustomerComplete* nextService = new CustomerComplete(); // need to change constructor
		eventQueue->insert(nextService);
	}
}

