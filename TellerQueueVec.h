/*
 * TellerQueueVec.h
 *
 *  Created on: Oct 8, 2018
 *      Author: wyuan
 */

#ifndef TELLERQUEUEVEC_H_
#define TELLERQUEUEVEC_H_

#include <vector>;
#include "TellerQueue.h"

class TellerQueueVec {
public:
	TellerQueueVec();
	virtual ~TellerQueueVec();
	void addTellerQueue(TellerQueue* aline);
private:
	std::vector<TellerQueue*> lines;
};

#endif /* TELLERQUEUEVEC_H_ */
