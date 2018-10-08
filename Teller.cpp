/*
 * Teller.cpp
 *
 *  Created on: Oct 7, 2018
 *      Author: wyuan
 */
#include "Teller.h"
#include <stdlib.h>
const int IDLEMAX = 600;
const bool INWORK = 1;
const bool REST = 0;

Teller::Teller() :
		idleTime(rand() % IDLEMAX), state(REST) {
}

Teller::Teller(bool astate) :
		idleTime(rand() % IDLEMAX), state(astate) {
}

Teller::Teller(int aidleTime) :
		idleTime(aidleTime), state(REST) {
}

Teller::Teller(int aidleTime, bool astate) :
		idleTime(aidleTime), state(astate) {
}

int Teller::getIdleTime() {
	return idleTime;
}

bool Teller::getState() {
	return state;
}

void Teller::setIdleTime(int aIdleTime){
	idleTime = aIdleTime;
}

void Teller::setState(bool astate){
	state = astate;
}
