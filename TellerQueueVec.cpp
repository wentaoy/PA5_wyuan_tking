/*
 * TellerQueueVec.cpp
 *
 *  Created on: Oct 8, 2018
 *      Author: wyuan
 */

#include "TellerQueueVec.h"

TellerQueueVec::TellerQueueVec() {
	// TODO Auto-generated constructor stub
}

TellerQueueVec::~TellerQueueVec() {
	// TODO Auto-generated destructor stub
}

void TellerQueueVec::addTellerQueue(TellerQueue* aline){
	lines.push_back(aline);
}

TellerQueue* TellerQueueVec::getTellerQueue(int id){
	return lines[id];
}

int TellerQueueVec::getQueueNum(){
	return lines.size();
}

//add customer into the vector
Customer* TellerQueueVec::getNextCustomer(Teller* ateller){
	return nullptr;
}
