/*
 * Teller.cpp
 *
 *  Created on: Oct 7, 2018
 *      Author: wyuan
 */
#include "Teller.h"
#include <stdlib.h>


Teller::Teller() :
		idleTime(rand() * IDLEMAX / float(RAND_MAX)), id(0),state(REST), totIdleTime(0) {
}


Teller::Teller(int aid) :
		idleTime(rand() * IDLEMAX / float(RAND_MAX)), id(aid),state(REST),totIdleTime(0) {
}

Teller::Teller(float aidleTime, int aid, bool astate) :
		idleTime(aidleTime), id(aid), state(astate), totIdleTime(0){
}

/**Returns the idle time for this teller
 *
 */
float Teller::getIdleTime() {
	return idleTime;
}

/**Returns the state for this teller
 * either rest or inwork
 */
bool Teller::getState() {
	return state;
}

/**Changes the idle time for this teller
 *
 */
void Teller::setIdleTime(float aIdleTime){
	idleTime = aIdleTime;
}
/**Changes the state for this teller
 *
 */
void Teller::setState(bool astate){
	state = astate;
}
/**Returns the id number for this teller
 *
 */
int Teller::getid(){
	return id;
}

/**Changes the id number for this teller
 *
 */
void Teller::setid(int aid){
	id = aid;
}

/**Returns the total idle time for this teller
 *
 */
float Teller::getTotIdleTime(){
	return totIdleTime;
}

/**Changes the total idle time for this teller
 *
 */
void Teller::addToTotIdleTime(float time){
	totIdleTime = totIdleTime + time;;
}
