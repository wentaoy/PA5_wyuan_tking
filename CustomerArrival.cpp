/*
 * CustomerArrival.cpp
 *
 *  Created on: Oct 7, 2018
 *      Author: wyuan
 */

#include "CustomerArrival.h"
#include <iostream>

CustomerArrival::CustomerArrival() :
		CustomerEvent() {
}

CustomerArrival::CustomerArrival(float time, Customer* aCustomer,
		TellerQueueVec* tellLines) :
		CustomerEvent(time, aCustomer, tellLines) {
}

CustomerArrival::~CustomerArrival() {
	// TODO Auto-generated destructor stub
}

void CustomerArrival::action(){
	tellerLines->addCustomer(customer);
	std::cout << "Customer Arrives at " << customer->getArrivalTime() <<" added to tellerLine." << std::endl;
}

