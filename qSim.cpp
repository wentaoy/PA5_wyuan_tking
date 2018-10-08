/*
 * qSim.cpp
 *
 *  Created on: Oct 5, 2018
 *      Author: wyuan
 */
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <time.h>
#include "Customer.h"
#include "Event.h"
#include "EventQueue.h"
#include "Teller.h"
#include "TellerQueue.h"
#include "CustomerEvent.h"
#include "CustomerArrival.h"

int main(int argc, char *argv[]) {
	const int customerNum = atoi(argv[1]);
	const int tellerNum = atoi(argv[2]);
	const float simulateTime = atof(argv[3]);
	const float arvSerTime = atof(argv[4]);
	int seed = time(NULL);
	if (argc == 6) {
		seed = atoi(argv[5]);
	}
	srand(seed);
	//Initialize EventQueue, TellQueue
	TellerQueue* commonLine = new TellerQueue();
	EventQueue eq = EventQueue();
	//create user specified number of customers
	for (int i = 0; i < customerNum; i++) {
		float custArrivalTime = simulateTime * rand() / float(RAND_MAX);
		Customer* cust = new Customer(custArrivalTime);
		CustomerArrival* ca1= new CustomerArrival(custArrivalTime, cust, commonLine);
		eq.insert(ca1);
	}
	while (!eq.isEmpty()) {
		eq.getHead()->data->action();
		eq.deleteHead();
	}
	commonLine->displayCusTime();
//	for (int i = 0; i < customerNum; i++) {
//		tellerLine.remove();
//		std::cout << tellerLine.isEmpty() << std::endl;
//	}

//Teller teller1();
	return EXIT_SUCCESS;
}

