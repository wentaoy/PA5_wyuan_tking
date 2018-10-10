/*
 * TellerQueueVec.cpp
 *
 *  Created on: Oct 8, 2018
 *      Author: wyuan
 */

#include "TellerQueueVec.h"
#include <iostream>

TellerQueueVec::TellerQueueVec() {
	lines = std::vector<TellerQueue*>();
}

TellerQueueVec::~TellerQueueVec() {
	// TODO Auto-generated destructor stub
}

/** Adds the given teller queue to the Vector
 * @param aline tellerQ to be added
 */
void TellerQueueVec::addTellerQueue(TellerQueue* aline){
	lines.push_back(aline);
}

/** Returns the teller queue with the given id
 * @return TellerQueue* the desired teller queue
 */
TellerQueue* TellerQueueVec::getTellerQueue(int id){
	return lines[id];
}
/** Finds the number of queues in the vector
 * @return int number of Queues
 */
int TellerQueueVec::getQueueNum(){
	return lines.size();
}

/**Finds the customer that a given teller should serve next
 * @param ateller the Teller that is asking for next Customer
 * @return Customer* returns the next customer that the teller should serve
 */
Customer* TellerQueueVec::getNextCustomer(Teller* ateller){
	//if there's only one line
	if(lines.size() == 1){
		//return the pointer to the cust first in the only line
		return lines[0]->getFirstCust();
	}else{
		//loop through the rest starting with line corresponding to teller
		int unsigned numchecked = 1;
		int unsigned location = ateller->getid();
		while(numchecked < lines.size()){
			if(!lines[location]->isEmpty()){
				return lines[location]->getFirstCust();
			}else{
				numchecked++;
			}
			if(location + 1 < lines.size()){
				location++;
			}else{
				location = 0;
			}
		}
		//if they are all empty return a null pointer
		return nullptr;
	}
}

/**adds a customer to the shortest tellerqueue in the the vector
 * @param acustomer the customer to be added
 */
void TellerQueueVec::addCustomer(Customer* acustomer){
	if(lines.size() == 1){
		lines[0]->add(acustomer);
	}else{
		int shortest = 0;
		for(int i = 0; i  < lines.size(); i++){
			if(lines[i]->customerNum() < lines[shortest]->customerNum()){
				shortest = i;
			}
		}
		lines[shortest]->add(acustomer);
	}
}

/**Removes a given customer from the front of one of the teller queues
 * @param acustomer the customer to be removes
 */
void TellerQueueVec::removeCustomer(Customer* acustomer){
	if(lines.size() == 1){
		lines[0]->remove();
	}else{
		for(int i = 0; i < lines.size(); i++){
			if(lines[i]->getFirstCust()->getArrivalTime() == acustomer->getArrivalTime()){
				lines[i]->remove();
				std::cout<<"Removed the customer."<<std::endl;
			}
		}
	}
}
