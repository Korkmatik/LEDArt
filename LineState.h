/*
 * LineState.h
 *
 *  Created on: 25.12.2019
 *      Author: fahri
 */

#ifndef LINESTATE_H_
#define LINESTATE_H_

#include "SmileyState.h"

class LineState: public State {
public:
	LineState();
	virtual ~LineState();
	virtual State* next() override;
	virtual void drawOnScreen(LedControl *lc) override;

private:
	byte line;
	int delayTime;
};

#endif /* LINESTATE_H_ */
