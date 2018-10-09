/*
 * TellerEvent.h
 *
 *  Created on: Oct 9, 2018
 *      Author: wyuan
 */

#ifndef TELLEREVENT_H_
#define TELLEREVENT_H_

#include "Event.h"
#include "Teller.h"

class TellerEvent: public Event {
public:
	TellerEvent();
	virtual ~TellerEvent();
	void action();
private:
	Teller* teller;
};

#endif /* TELLEREVENT_H_ */
