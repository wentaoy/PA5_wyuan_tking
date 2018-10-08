/*
 * Customer.h
 *
 *  Created on: Oct 6, 2018
 *      Author: wyuan
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

class Customer {
public:
	Customer();
	Customer(float arrTime);
	float getArrivalTime();
	void setArrivalTime(float);

private:
	float arrivalTime;
};

#endif /* CUSTOMER_H_ */
