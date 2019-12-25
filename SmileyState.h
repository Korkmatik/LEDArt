/*
 * SmileyState.h
 *
 *  Created on: 25.12.2019
 *      Author: fahri
 */

#ifndef SMILEYSTATE_H_
#define SMILEYSTATE_H_

#include "State.h"

class SmileyState : public State {
public:


	SmileyState();
	virtual ~SmileyState();

	virtual void drawOnScreen(LedControl *lc) override;
	virtual State* next() override;
private:
	enum SMILEY_EXPRESSION {
		LAUGHING, NEUTRAL, SAD
	};

	int expressionsSize;
	byte** expressions;

	byte* smileyTop;
	int smileyTopSize;

	byte* smileyBottom;
	int smileyBottomSize;

	int mouthSize;
	byte* mouthLaugh;
	byte* mouthNeutral;
	byte* mouthSad;
};

#endif /* SMILEYSTATE_H_ */
