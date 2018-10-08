/*
 * Teller.h
 *
 *  Created on: Oct 7, 2018
 *      Author: wyuan
 */

#ifndef TELLER_H_
#define TELLER_H_

const int IDLEMAX = 600;
const bool INWORK = 1;
const bool REST = 0;

class Teller{
public:
	Teller();
	Teller(int);
	Teller(int, int, bool);
	int getIdleTime();
	bool getState();
	int getid();
	void setid(int aid);
	void setIdleTime(int);
	void setState(bool);

private:
	int idleTime;
	int id;
	bool state; //indicates whether a teller is in rest
};



#endif /* TELLER_H_ */
