/*
 * CustomerComplete.cpp
 *
 *  Created on: Oct 8, 2018
 *      Author: wyuan
 */

#include "CustomerComplete.h"
#include <iostream>

CustomerComplete::CustomerComplete(Teller* ateller) :
		CustomerEvent(), teller(ateller) {
}

CustomerComplete::~CustomerComplete() {
	// TODO Auto-generated destructor stub
}

void CustomerComplete::action() {
	std::cout << "customer stays in bank for"
			<< time - customer->getArrivalTime() << std::endl;
	customer->setLeaveTime(time);
	tellerLines->removeCustomer(customer);
}
