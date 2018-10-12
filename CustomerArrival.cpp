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
/** The action for when a customer arrival is next on queue
 * adds a customer to the tellerQueueVec
 * prints the arrival time
 */
void CustomerArrival::action(){
	tellerLines->addCustomer(customer);
}

