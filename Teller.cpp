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

/**Returns the idle time for this teller
 *
 */
int Teller::getIdleTime() {
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
void Teller::setIdleTime(int aIdleTime){
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
