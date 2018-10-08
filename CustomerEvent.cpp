/*
 * CustomerEvent.cpp
 *
 *  Created on: Oct 7, 2018
 *      Author: wyuan
 */
#include <iostream>
#include "CustomerEvent.h"

CustomerEvent::CustomerEvent() :
		Event(), customer(new Customer(1)), tellerLine(new TellerQueue()) {
}

CustomerEvent::CustomerEvent(float time, Customer* aCustomer, TellerQueue* aTellLine) :
		Event(time), customer(aCustomer), tellerLine(aTellLine) {
}
CustomerEvent::~CustomerEvent() {
	// do not delete the customer object
}
void CustomerEvent::action(){
	std::cout << "error: which CustomerEvent" << std::endl;
}

