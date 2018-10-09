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
	const int customerNum = atoi(argv[1]);
	const int tellerNum = atoi(argv[2]);
	const float simulateTime = atof(argv[3]);
	const float arvSerTime = atof(argv[4]);
	int seed = time(NULL);
	if (argc == 6) {
		seed = atoi(argv[5]);
	}
	srand(seed);
	//Initialize EventQueue, TellQueueVec
	TellerQueueVec* commonLineVec = new TellerQueueVec();
	TellerQueue* commonLine = new TellerQueue();
	commonLineVec->addTellerQueue(commonLine);
	EventQueue eq = EventQueue();
	//create user specified number of customers
	for (int i = 0; i < customerNum; i++) {
		float custArrivalTime = simulateTime * rand() / float(RAND_MAX);
		Customer* cust = new Customer(custArrivalTime);
		CustomerArrival* ca1= new CustomerArrival(custArrivalTime, cust, commonLineVec);
		eq.insert(ca1);
	}
	//vector for tellers
	std::vector<Teller*> tellerVec = std::vector<Teller*>();
	//Initialize tellers
	for (int i = 0; i < tellerNum; i++){
		Teller* teller = new Teller(i);
		tellerVec.push_back(teller);
		std::cout << "Teller Idle Time: " <<teller->getIdleTime() << std::endl;
	}

	//starts the simulation
	while (!eq.isEmpty()) {
		for (int i = 0; i < tellerNum; i++){
			if(tellerVec[i]->getState()==INWORK){
				if(commonLineVec->getNextCustomer(tellerVec[i]) == nullptr){
					tellerVec[i]->setState(REST);
					tellerVec[i]->getIdleTime();//goes into the event time
					//Create the teller Event to come back to work after idleTime
				}
				else {
					// create the customer complete event after random service time

				}
			}
		}
		eq.getHead()->data->action();
		eq.deleteHead();
	}
	std::cout << "Number of customers in common line is " << commonLine->customerNum() << std::endl;


//	for (int i = 0; i < customerNum; i++) {
//		commonLineVec->removeCustomer();
//	}
	std::cout << "hello" << std::endl;
	std::cout << "Customer in common line is " << commonLine->customerNum() << std::endl;
	return EXIT_SUCCESS;
}

