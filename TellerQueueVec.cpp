/*
 * TellerQueueVec.cpp
 *
 *  Created on: Oct 8, 2018
 *      Author: wyuan
 */

#include "TellerQueueVec.h"

TellerQueueVec::TellerQueueVec() {
	// TODO Auto-generated constructor stub
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
		int numchecked = 1;
		int location = ateller->getid() - 1;
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
