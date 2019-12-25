

#include "SmileyState.h"

LedControl* lc= new LedControl(12,10,11,1);

void nextState();

void setup() {
	  lc->shutdown(0,false);
	  lc->setIntensity(0,8);
	  lc->clearDisplay(0);
}

State* currentState = new SmileyState();

void loop() {

	currentState->drawOnScreen(lc);

	nextState();
}

void nextState() {
	State* next = currentState->next();
	delete currentState;
	currentState = next;
}
