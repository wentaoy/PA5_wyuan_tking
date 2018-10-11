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
#include "TellerEvent.h"
#include <vector>

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

	/**********************Start of testing for add, remove and getnextcos********************

	TellerQueueVec* testVec = new TellerQueueVec();
	TellerQueue* q0 = new TellerQueue();
	TellerQueue* q1 = new TellerQueue();
	TellerQueue* q2 = new TellerQueue();
	Customer* c0 = new Customer(1);
	Customer* c1 = new Customer(2);
	Customer* c2 = new Customer(3);
	Customer* c3 = new Customer(4);
	Customer* c4 = new Customer(5);
	Customer* c5 = new Customer(6);

	Teller* t0 = new Teller(0);
	Teller* t1 = new Teller(1);
	//adding teller queues
	testVec->addTellerQueue(q0);
	testVec->addTellerQueue(q1);
	testVec->addTellerQueue(q2);

	//adding customers to teller q vec (go to shortest line
	testVec->addCustomer(c0);
	testVec->addCustomer(c1);
	testVec->addCustomer(c2);
	testVec->addCustomer(c3);
	testVec->addCustomer(c4);
	testVec->addCustomer(c5);

	int num0 = q0->customerNum();
	int num1 = q1->customerNum();
	int num2 = q2->customerNum();

	std::cout<< "There are " << num0 << " customers in q0" << std::endl;
	std::cout<< "There are " << num1 << " customers in q1" << std::endl;
	std::cout<< "There are " << num2 << " customers in q2" << std::endl;
	std::cout<< "The next customer in first line has: " << q0->getFirstCust()->getArrivalTime() << std::endl;
	std::cout<< "The next customer in second line has: " << q1->getFirstCust()->getArrivalTime() << std::endl;

	Customer* nextCust = testVec->getNextCustomer(t0);
	std::cout<< "The next customer teller 0 is to serve has this arrival time: " << nextCust->getArrivalTime() << std::endl;
	nextCust = testVec->getNextCustomer(t1);
	std::cout<< "The next customer teller 1 is to serve has this arrival time: " << nextCust->getArrivalTime() << std::endl;
	std::cout<<"The arrival time of nextCust is: " << nextCust->getArrivalTime()<< std::endl;
	std::cout<< "Removing first Customer from line 2." << std::endl;
	testVec->removeCustomer(nextCust);
	std::cout<< "There are " << q0->customerNum() << " customers in q0" << std::endl;
	std::cout<< "There are " << q1->customerNum() << " customers in q1" << std::endl;
	std::cout<< "There are " << q2->customerNum() << " customers in q2" << std::endl;

	*************************************************************************************************/

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
	//Create an empty Vector of Tellers
	std::vector<Teller*> tellerVec;

	//TODO add tellers to vector then calculate stats
	//Create an empty Event Queue
	EventQueue* eqCommon = new EventQueue();
	EventQueue* eqMuti = new EventQueue();

	//Create the completed Customer Queue
	std::vector<Customer*>* completedCusCommon = new std::vector<Customer*>();
	std::vector<Customer*>* completedCusMuti = new std::vector<Customer*>();
	//create user specified number of customers
	for (int i = 0; i < customerNum; i++) {
		float custArrivalTime = simulateTime * rand() / float(RAND_MAX);
		Customer* cust = new Customer(custArrivalTime);
		//Create customer arrival event and insert into eventqueue
		CustomerArrival* caCommon= new CustomerArrival(custArrivalTime, cust, commonLineVec);
		eqCommon->insert(caCommon);
		CustomerArrival* caMuti = new CustomerArrival(custArrivalTime, cust, mutiLineVec);
		eqMuti->insert(caMuti);
	}
	//create user specified number of tellers
	for (int i = 0; i < tellerNum; i++){
		//create the new teller
		Teller* t = new Teller(i);
		tellerVec.push_back(t);
		//create the first teller
		TellerEvent* teCommon = new TellerEvent(0, t, commonLineVec, eqCommon, arvSerTime, completedCusCommon);
		//create Tellerevent and insert into both eventQueue
		eqCommon->insert(teCommon);
		TellerEvent* teMuti = new TellerEvent(0, t, mutiLineVec, eqMuti, arvSerTime, completedCusMuti);
		eqMuti->insert(teMuti);
	}

	//starts the simulation for common line
	float worldTime = 0;
	while (!eqCommon->isEmpty() && worldTime < simulateTime && completedCusCommon->size() < customerNum) {
		eqCommon->getHead()->data->action();
		std::cout<< "Ends" << std::endl;
		worldTime = eqCommon->getHead()->data->getTime();
		eqCommon->deleteHead();
	}
	//destructing eqCommon

	eqCommon->~EventQueue();
	std::cout << worldTime <<std::endl;
	//collect statistics
	//number of customers served
	int numCustSerCommon = completedCusCommon->size();
	//Sum of times customers were in bank
	float totTellSerTimeCommon = 0;
	float maxWaitTimeCommon = 0;
	float sumOfSquaresCommon = 0;
	for(int i = 0; i < completedCusCommon->size(); i++){
		//if this wait time is greater than all before set it as max
		if(((*completedCusCommon)[i]->getCalledTime() - (*completedCusCommon)[i]->getArrivalTime()) > maxWaitTimeCommon){
			maxWaitTimeCommon = (*completedCusCommon)[i]->getCalledTime() - (*completedCusCommon)[i]->getArrivalTime();
		}
		//get the first time inside of the Q
		totTellSerTimeCommon = totTellSerTimeCommon + ((*completedCusCommon)[i]->getLeaveTime() -
				(*completedCusCommon)[i]->getArrivalTime());
	}
	float avrTimeInBankCommon = totTellSerTimeCommon / numCustSerCommon;
	float tellIdleTimeCommon = 0;
	for(int i = 0; i < tellerNum; i ++){
		tellIdleTimeCommon = tellIdleTimeCommon + tellerVec[i]->getIdleTime();
	}
	for(int i = 0; i < completedCusCommon->size(); i++){
		sumOfSquaresCommon = sumOfSquaresCommon + pow(((*completedCusCommon)[i]->getLeaveTime() - (*completedCusCommon)[i]->getArrivalTime()) - avrTimeInBankCommon, 2);
	}
	float stdDevCommon = sqrt(sumOfSquaresCommon/ completedCusCommon->size());
	std::cout<<"Type of queuing is: common "<<std::endl;
	std::cout<<"Number of tellers: " << tellerNum << std::endl;
	std::cout<<"The total idle time is: " << tellIdleTimeCommon<<std::endl;
	std::cout<<"The number of customers for common is: "<< numCustSerCommon << std::endl;
	std::cout<<"The total teller service time for common is: "<< totTellSerTimeCommon << std::endl;
	std::cout<<"The max wait time for common is: "<< maxWaitTimeCommon << std::endl;
	std::cout<<"The average time customers spent in bank for common is: "<< avrTimeInBankCommon << std::endl;
	std::cout<<"The time required to serve all customers for common is: "<<worldTime<<std::endl;
	std::cout<<"The standard deviation of time spent in bank for common is: "<< stdDevCommon << std::endl;
	delete completedCusCommon;
	//to-do start mutiline simulation


	worldTime = 0;
	while (!eqMuti->isEmpty() && worldTime < simulateTime && completedCusMuti->size() < customerNum) {
		eqMuti->getHead()->data->action();
		std::cout<< "Ends" << std::endl;
		worldTime = eqMuti->getHead()->data->getTime();
		eqMuti->deleteHead();
	}
	std::cout << worldTime <<std::endl;
	eqMuti->~EventQueue();

	//collect statistics
	int numCustSerMuti = completedCusMuti->size();
	//Sum of times customers were in bank
	float totTellSerTimeMuti = 0;
	float maxWaitTimeMuti = 0;
	float sumOfSquaresMuti = 0;
	for(int i = 0; i < completedCusMuti->size(); i++){
		//if this wait time is greater than all before set it as max
		if(((*completedCusMuti)[i]->getCalledTime() - (*completedCusMuti)[i]->getArrivalTime()) > maxWaitTimeMuti){
			maxWaitTimeMuti = (*completedCusMuti)[i]->getCalledTime() - (*completedCusMuti)[i]->getArrivalTime();
		}
		//get the first time inside of the Q
		totTellSerTimeMuti = totTellSerTimeMuti + ((*completedCusMuti)[i]->getLeaveTime() -
				(*completedCusMuti)[i]->getArrivalTime());
	}
	float tellIdleTimeMuti = 0;
	for(int i = 0; i < tellerNum; i ++){
		tellIdleTimeMuti = tellIdleTimeMuti + tellerVec[i]->getIdleTime();
	}
	float avrTimeInBankMuti = totTellSerTimeMuti / numCustSerMuti;
	for(int i = 0; i < completedCusMuti->size(); i++){
		sumOfSquaresMuti = sumOfSquaresMuti + pow(((*completedCusMuti)[i]->getLeaveTime() - (*completedCusMuti)[i]->getArrivalTime()) - avrTimeInBankMuti, 2);
	}
	float stdDevMuti = sqrt(sumOfSquaresMuti/ completedCusMuti->size());
	std::cout<<"Type of queuing is: multiple "<<std::endl;
	std::cout<<"Number of tellers: " << tellerNum << std::endl;
	std::cout<<"The number of customers for multiple is: "<< numCustSerMuti << std::endl;
	std::cout<<"The total idle time is: " << tellIdleTimeMuti<<std::endl;
	std::cout<<"The total teller service time for multiple is: "<< totTellSerTimeMuti << std::endl;
	std::cout<<"The max wait time for multiple is: "<< maxWaitTimeMuti << std::endl;
	std::cout<<"The average time customers spent in bank for multiple is: "<< avrTimeInBankMuti << std::endl;
	std::cout<<"The time required to serve all customers for multiple is: "<<worldTime<<std::endl;
	std::cout<<"The standard deviation of time spent in bank for multiple is: "<< stdDevMuti << std::endl;

	//run simulation again on muti lines
	return EXIT_SUCCESS;
}


