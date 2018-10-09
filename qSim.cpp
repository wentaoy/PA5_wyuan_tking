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
#include "TellerQueueVec.h"

int main(int argc, char *argv[]) {
	//reading command line
	const int customerNum = atoi(argv[1]);
	const int tellerNum = atoi(argv[2]);
	const float simulateTime = atof(argv[3]);
	const float arvSerTime = atof(argv[4]);
	int seed = time(NULL);
	if (argc == 6) {
		seed = atoi(argv[5]);
	}
	srand(seed);

	//Initialize TellQueueVec and the tellqueue for common line
	TellerQueueVec* commonLineVec = new TellerQueueVec();
	TellerQueue* commonLine = new TellerQueue();
	commonLineVec->addTellerQueue(commonLine);

	//Initialize TellerQueueVec and tellqueues for each teller
	TellerQueueVec* mutiLineVec = new TellerQueueVec();
	for (int i = 0; i < tellerNum; i++){
		TellerQueue* mutiLine = new TellerQueue();
		mutiLineVec->addTellerQueue(mutiLine);
	}

	//Create an empty Event Queue
	EventQueue eqCommon = EventQueue();
	EventQueue eqMuti = EventQueue();

	//create user specified number of customers
	for (int i = 0; i < customerNum; i++) {
		float custArrivalTime = simulateTime * rand() / float(RAND_MAX);
		Customer* cust = new Customer(custArrivalTime);
		//Create customer arrival event and insert into eventqueue
		CustomerArrival* caCommon= new CustomerArrival(custArrivalTime, cust, commonLineVec);
		eqCommon.insert(caCommon);
		CustomerArrival* caMuti = new CustomerArrival(custArrivalTime, cust, mutiLineVec);
		eqMuti.insert(caMuti);
	}

	//create user specified number of tellers
	for (int i = 0; i < tellerNum; i++){
		Teller* t = new Teller(i);
		//create Tellerevent and insert into both eventQueue

	}

	//starts the simulation for common line
	while (!eqCommon.isEmpty()) {
		eqCommon.getHead()->data->action();
		eqCommon.deleteHead();
	}

	//to-do clear all the arrival time for customers


	//run simulation again on muti lines
	return EXIT_SUCCESS;
}


