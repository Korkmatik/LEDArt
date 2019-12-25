#include "SmileyState.h"
#include "SquaresState.h"

#define BUTTON_PIN 9

LedControl* lc;
State* currentState;

void nextState();

void setup() {
	pinMode(BUTTON_PIN, INPUT_PULLUP);

	lc = new LedControl(12,10,11,1);
	currentState = new SquaresState();

	lc->shutdown(0,false);
	lc->setIntensity(0,8);
	lc->clearDisplay(0);
}

void loop() {

	currentState->drawOnScreen(lc);

	if (digitalRead(BUTTON_PIN) == LOW) {
		nextState();
	}
}

void nextState() {
	State* next = currentState->next();
	delete currentState;
	currentState = next;
}
