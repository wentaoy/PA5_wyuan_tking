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
	// TODO Auto-generated destructor stub
}

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

void EventQueue::displayTime() {
	Node* tmp = new Node;
	tmp = head;
	while (tmp != NULL) {
		std::cout << tmp->data->getTime() << std::endl;
		tmp = tmp->link;
	}
}

Node* EventQueue::getHead() {
	return head;
}

void EventQueue::deleteHead() {
	Node *temp = head; // Remember the old head
	head = head->link; // Second in line becomes new head
	delete temp; // Delete old head
}

bool EventQueue::isEmpty(){
	return head == NULL;
}
