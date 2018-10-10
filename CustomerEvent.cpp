/*
 * CustomerEvent.cpp
 *
 *  Created on: Oct 7, 2018
 *      Author: wyuan
 */
#include <iostream>
#include "CustomerEvent.h"
#include "TellerEvent.h"

CustomerEvent::CustomerEvent() :
		Event(), customer(new Customer(1)), tellerLines(new TellerQueueVec()) {
}

CustomerEvent::CustomerEvent(float time, Customer* aCustomer, TellerQueueVec* aTellLine) :
		Event(time), customer(aCustomer), tellerLines(aTellLine) {
}
CustomerEvent::~CustomerEvent() {
	// do not delete the customer object
}

/**Prints out error message if attempts to call action on this object
 *
 */
void CustomerEvent::action(){
	std::cout << "error: which CustomerEvent" << std::endl;
}

