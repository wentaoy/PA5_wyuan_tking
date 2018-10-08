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
