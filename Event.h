/*
 * Event.h
 *
 *  Created on: Oct 7, 2018
 *      Author: wyuan
 */

#ifndef EVENT_H_
#define EVENT_H_

class Event {
public:
	Event();
	Event(float);
	float getTime();
	virtual void action();
	virtual ~Event();
protected:
	float time;
};

#endif /* EVENT_H_ */
