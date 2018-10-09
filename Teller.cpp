/*
 * Teller.cpp
 *
 *  Created on: Oct 7, 2018
 *      Author: wyuan
 */
#include "Teller.h"
#include <stdlib.h>


Teller::Teller() :
		idleTime(rand() % IDLEMAX), id(0),state(REST) {
}


Teller::Teller(int aid) :
		idleTime(rand() % IDLEMAX), id(aid),state(REST) {
}

Teller::Teller(int aidleTime, int aid, bool astate) :
		idleTime(aidleTime), id(aid), state(astate) {
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

int Teller::getid(){
	return id;
}

void Teller::setid(int aid){
	id = aid;
}
