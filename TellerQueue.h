/*
 * TellerQueue.h
 *
 *  Created on: Oct 7, 2018
 *      Author: wyuan
 */

#ifndef TELLERQUEUE_H_
#define TELLERQUEUE_H_

#include "Teller.h"
#include "Customer.h"
struct CustomerNode {
	Customer* data;
	CustomerNode *link;
};

class TellerQueue {
public:
	TellerQueue();
	void add(Customer* t);
	Customer* remove();
	bool isEmpty();
	virtual ~TellerQueue();
	void displayCusTime();
	int customerNum();
	Customer* getFirstCust();
private:
	CustomerNode *head, *tail;
};

#endif /* TELLERQUEUE_H_ */
