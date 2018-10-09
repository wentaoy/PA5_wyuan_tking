/*
 * TellerEvent.cpp
 *
 *  Created on: Oct 9, 2018
 *      Author: wyuan
 */

#include "TellerEvent.h"

TellerEvent::TellerEvent() : Event(), teller(new Teller()){
	// TODO Auto-generated constructor stub

}

TellerEvent::~TellerEvent() {
	// TODO Auto-generated destructor stub
}

void TellerEvent::action(){
	//set the teller'state to INWORK
	teller->setState(INWORK);
	//ask for next consumer
	//if no consumer set state to REST
	//if there is next consumer create consumercomplete event with after random service time

}

