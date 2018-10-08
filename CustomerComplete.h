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
	CustomerComplete(Teller* ateller);
	virtual ~CustomerComplete();
	virtual void action();
private:
	Teller* teller;
};

#endif /* CUSTOMERCOMPLETE_H_ */
