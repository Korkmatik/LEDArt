/*
 * LineState.cpp
 *
 *  Created on: 25.12.2019
 *      Author: fahri
 */

#include "LineState.h"
#include "SmileyState.h"

LineState::LineState() {
	delayTime = 300;
	line = B11111111;
}

LineState::~LineState() {
}

State* LineState::next() {
	return new SmileyState();
}

void LineState::drawOnScreen(LedControl *lc) {

	int i;
	for (i = 0; i < 8; i++) {
		lc->clearDisplay(0);
		lc->setRow(0, i, line);
		delay(delayTime);
	}

	for (i = 7; i >= 0; i--) {
		lc->clearDisplay(0);
		lc->setRow(0, i, line);
		delay(delayTime);
	}
}
