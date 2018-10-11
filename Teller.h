/*
 * Teller.h
 *
 *  Created on: Oct 7, 2018
 *      Author: wyuan
 */

#ifndef TELLER_H_
#define TELLER_H_

const float IDLEMAX = 600;
const bool INWORK = 1;
const bool REST = 0;

class Teller{
public:
	Teller();
	Teller(int);
	Teller(float, int, bool);
	float getIdleTime();
	bool getState();
	int getid();
	void setid(int aid);
	void setIdleTime(float);
	void setState(bool);
	float getTotIdleTime();
	void addToTotIdleTime(float);

private:
	float idleTime;
	int id;
	bool state; //indicates whether a teller is in rest
	float totIdleTime;
};



#endif /* TELLER_H_ */
