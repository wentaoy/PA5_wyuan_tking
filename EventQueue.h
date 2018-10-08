/*
 * EventQueue.h
 *
 *  Created on: Oct 7, 2018
 *      Author: wyuan
 */

#ifndef EVENTQUEUE_H_
#define EVENTQUEUE_H_

#include "Event.h"

struct Node
{
    Event *data;
    Node *link;
};

class EventQueue {
public:
	EventQueue();
	void insert(Event*);
	void after(Node*, Event*);
	void front(Event*);
	void back(Event*);
	void displayTime();
	Node* getHead();
	void deleteHead();
	bool isEmpty();
	int eventNum();
	virtual ~EventQueue();
private:
	Node *head,*tail;
};

#endif /* EVENTQUEUE_H_ */
