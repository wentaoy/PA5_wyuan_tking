/*
 * TellerEvent.h
 *
 *  Created on: Oct 9, 2018
 *      Author: wyuan
 */

#ifndef TELLEREVENT_H_
#define TELLEREVENT_H_

#include "Event.h"

class TellerEvent: public Event {
public:
	TellerEvent();
	virtual ~TellerEvent();
	void action();
};

#endif /* TELLEREVENT_H_ */
