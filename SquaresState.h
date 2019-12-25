/*
 * Squares.h
 *
 *  Created on: 25.12.2019
 *      Author: fahri
 */

#ifndef SQUARESSTATE_H_
#define SQUARESSTATE_H_

#include "State.h"

class SquaresState : public State {
public:
	SquaresState();
	virtual ~SquaresState();
	virtual State* next() override;
	virtual void drawOnScreen(LedControl *lc) override;

private:
	int framesSize;
	byte** frames;
};

#endif /* SQUARESSTATE_H_ */
