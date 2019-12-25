/*
 * Squares.cpp
 *
 *  Created on: 25.12.2019
 *      Author: fahri
 */

#include "SquaresState.h"
#include "LineState.h"

SquaresState::SquaresState() {

	byte* frame1 = new byte[8];
	frame1[0] = B00000000;
	frame1[1] = B00000000;
	frame1[2] = B00000000;
	frame1[3] = B00011000;
	frame1[4] = B00011000;
	frame1[5] = B00000000;
	frame1[6] = B00000000;
	frame1[7] = B00000000;

	byte* frame2 = new byte[8];
	frame2[0] = B00000000;
	frame2[1] = B00000000;
	frame2[2] = B00111100;
	frame2[3] = B00100100;
	frame2[4] = B00100100;
	frame2[5] = B00111100;
	frame2[6] = B00000000;
	frame2[7] = B00000000;

	byte* frame3 = new byte[8];
	frame3[0] = B00000000;
	frame3[1] = B01111110;
	frame3[2] = B01000010;
	frame3[3] = B01000010;
	frame3[4] = B01000010;
	frame3[5] = B01000010;
	frame3[6] = B01111110;
	frame3[7] = B00000000;

	byte* frame4 = new byte[8];
	frame4[0] = B11111111;
	frame4[1] = B10000001;
	frame4[2] = B10000001;
	frame4[3] = B10000001;
	frame4[4] = B10000001;
	frame4[5] = B10000001;
	frame4[6] = B10000001;
	frame4[7] = B11111111;

	framesSize = 4;
	frames = new byte*[framesSize];
	frames[0] = frame1;
	frames[1] = frame2;
	frames[2] = frame3;
	frames[3] = frame4;
}

SquaresState::~SquaresState() {
	for (int i = 0; i < framesSize; i++) {
		delete frames[i];
	}

	delete frames;
}

State* SquaresState::next() {
	return new LineState();
}

void SquaresState::drawOnScreen(LedControl *lc) {
	for (int i = 0; i < framesSize; i++) {
		for (int j = 0; j < 8; j++) {
			lc->setRow(0, j, frames[i][j]);
		}
		delay(300);
	}
}
