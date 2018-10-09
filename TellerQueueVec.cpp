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

void TellerQueueVec::addTellerQueue(TellerQueue* aline){
	lines.push_back(aline);
}

TellerQueue* TellerQueueVec::getTellerQueue(int id){
	return lines[id];
}

int TellerQueueVec::getQueueNum(){
	return lines.size();
}

//add customer into the vector
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

void TellerQueueVec::removeCustomer(Customer* acustomer){
	if(lines.size() == 1){
		lines[0]->remove();
	}else{
		for(int i = 0; i < lines.size(); i++){
			if(lines[i]->getFirstCust()->getArrivalTime() == acustomer->getArrivalTime()){
				lines[i]->remove();
			}else{
			std::cout<<"The customer isn't there."<<std::endl;
			}
		}
	}
}
