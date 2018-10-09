/*
 * CustomerComplete.cpp
 *
 *  Created on: Oct 8, 2018
 *      Author: wyuan
 */

#include "CustomerComplete.h"
#include <iostream>

CustomerComplete::CustomerComplete() :
		CustomerEvent(), teller(nullptr), completedCus(nullptr), eventQueue(nullptr), arvSerTime(0){
}

// need another Constructor

CustomerComplete::~CustomerComplete() {
	// TODO Auto-generated destructor stub
}

void CustomerComplete::action() {
	std::cout << "customer stays in bank for"
			<< time - customer->getArrivalTime() << std::endl;
	customer->setLeaveTime(time);
	tellerLines->removeCustomer(customer);
	// store customer into the tellerqueue of completed customers
	completedCus->add(customer);
	// teller gets next customer if nullptr then set teller to rest and create new tellerevent after idle time
	Customer* nextCus = tellerLines->getNextCustomer(teller);
	if (nextCus == nullptr) {
		teller->setState(REST);
		TellerEvent* tComeback = new TellerEvent(); //need to be changed with eventtime = time + idletime
	}
	// if there is next customer then create new customercomplete event after a random service time
	else {
		float randSerTime = 2 * arvSerTime * rand() / float(RAND_MAX);
		CustomerComplete* nextService = new CustomerComplete(); // need to change constructor
		eventQueue->insert(nextService);
	}
}
