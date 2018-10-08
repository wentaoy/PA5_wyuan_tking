/*
 * CustomerComplete.h
 *
 *  Created on: Oct 8, 2018
 *      Author: wyuan
 */

#ifndef CUSTOMERCOMPLETE_H_
#define CUSTOMERCOMPLETE_H_

#include "CustomerEvent.h"

class CustomerComplete: public CustomerEvent {
public:
	CustomerComplete();
	virtual ~CustomerComplete();
	void action();
};

#endif /* CUSTOMERCOMPLETE_H_ */
