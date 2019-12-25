/*
 * SmileyState.cpp
 *
 *  Created on: 25.12.2019
 *      Author: fahri
 */

#include "SmileyState.h"

SmileyState::SmileyState() {
	smileyTopSize = 4;
	smileyTop = new byte[smileyTopSize];
	smileyTop[0] = B00111100;
	smileyTop[1] = B01000010;
	smileyTop[2] = B10100101;
	smileyTop[3] = B10000001;

	smileyBottomSize = 2;
	smileyBottom = new byte[smileyBottomSize];
	smileyBottom[0] = B01000010;
	smileyBottom[1] = B00111100;

	mouthSize = 2;

	mouthLaugh = new byte[mouthSize];
	mouthLaugh[0] = B10100101;
	mouthLaugh[1] = B10011001;

	mouthNeutral = new byte[mouthSize];
	mouthNeutral[0] = B10000001;
	mouthNeutral[1] = B10111101;

	mouthSad = new byte[mouthSize];
	mouthSad[0] = B10011001;
	mouthSad[1] = B10100101;

	expressionsSize = 3;
	expressions = new byte*[expressionsSize];
	expressions[SMILEY_EXPRESSION::LAUGHING] = mouthLaugh;
	expressions[SMILEY_EXPRESSION::NEUTRAL] = mouthNeutral;
	expressions[SMILEY_EXPRESSION::SAD] = mouthSad;
}

SmileyState::~SmileyState() {
	delete smileyTop;
	delete smileyBottom;
	delete mouthLaugh;
	delete mouthNeutral;
	delete mouthSad;
	delete expressions;
}

void SmileyState::drawOnScreen(LedControl *lc) {
	for (int k = 0; k < expressionsSize; k++) {
		int i;
		for (i = 0; i < smileyTopSize; i++) {
			lc->setRow(0, i, smileyTop[i]);
		}

		for (int j = 0; j < mouthSize; j++, i++) {
			lc->setRow(0, i, expressions[k][j]);
		}

		for (int j = 0; j < smileyBottomSize; j++, i++) {
			lc->setRow(0, i, smileyBottom[j]);
		}

		delay(500);
	}

}

State* SmileyState::next() {
	return this;
}
