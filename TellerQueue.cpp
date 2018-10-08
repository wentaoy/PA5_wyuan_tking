/*
 * TellerQueue.cpp
 *
 *  Created on: Oct 7, 2018
 *      Author: wyuan
 */
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include "TellerQueue.h"

TellerQueue::TellerQueue() :
		head(NULL), tail(NULL) {
}

TellerQueue::~TellerQueue() {
	// TODO Auto-generated destructor stub
}

void TellerQueue::add(Customer* t) {
	CustomerNode *tmp = new CustomerNode;
	tmp->data = t;
	tmp->link = NULL;

	if (head == NULL) {
		head = tmp;
		tail = tmp;
	} else {
		tail->link = tmp;
		tail = tail->link;
	}
}

Customer* TellerQueue::remove() {
	if (isEmpty()) {
		std::cout << "Error: Removing an item from an empty queue.\n";
		exit(1);
	}
	Customer* result = head->data;
	CustomerNode *discard;
	discard = head;
	head = head->link;
	if (head == NULL) //if you removed the last node
		tail = NULL;
	delete discard;
	return result;
}

bool TellerQueue::isEmpty() {
	return (tail == NULL);
}

void TellerQueue::displayCusTime() {
	CustomerNode* tmp = new CustomerNode;
	tmp = head;
	while (tmp != NULL) {
		std::cout << tmp->data->getArrivalTime() << std::endl;
		tmp = tmp->link;
	}
}
