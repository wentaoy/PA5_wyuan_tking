/*
 * Teller.h
 *
 *  Created on: Oct 7, 2018
 *      Author: wyuan
 */

#ifndef TELLER_H_
#define TELLER_H_

class Teller{
public:
	Teller();
	Teller(bool);
	Teller(int);
	Teller(int, bool);
	int getIdleTime();
	bool getState();
	void setIdleTime(int);
	void setState(bool);

private:
	int idleTime;
	bool state; //indicates whether a teller is in rest
};



#endif /* TELLER_H_ */
