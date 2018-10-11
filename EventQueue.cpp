/*
 * EventQueue.cpp
 *
 *  Created on: Oct 7, 2018
 *      Author: wyuan
 */

#include <iostream>
#include <cstdlib>
#include <cstddef>
#include "EventQueue.h"

EventQueue::EventQueue() :
		head(NULL), tail(NULL) {
}

EventQueue::~EventQueue() {
	while(!this->isEmpty()){
		this->deleteHead();
	}
}

/**inserts an event into the eventQueue in the right place
 * @param e the event to be inserted
 */
void EventQueue::insert(Event* e) {
	Node *tmp = new Node;
	tmp->data = e;
	tmp->link = NULL;
	if (head == NULL) {
		head = tmp;
		tail = tmp;
	} else if (head->data->getTime() > e->getTime()) {
		front(e);
	} else if (tail->data->getTime() < e->getTime()) {
		back(e);
	} else {
		tmp = head;
		while (tmp->link != NULL && tmp->link->data->getTime() < e->getTime()) {
			tmp = tmp->link;
		}
		after(tmp, e);
	}
}

void EventQueue::after(Node *a, Event* e) {
	Node* p = new Node;
	p->data = e;
	p->link = a->link;
	a->link = p;
}

void EventQueue::front(Event* e) {
	Node *tmp = new Node;
	tmp->data = e;
	tmp->link = head;
	head = tmp;
}

void EventQueue::back(Event* e) {
	Node *tmp = new Node;
	tmp->data = e;
	tmp->link = NULL;
	if (head == NULL) {
		head = tmp;
		tail = tmp;
	} else {
		tail->link = tmp;
		tail = tail->link;
	}
}
/** Prints the time
 *
 */
void EventQueue::displayTime() {
	Node* tmp = new Node;
	tmp = head;
	while (tmp != NULL) {
		std::cout << tmp->data->getTime() << std::endl;
		tmp = tmp->link;
	}
}
/** Returns the first in the event queue
 * @returns Node* node in the front of the event queue
 */
Node* EventQueue::getHead() {
	return head;
}

/**Deletes the node first in the event queue
 *
 */
void EventQueue::deleteHead() {
	Node *temp = head; // Remember the old head
	head = head->link; // Second in line becomes new head
	delete temp; // Delete old head
}

/** Tells whether the EventQueue is empty
 * @return bool true for empty false for not empty
 */
bool EventQueue::isEmpty(){
	return head == NULL;
}

/** Tells how many events are in the eventQueue
 * @return int num of nodes
 */
int EventQueue::eventNum(){
	Node* p = head;
	int count = 0;
	while (p != NULL)
	{
	  ++count;
	  p = p->link;
	}
	return count;
}
