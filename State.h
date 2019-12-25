/*
 * State.h
 *
 *  Created on: 25.12.2019
 *      Author: fahri
 */

#ifndef STATE_H_
#define STATE_H_

#include <Arduino.h>
#include <LedControl.h>

class State {
public:
	State();
	virtual ~State();

	virtual void drawOnScreen(LedControl* lc) = 0;
	virtual State* next() = 0;
};

#endif /* STATE_H_ */
