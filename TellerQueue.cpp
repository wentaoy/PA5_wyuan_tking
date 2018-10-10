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
/**Adds a given customer to the teller queue
 * @param t a customer to be added
 */
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
/** removes the first customer off of the teller queue
 * @return Customer* customer that was removed
 */
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

/**Tells if the tellr queue has any customers in it
 * @return bool true for empty, false for not empty
 */
bool TellerQueue::isEmpty() {
	return (tail == NULL);
}

/**Finds the arrival time of the customer at the front and prints it
 *
 */
void TellerQueue::displayCusTime() {
	CustomerNode* tmp = new CustomerNode;
	tmp = head;
	while (tmp != NULL) {
		std::cout << tmp->data->getArrivalTime() << std::endl;
		tmp = tmp->link;
	}
}
/**Finds the number of customers in this line
 * @return int number in line
 */
int TellerQueue::customerNum() {
	CustomerNode* p = head;
	int count = 0;
	while (p != NULL) {
		++count;
		p = p->link;
	}
	return count;
}
/**Gets the customer who is in the front of the line
 * @return Customer* customer in front
 */
Customer* TellerQueue::getFirstCust(){
	return head->data;
}
