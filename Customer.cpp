/*
 * Customer.cpp
 *
 *  Created on: Oct 6, 2018
 *      Author: wyuan
 */
#include "Customer.h"

Customer::Customer(){arrivalTime = 0;}

Customer::Customer(float arrTime): arrivalTime (arrTime){}

float Customer::getArrivalTime(){
	return arrivalTime;
}

void Customer::setArrivalTime(float arrTime){
	arrivalTime = arrTime;
}

