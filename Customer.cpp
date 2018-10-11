/*
 * Customer.cpp
 *
 *  Created on: Oct 6, 2018
 *      Author: wyuan
 */
#include "Customer.h"

Customer::Customer(){arrivalTime = 0; leaveTime = 0; calledTime = 0;}

Customer::Customer(float arrTime): arrivalTime (arrTime), leaveTime(0), calledTime(0){}
//TODO keep track of Called Time
/**Returns the arrival time of the customer
 * @return float arrival time
 */
float Customer::getArrivalTime(){
	return arrivalTime;
}

/**Changes arrival time to given float value
 * @param arrTime float
 */
void Customer::setArrivalTime(float arrTime){
	arrivalTime = arrTime;
}

/**Returns the leave time of the customer
 * @return float leave time
 */
float Customer::getLeaveTime(){
	return leaveTime;
}

/**Changes leave time to given float value
 * @param time float
 */
void Customer::setLeaveTime(float time){
	leaveTime = time;
}

/**Returns the called time of the customer
 * @return float called time
 */
float Customer::getCalledTime(){
	return calledTime;
}

/**Changes called time to given float value
 * @param called float
 */
void Customer::setCalledTime(float time){
	calledTime = time;
}
